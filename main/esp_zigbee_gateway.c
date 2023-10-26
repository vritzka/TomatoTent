/*
 * SPDX-FileCopyrightText: 2021-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 *
 * Zigbee Gateway Example
 *
 * This example code is in the Public Domain (or CC0 licensed, at your option.)
 *
 * Unless required by applicable law or agreed to in writing, this
 * software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
 * CONDITIONS OF ANY KIND, either express or implied.
 */

#include "esp_zigbee_gateway.h"

static esp_err_t err;
static nvs_handle_t storage_handle;

#if (!defined ZB_MACSPLIT_HOST && defined ZB_MACSPLIT_DEVICE)
#error Only Zigbee gateway host device should be defined
#endif

static const char *TAG = "ESP_ZB_GATEWAY";


#if(CONFIG_ZIGBEE_GW_AUTO_UPDATE_RCP)
static void esp_zb_gateway_update_rcp(void)
{
    /* Deinit uart to transfer UART to the serial loader */
    esp_zb_macsplit_uart_deinit();
    if (esp_rcp_update() != ESP_OK) {
        esp_rcp_mark_image_verified(false);
    }
    esp_restart();
}

static void esp_zb_gateway_board_try_update(const char *rcp_version_str)
{
    char version_str[RCP_VERSION_MAX_SIZE];
    if (esp_rcp_load_version_in_storage(version_str, sizeof(version_str)) == ESP_OK) {
        ESP_LOGI(TAG, "Storage RCP Version: %s", version_str);
        if (strcmp(version_str, rcp_version_str)) {
            ESP_LOGI(TAG, "*** NOT MATCH VERSION! ***");
            esp_zb_gateway_update_rcp();
        } else {
            ESP_LOGI(TAG, "*** MATCH VERSION! ***");
            esp_rcp_mark_image_verified(true);
        }
    } else {
        ESP_LOGI(TAG, "RCP firmware not found in storage, will reboot to try next image");
        esp_rcp_mark_image_verified(false);
        esp_restart();
    }
}

esp_err_t init_spiffs(void)
{
    esp_vfs_spiffs_conf_t rcp_fw_conf = {
        .base_path = "/rcp_fw", .partition_label = "rcp_fw", .max_files = 10, .format_if_mount_failed = false
    };
    esp_vfs_spiffs_register(&rcp_fw_conf);
    return ESP_OK;
}
#endif

static void bdb_start_top_level_commissioning_cb(uint8_t mode_mask)
{
    ESP_ERROR_CHECK(esp_zb_bdb_start_top_level_commissioning(mode_mask));
}

void rcp_error_handler(uint8_t connect_timeout)
{
    ESP_LOGI(TAG, "RCP connection failed timeout:%d seconds", connect_timeout);
#if(CONFIG_ZIGBEE_GW_AUTO_UPDATE_RCP)
    ESP_LOGI(TAG, "Timeout! Re-flashing RCP");
    esp_zb_gateway_update_rcp();
#endif
}


static esp_err_t zb_attribute_handler(const esp_zb_zcl_set_attr_value_message_t *message)
{
    esp_err_t ret = ESP_OK;
    bool light_state = 0;
    ESP_RETURN_ON_FALSE(message, ESP_FAIL, TAG, "Empty message");
    ESP_RETURN_ON_FALSE(message->info.status == ESP_ZB_ZCL_STATUS_SUCCESS, ESP_ERR_INVALID_ARG, TAG, "Received message: error status(%d)",
                        message->info.status);
    ESP_LOGI(TAG, "Received message: endpoint(%d), cluster(0x%x), attribute(0x%x), data size(%d)", message->info.dst_endpoint, message->info.cluster,
             message->attribute.id, message->attribute.data.size);
    if (message->info.dst_endpoint == HA_ESP_LIGHT_ENDPOINT) {
        if (message->info.cluster == ESP_ZB_ZCL_CLUSTER_ID_ON_OFF) {
            if (message->attribute.id == ESP_ZB_ZCL_ATTR_ON_OFF_ON_OFF_ID && message->attribute.data.type == ESP_ZB_ZCL_ATTR_TYPE_BOOL) {
                light_state = message->attribute.data.value ? *(bool *)message->attribute.data.value : light_state;
                ESP_LOGI(TAG, "Light sets to %s", light_state ? "On" : "Off");
                //light_driver_set_power(light_state);
            }
        }
    }
    return ret;
}


static esp_err_t zb_attribute_reporting_handler(const esp_zb_zcl_report_attr_message_t *message)
{
    ESP_RETURN_ON_FALSE(message, ESP_FAIL, TAG, "Empty message");
    ESP_RETURN_ON_FALSE(message->status == ESP_ZB_ZCL_STATUS_SUCCESS, ESP_ERR_INVALID_ARG, TAG, "Received message: error status(%d)",
                        message->status);
    ESP_LOGI(TAG, "Received report from address(0x%x) src endpoint(%d) to dst endpoint(%d) cluster(0x%x)", message->src_address.u.short_addr,
             message->src_endpoint, message->dst_endpoint, message->cluster);
    ESP_LOGI(TAG, "Received report information: attribute(0x%x), type(0x%x), value(%d)\n", message->attribute.id, message->attribute.data.type,
             message->attribute.data.value ? *(uint8_t *)message->attribute.data.value : 0);
    return ESP_OK;
}

static esp_err_t zb_read_attr_resp_handler(const esp_zb_zcl_cmd_read_attr_resp_message_t *message)
{
    ESP_RETURN_ON_FALSE(message, ESP_FAIL, TAG, "Empty message");
    ESP_RETURN_ON_FALSE(message->info.status == ESP_ZB_ZCL_STATUS_SUCCESS, ESP_ERR_INVALID_ARG, TAG, "Received message: error status(%d)",
                        message->info.status);
    ESP_LOGI(TAG, "Read attribute response: status(%d), cluster(0x%x), attribute(0x%x), type(0x%x), value(%d)", message->info.status,
            message->info.cluster, message->attribute.id, message->attribute.data.type,
            message->attribute.data.value ? *(uint8_t *)message->attribute.data.value : 0);
             
			if(message->attribute.id == 0)
				//my_tent.temperature_c = -10 + ((60/255) * (int)message->attribute.data.value);
				my_tent.temperature_c = (int)message->attribute.data.value;
				
				
			update_displayed_values();	    
    return ESP_OK;
}

static esp_err_t zb_configure_report_resp_handler(const esp_zb_zcl_cmd_config_report_resp_message_t *message)
{
    ESP_RETURN_ON_FALSE(message, ESP_FAIL, TAG, "Empty message");
    ESP_RETURN_ON_FALSE(message->info.status == ESP_ZB_ZCL_STATUS_SUCCESS, ESP_ERR_INVALID_ARG, TAG, "Received message: error status(%d)",
                        message->info.status);
    ESP_LOGI(TAG, "Configure report response: status(%d), cluster(0x%x), attribute(0x%x)", message->info.status, message->info.cluster,
             message->attribute_id);
    return ESP_OK;
}


static esp_err_t zb_action_handler(esp_zb_core_action_callback_id_t callback_id, const void *message)
{
    esp_err_t ret = ESP_OK;
    switch (callback_id) {
    case ESP_ZB_CORE_SET_ATTR_VALUE_CB_ID:
        ret = zb_attribute_handler((esp_zb_zcl_set_attr_value_message_t *)message);
        break;
   case ESP_ZB_CORE_REPORT_ATTR_CB_ID:
        ret = zb_attribute_reporting_handler((esp_zb_zcl_report_attr_message_t *)message);
        break;
    case ESP_ZB_CORE_CMD_READ_ATTR_RESP_CB_ID:
        ret = zb_read_attr_resp_handler((esp_zb_zcl_cmd_read_attr_resp_message_t *)message);
        break;
    case ESP_ZB_CORE_CMD_REPORT_CONFIG_RESP_CB_ID:
        ret = zb_configure_report_resp_handler((esp_zb_zcl_cmd_config_report_resp_message_t *)message);
        break;      
    default:
        ESP_LOGW(TAG, "Receive Zigbee action(0x%x) callback", callback_id);
        break;
    }
    return ret;
}



/////////////////////////////////////
/////////// SWITCH //////////////////
/////////////////////////////////////

typedef struct light_bulb_device_params_s {
    esp_zb_ieee_addr_t ieee_addr;
    uint8_t  endpoint;
    uint16_t short_addr;
} light_bulb_device_params_t;

static void bind_cb(esp_zb_zdp_status_t zdo_status, void *user_ctx)
{
    if (zdo_status == ESP_ZB_ZDP_STATUS_SUCCESS) {
        ESP_LOGI(TAG, "Bound successfully!");
        if (user_ctx) {
            light_bulb_device_params_t *light = (light_bulb_device_params_t *)user_ctx;
            ESP_LOGI(TAG, "The light originating from address(0x%x) on endpoint(%d)", light->short_addr, light->endpoint);
            
            my_tent.power_outlet_short_addr = light->short_addr;
            
            draw_socket_pair_panel(&my_tent.power_outlet_short_addr,1);
            
            err = nvs_open("storage", NVS_READWRITE, &storage_handle);
            err = nvs_set_u16(storage_handle, "power_outlet", my_tent.power_outlet_short_addr);
            printf((err != ESP_OK) ? "Failed!\n" : "Done\n");
            nvs_close(storage_handle);
            free(light);
        }
    }
}

static void user_find_cb(esp_zb_zdp_status_t zdo_status, uint16_t addr, uint8_t endpoint, void *user_ctx)
{
    if (zdo_status == ESP_ZB_ZDP_STATUS_SUCCESS) {
        ESP_LOGI(TAG, "Found light");
        esp_zb_zdo_bind_req_param_t bind_req;
        light_bulb_device_params_t *light = (light_bulb_device_params_t *)malloc(sizeof(light_bulb_device_params_t));
        light->endpoint = endpoint;
        light->short_addr = addr;
        esp_zb_ieee_address_by_short(light->short_addr, light->ieee_addr);
		bind_req.src_endp = HA_ONOFF_SWITCH_ENDPOINT;
        bind_req.cluster_id = ESP_ZB_ZCL_CLUSTER_ID_ON_OFF;
        bind_req.dst_addr_mode = ESP_ZB_ZDO_BIND_DST_ADDR_MODE_64_BIT_EXTENDED;
        memcpy(bind_req.dst_address_u.addr_long, light->ieee_addr, sizeof(esp_zb_ieee_addr_t));
        bind_req.dst_endp = endpoint;
        bind_req.req_dst_addr = esp_zb_get_short_address(); /* TODO: Send bind request to self */
        ESP_LOGI(TAG, "Try to bind On/Off");
        esp_zb_zdo_device_bind_req(&bind_req, bind_cb, (void *)light);
    }
}

static void user_leave_cb(esp_zb_zdp_status_t zdo_status, void *user_ctx)
{
	if (zdo_status == ESP_ZB_ZDP_STATUS_SUCCESS) {	
		//ESP_LOGI(TAG, "Leave CB");
		if (pdTRUE == xSemaphoreTake(xGuiSemaphore, portMAX_DELAY)) {
			lv_obj_add_flag(ui_PowerOutletDevicePanel, LV_OBJ_FLAG_HIDDEN);
			xSemaphoreGive(xGuiSemaphore);
		}
		err = nvs_open("storage", NVS_READWRITE, &storage_handle);
		err = nvs_erase_key(storage_handle, "power_outlet");
		printf((err != ESP_OK) ? "Not deleted!\n" : "Deleted\n");
		nvs_close(storage_handle);
	}
}

void pair_socket(lv_event_t * e)
{
	uint16_t * device_short_address = lv_event_get_user_data(e); 
	ESP_LOGI(TAG, "'Pairing' 0x%04hx", *device_short_address);
	
	esp_zb_zdo_match_desc_req_param_t cmd_req;
	cmd_req.dst_nwk_addr = *device_short_address;
	cmd_req.addr_of_interest = *device_short_address;
	
	esp_zb_zdo_find_on_off_light(&cmd_req, user_find_cb, NULL);	
}

void leave_device(lv_event_t * e)
{
	uint16_t * device_short_address = lv_event_get_user_data(e);
	ESP_LOGI(TAG,"LEAVE ADDRESS:0x%04hx",*device_short_address);  
	esp_zb_zdo_mgmt_leave_req_param_t cmd_req;
	esp_zb_ieee_address_by_short(*device_short_address, cmd_req.device_address);
	cmd_req.dst_nwk_addr = *device_short_address;
	cmd_req.rejoin = 0;
	esp_zb_zdo_device_leave_req(&cmd_req, user_leave_cb, NULL);
}

/////////////////////////////////////
/////////// END SWITCH //////////////////
/////////////////////////////////////


/////////////////////////////////////
/////////// THERMOMETER //////////////////
/////////////////////////////////////

typedef struct thermometer_device_params_s {
    esp_zb_ieee_addr_t ieee_addr;
    uint8_t  endpoint;
    uint16_t short_addr;
} thermometer_device_params_t;

static void thermometer_bind_cb(esp_zb_zdp_status_t zdo_status, void *user_ctx)
{
    if (zdo_status == ESP_ZB_ZDP_STATUS_SUCCESS) {
        ESP_LOGI(TAG, "Thermometer Bound successfully!");
        if (user_ctx) {
            thermometer_device_params_t *thermometer = (thermometer_device_params_t *)user_ctx;
            ESP_LOGI(TAG, "The thermometer originating from address(0x%x) on endpoint(%d)", thermometer->short_addr, thermometer->endpoint);
            
            my_tent.thermometer_short_addr = thermometer->short_addr;
            
            //draw_socket_pair_panel(&my_tent.power_outlet_short_addr,1);
            
            err = nvs_open("storage", NVS_READWRITE, &storage_handle);
            err = nvs_set_u16(storage_handle, "thermo_outlet", my_tent.thermometer_short_addr);
            printf((err != ESP_OK) ? "Failed!\n" : "Done\n");
            nvs_close(storage_handle);
            free(thermometer);
        }
    }
}

static void thermometer_find_cb(esp_zb_zdp_status_t zdo_status, uint16_t addr, uint8_t endpoint, void *user_ctx)
{
    if (zdo_status == ESP_ZB_ZDP_STATUS_SUCCESS) {
        ESP_LOGI(TAG, "Found thermometer");
        esp_zb_zdo_bind_req_param_t bind_req;
        thermometer_device_params_t *thermometer = (thermometer_device_params_t *)malloc(sizeof(thermometer_device_params_t));
        thermometer->endpoint = endpoint;
        thermometer->short_addr = addr;
        esp_zb_ieee_address_by_short(thermometer->short_addr, thermometer->ieee_addr);
        esp_zb_get_long_address(bind_req.src_address);
        bind_req.src_endp = THERMOMETER_ENDPOINT;
        bind_req.cluster_id = ESP_ZB_ZCL_CLUSTER_ID_TEMP_MEASUREMENT;
        bind_req.dst_addr_mode = ESP_ZB_ZDO_BIND_DST_ADDR_MODE_64_BIT_EXTENDED;
        memcpy(bind_req.dst_address_u.addr_long, thermometer->ieee_addr, sizeof(esp_zb_ieee_addr_t));
        bind_req.dst_endp = endpoint;
        bind_req.req_dst_addr = esp_zb_get_short_address(); /* TODO: Send bind request to self */
        ESP_LOGI(TAG, "Try to bind Thermometer");
        esp_zb_zdo_device_bind_req(&bind_req, thermometer_bind_cb, (void *)thermometer);
    }
}

static void thermometer_leave_cb(esp_zb_zdp_status_t zdo_status, void *user_ctx)
{
	if (zdo_status == ESP_ZB_ZDP_STATUS_SUCCESS) {	
		//ESP_LOGI(TAG, "Leave CB");
		if (pdTRUE == xSemaphoreTake(xGuiSemaphore, portMAX_DELAY)) {
			//lv_obj_add_flag(ui_PowerOutletDevicePanel, LV_OBJ_FLAG_HIDDEN);
			//xSemaphoreGive(xGuiSemaphore);
		}
		err = nvs_open("storage", NVS_READWRITE, &storage_handle);
		err = nvs_erase_key(storage_handle, "thermometer_outlet");
		printf((err != ESP_OK) ? "Not deleted!\n" : "Deleted\n");
		nvs_close(storage_handle);
	}
}


/////////////////////////////////////
/////////// END THERMOMETER //////////////////
/////////////////////////////////////


uint16_t power_outlet_short_addr;
uint16_t thermometer_short_addr;

void esp_zb_app_signal_handler(esp_zb_app_signal_t *signal_struct)
{
    uint32_t *p_sg_p       = signal_struct->p_app_signal;
    esp_err_t err_status = signal_struct->esp_err_status;
    esp_zb_app_signal_type_t sig_type = *p_sg_p;
    esp_zb_zdo_signal_device_annce_params_t *dev_annce_params = NULL;
    esp_zb_zdo_signal_macsplit_dev_boot_params_t *rcp_version = NULL;

    switch (sig_type) {
    case ESP_ZB_ZDO_SIGNAL_SKIP_STARTUP:
        ESP_LOGI(TAG, "Zigbee stack initialized");
        esp_zb_bdb_start_top_level_commissioning(ESP_ZB_BDB_MODE_INITIALIZATION);
        break;
    case ESP_ZB_MACSPLIT_DEVICE_BOOT:
        ESP_LOGI(TAG, "Zigbee rcp device booted");
        rcp_version = (esp_zb_zdo_signal_macsplit_dev_boot_params_t *)esp_zb_app_signal_get_params(p_sg_p);
        ESP_LOGI(TAG, "Running RCP Version: %s", rcp_version->version_str);
#if(CONFIG_ZIGBEE_GW_AUTO_UPDATE_RCP)
        esp_zb_gateway_board_try_update(rcp_version->version_str);
#endif
        break;
    case ESP_ZB_BDB_SIGNAL_DEVICE_FIRST_START:
    case ESP_ZB_BDB_SIGNAL_DEVICE_REBOOT:
        if (err_status == ESP_OK) {
            ESP_LOGI(TAG, "Start network formation");
            esp_zb_bdb_start_top_level_commissioning(ESP_ZB_BDB_MODE_NETWORK_FORMATION);
        } else {
            ESP_LOGE(TAG, "Failed to initialize Zigbee stack (status: %s)", esp_err_to_name(err_status));
        }
        break;
    case ESP_ZB_BDB_SIGNAL_FORMATION:
        if (err_status == ESP_OK) {
            esp_zb_ieee_addr_t ieee_address;
            esp_zb_get_long_address(ieee_address);
            ESP_LOGI(TAG, "Formed network successfully (ieee_address: %02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x, PAN ID: 0x%04hx, Channel:%d)",
                     ieee_address[7], ieee_address[6], ieee_address[5], ieee_address[4],
                     ieee_address[3], ieee_address[2], ieee_address[1], ieee_address[0],
                     esp_zb_get_pan_id(), esp_zb_get_current_channel());
            esp_zb_bdb_start_top_level_commissioning(ESP_ZB_BDB_MODE_NETWORK_STEERING);
        } else {
            ESP_LOGI(TAG, "Restart network formation (status: %s)", esp_err_to_name(err_status));
            esp_zb_scheduler_alarm((esp_zb_callback_t)bdb_start_top_level_commissioning_cb, ESP_ZB_BDB_MODE_NETWORK_FORMATION, 1000);
        }
        break;
    case ESP_ZB_BDB_SIGNAL_STEERING:
        if (err_status == ESP_OK) {
            ESP_LOGI(TAG, "Network steering started");
        }
        break;
    case ESP_ZB_ZDO_SIGNAL_DEVICE_ANNCE:
        dev_annce_params = (esp_zb_zdo_signal_device_annce_params_t *)esp_zb_app_signal_get_params(p_sg_p);
        ESP_LOGI(TAG, "New device found (short: 0x%04hx), Capabilities: %d", dev_annce_params->device_short_addr, dev_annce_params->capability);

        ESP_LOGI(TAG, "IEEE address: %02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x",
                 dev_annce_params->ieee_addr[7], dev_annce_params->ieee_addr[6], dev_annce_params->ieee_addr[5], dev_annce_params->ieee_addr[4],
                 dev_annce_params->ieee_addr[3], dev_annce_params->ieee_addr[2], dev_annce_params->ieee_addr[1], dev_annce_params->ieee_addr[0]);
        
        if(dev_annce_params->capability == 142) { //switch
			power_outlet_short_addr = dev_annce_params->device_short_addr;
			draw_socket_pair_panel(&power_outlet_short_addr, false);
        }
        if(dev_annce_params->capability == 128) { //temp / humidity sensor
			ESP_LOGI(TAG, "Temperature Sensor found");
			//power_outlet_short_addr = dev_annce_params->device_short_addr;
			//draw_socket_pair_panel(&power_outlet_short_addr, false);
			
        esp_zb_zdo_bind_req_param_t bind_req;
        thermometer_device_params_t *thermometer = (thermometer_device_params_t *)malloc(sizeof(thermometer_device_params_t));
        thermometer->endpoint = 3;
        thermometer->short_addr = dev_annce_params->device_short_addr;
        esp_zb_ieee_address_by_short(thermometer->short_addr, thermometer->ieee_addr);
        esp_zb_get_long_address(bind_req.src_address);
        bind_req.src_endp = THERMOMETER_ENDPOINT;
        bind_req.cluster_id = ESP_ZB_ZCL_CLUSTER_ID_TEMP_MEASUREMENT;
        bind_req.dst_addr_mode = ESP_ZB_ZDO_BIND_DST_ADDR_MODE_64_BIT_EXTENDED;
        memcpy(bind_req.dst_address_u.addr_long, thermometer->ieee_addr, sizeof(esp_zb_ieee_addr_t));
        bind_req.dst_endp = thermometer->endpoint;
        bind_req.req_dst_addr = esp_zb_get_short_address(); /* TODO: Send bind request to self */
        ESP_LOGI(TAG, "Try to bind Thermometer");
        esp_zb_zdo_device_bind_req(&bind_req, thermometer_bind_cb, (void *)thermometer);
			
        }
        
        break;
    default:
		dev_annce_params = (esp_zb_zdo_signal_device_annce_params_t *)esp_zb_app_signal_get_params(p_sg_p);
		
        ESP_LOGI(TAG, "ZDO signal: %s (0x%x), status: %s, (short: 0x%04hx)", esp_zb_zdo_signal_to_string(sig_type), sig_type, esp_err_to_name(err_status), dev_annce_params->device_short_addr);
        break;
    }
}



static void esp_zb_task(void *pvParameters)
{
    /* initialize Zigbee stack */
	esp_zb_cfg_t zb_nwk_cfg = ESP_ZB_ZC_CONFIG();
    esp_zb_init(&zb_nwk_cfg);
    uint8_t test_attr;
    test_attr = 0;
    /* basic cluster create with fully customized */
    esp_zb_attribute_list_t *esp_zb_basic_cluster = esp_zb_zcl_attr_list_create(ESP_ZB_ZCL_CLUSTER_ID_BASIC);
    esp_zb_basic_cluster_add_attr(esp_zb_basic_cluster, ESP_ZB_ZCL_ATTR_BASIC_ZCL_VERSION_ID, &test_attr);
    esp_zb_basic_cluster_add_attr(esp_zb_basic_cluster, ESP_ZB_ZCL_ATTR_BASIC_POWER_SOURCE_ID, &test_attr);
    esp_zb_cluster_update_attr(esp_zb_basic_cluster, ESP_ZB_ZCL_ATTR_BASIC_ZCL_VERSION_ID, &test_attr);
    /* identify cluster create with fully customized */
    esp_zb_attribute_list_t *esp_zb_identify_cluster = esp_zb_zcl_attr_list_create(ESP_ZB_ZCL_CLUSTER_ID_IDENTIFY);
    esp_zb_identify_cluster_add_attr(esp_zb_identify_cluster, ESP_ZB_ZCL_ATTR_IDENTIFY_IDENTIFY_TIME_ID, &test_attr);
    /* create client role of the cluster */
    esp_zb_attribute_list_t *esp_zb_identify_client_cluster = esp_zb_zcl_attr_list_create(ESP_ZB_ZCL_CLUSTER_ID_IDENTIFY);
    /* temp meas cluster */
    esp_zb_temperature_meas_cluster_cfg_t temperature_cfg;                                                                          
    temperature_cfg.measured_value = ESP_ZB_ZCL_ATTR_TEMP_MEASUREMENT_VALUE_UNKNOWN;                   
    temperature_cfg.min_value = ESP_ZB_ZCL_ATTR_TEMP_MEASUREMENT_MIN_VALUE_INVALID;                   
    temperature_cfg.max_value = ESP_ZB_ZCL_ATTR_TEMP_MEASUREMENT_MAX_VALUE_INVALID;                    
    esp_zb_attribute_list_t *esp_zb_temperature_cluster = esp_zb_temperature_meas_cluster_create(&temperature_cfg);
      
    
    esp_zb_humidity_meas_cluster_cfg_t humidity_cfg;
    humidity_cfg.measured_value = 0;                   
    humidity_cfg.min_value = 0;                   
    humidity_cfg.max_value = 0;      
    esp_zb_attribute_list_t *esp_zb_humidity_cluster = esp_zb_humidity_meas_cluster_create(&humidity_cfg); 
        
    /* create cluster lists for this endpoint */
    esp_zb_cluster_list_t *esp_zb_cluster_list = esp_zb_zcl_cluster_list_create();
    esp_zb_cluster_list_add_basic_cluster(esp_zb_cluster_list, esp_zb_basic_cluster, ESP_ZB_ZCL_CLUSTER_SERVER_ROLE);
    esp_zb_cluster_list_add_identify_cluster(esp_zb_cluster_list, esp_zb_identify_cluster, ESP_ZB_ZCL_CLUSTER_SERVER_ROLE);
    esp_zb_cluster_list_add_identify_cluster(esp_zb_cluster_list, esp_zb_identify_client_cluster, ESP_ZB_ZCL_CLUSTER_CLIENT_ROLE);
    esp_zb_cluster_list_add_temperature_meas_cluster(esp_zb_cluster_list, esp_zb_temperature_cluster, ESP_ZB_ZCL_CLUSTER_CLIENT_ROLE);
    esp_zb_cluster_list_add_humidity_meas_cluster(esp_zb_cluster_list, esp_zb_humidity_cluster, ESP_ZB_ZCL_CLUSTER_CLIENT_ROLE);


    esp_zb_ep_list_t *esp_zb_ep_list = esp_zb_ep_list_create();
    /* add created endpoint (cluster_list) to endpoint list */
	esp_zb_ep_list_add_ep(esp_zb_ep_list, esp_zb_cluster_list, THERMOMETER_ENDPOINT, ESP_ZB_AF_HA_PROFILE_ID, ESP_ZB_HA_SIMPLE_SENSOR_DEVICE_ID);
	esp_zb_device_register(esp_zb_ep_list);   
    
    esp_zb_core_action_handler_register(zb_action_handler);  
    
    esp_zb_set_primary_network_channel_set(ESP_ZB_PRIMARY_CHANNEL_MASK);
    esp_zb_set_secondary_network_channel_set(ESP_ZB_SECONDARY_CHANNEL_MASK);  
    
    ESP_ERROR_CHECK(esp_zb_start(false));
	esp_zb_main_loop_iteration();

    
#if(CONFIG_ZB_RADIO_MACSPLIT_UART)
    esp_zb_add_rcp_failure_cb(rcp_error_handler);
#endif
    esp_zb_main_loop_iteration();
    esp_rcp_update_deinit();
    vTaskDelete(NULL);
}

extern void vCreateZigbeeTask(void)
{
    xTaskCreate(esp_zb_task, "Zigbee_main", 4096, NULL, 5, NULL);
}
