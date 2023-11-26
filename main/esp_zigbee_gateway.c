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
 * 
 * https://github.com/espressif/esp-zigbee-sdk/blob/main/examples/esp_zigbee_customized_devices/customized_client/main/esp_HA_customized_switch.c
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



/////////////////////////////////////
/////////// SWITCH //////////////////
/////////////////////////////////////

typedef struct light_bulb_device_params_s {
    esp_zb_ieee_addr_t ieee_addr;
    uint8_t  endpoint;
    uint16_t short_addr;
} light_bulb_device_params_t;

typedef struct thermometer_device_params_s {
    esp_zb_ieee_addr_t ieee_addr;
    uint8_t  endpoint;
    uint16_t short_addr;
} thermometer_device_params_t;

typedef struct zdo_info_ctx_s {
    uint8_t endpoint;
    uint16_t short_addr;
} zdo_info_user_ctx_t;

thermometer_device_params_t thermometer;


static void thermometer_bind_cb(esp_zb_zdp_status_t zdo_status, void *user_ctx)
{
    if (zdo_status == ESP_ZB_ZDP_STATUS_SUCCESS) {
        ESP_LOGI(TAG, "Bind response from address(0x%x), endpoint(%d) with status(%d)", ((zdo_info_user_ctx_t *)user_ctx)->short_addr,
                 ((zdo_info_user_ctx_t *)user_ctx)->endpoint, zdo_status);
        /* configure report attribute command */
        esp_zb_zcl_config_report_cmd_t report_cmd;
        bool report_change = 0;
        report_cmd.zcl_basic_cmd.dst_addr_u.addr_short = thermometer.short_addr;
        report_cmd.zcl_basic_cmd.dst_endpoint = thermometer.endpoint;
        report_cmd.zcl_basic_cmd.src_endpoint = HA_THERMOMETER_ENDPOINT;
        report_cmd.address_mode = ESP_ZB_APS_ADDR_MODE_16_ENDP_PRESENT;
        report_cmd.clusterID = ESP_ZB_ZCL_CLUSTER_ID_TEMP_MEASUREMENT;

        esp_zb_zcl_config_report_record_t records[] = {
            {ESP_ZB_ZCL_CMD_DIRECTION_TO_SRV, ESP_ZB_ZCL_ATTR_TEMP_MEASUREMENT_VALUE_ID, ESP_ZB_ZCL_ATTR_TYPE_U16, 0, 5, &report_change}};
        report_cmd.record_number = sizeof(records) / sizeof(esp_zb_zcl_config_report_record_t);
        report_cmd.record_field = records;

        esp_zb_zcl_config_report_cmd_req(&report_cmd);
        
        
    }
}

static void bind_cb(esp_zb_zdp_status_t zdo_status, void *user_ctx)
{
    if (zdo_status == ESP_ZB_ZDP_STATUS_SUCCESS) {
        ESP_LOGI(TAG, "Bound successfully!");
        return;
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

static void ep_cb(esp_zb_zdp_status_t zdo_status, uint8_t ep_count, uint8_t *ep_id_list, void *user_ctx)
{
    if (zdo_status == ESP_ZB_ZDP_STATUS_SUCCESS) {
        ESP_LOGI(TAG, "Active endpoint response: status(%d) and endpoint count(%d)", zdo_status, ep_count);
        for (int i = 0; i < ep_count; i++) {
            ESP_LOGI(TAG, "Endpoint ID List: %d", ep_id_list[i]);
        }
    }
}

static void simple_desc_cb(esp_zb_zdp_status_t zdo_status, esp_zb_af_simple_desc_1_1_t *simple_desc, void *user_ctx)
{
    if (zdo_status == ESP_ZB_ZDP_STATUS_SUCCESS) {
        ESP_LOGI(TAG, "Simple desc resposne: status(%d), device_id(%d), app_version(%d), profile_id(0x%x), endpoint_ID(%d)", zdo_status,
                 simple_desc->app_device_id, simple_desc->app_device_version, simple_desc->app_profile_id, simple_desc->endpoint);

        for (int i = 0; i < (simple_desc->app_input_cluster_count + simple_desc->app_output_cluster_count); i++) {
            ESP_LOGI(TAG, "Cluster ID list: 0x%x", *(simple_desc->app_cluster_list + i));
        }
    }
}

static void ieee_cb(esp_zb_zdp_status_t zdo_status, esp_zb_ieee_addr_t ieee_addr, void *user_ctx)
{
    if (zdo_status == ESP_ZB_ZDP_STATUS_SUCCESS) {
		
        memcpy(&(thermometer.ieee_addr), ieee_addr, sizeof(esp_zb_ieee_addr_t));
        ESP_LOGI(TAG, "IEEE address: %02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x",
                 ieee_addr[7], ieee_addr[6], ieee_addr[5], ieee_addr[4],
                 ieee_addr[3], ieee_addr[2], ieee_addr[1], ieee_addr[0]);
                 
        /* bind the on-off light to on-off switch */
       
        esp_zb_zdo_bind_req_param_t bind_req;
        memcpy(&(bind_req.src_address), thermometer.ieee_addr, sizeof(esp_zb_ieee_addr_t));
        bind_req.src_endp = thermometer.endpoint;
        bind_req.cluster_id = ESP_ZB_ZCL_CLUSTER_ID_TEMP_MEASUREMENT;
        bind_req.dst_addr_mode = ESP_ZB_ZDO_BIND_DST_ADDR_MODE_64_BIT_EXTENDED;
        esp_zb_get_long_address(bind_req.dst_address_u.addr_long);
        bind_req.dst_endp = HA_THERMOMETER_ENDPOINT;
        bind_req.req_dst_addr = thermometer.short_addr;
        static zdo_info_user_ctx_t test_info_ctx;
        test_info_ctx.endpoint = HA_THERMOMETER_ENDPOINT;
        test_info_ctx.short_addr = thermometer.short_addr;
        esp_zb_zdo_device_bind_req(&bind_req, thermometer_bind_cb, (void *) & (test_info_ctx));
       
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
        esp_zb_get_long_address(bind_req.src_address);
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

static void user_thermometer_find_cb(esp_zb_zdp_status_t zdo_status, uint16_t addr, uint8_t endpoint, void *user_ctx)
{
	   if (zdo_status == ESP_ZB_ZDP_STATUS_SUCCESS) {
        ESP_LOGI(TAG, "Found thermometer");
        ESP_LOGI(TAG, "Match desc response: status(%d), address(0x%x), endpoint(%d)", zdo_status, addr, endpoint);
        /* save into remote device record structure for future use */
        thermometer.endpoint = endpoint;
        thermometer.short_addr = addr;
        /* find the active endpoint */
        esp_zb_zdo_active_ep_req_param_t active_ep_req;
        active_ep_req.addr_of_interest = thermometer.short_addr;
        esp_zb_zdo_active_ep_req(&active_ep_req, ep_cb, NULL);
        /* get the node simple descriptor */
        esp_zb_zdo_simple_desc_req_param_t simple_desc_req;
        simple_desc_req.addr_of_interest = addr;
        simple_desc_req.endpoint = endpoint;
        esp_zb_zdo_simple_desc_req(&simple_desc_req, simple_desc_cb, NULL);
        /* get the light ieee address */
        esp_zb_zdo_ieee_addr_req_param_t ieee_req;
        ieee_req.addr_of_interest = thermometer.short_addr;
        ieee_req.dst_nwk_addr = thermometer.short_addr;
        ieee_req.request_type = 0;
        ieee_req.start_index = 0;
        esp_zb_zdo_ieee_addr_req(&ieee_req, ieee_cb, NULL);
        esp_zb_zcl_read_attr_cmd_t read_req;
        uint16_t attributes[] = {ESP_ZB_ZCL_ATTR_ON_OFF_ON_OFF_ID};
        read_req.address_mode = ESP_ZB_APS_ADDR_MODE_16_ENDP_PRESENT;
        read_req.attr_number = sizeof(attributes) / sizeof(uint16_t);
        read_req.attr_field = attributes;
        read_req.clusterID = ESP_ZB_ZCL_CLUSTER_ID_TEMP_MEASUREMENT;
        read_req.zcl_basic_cmd.dst_endpoint = thermometer.endpoint;
        read_req.zcl_basic_cmd.src_endpoint = HA_THERMOMETER_ENDPOINT;
        read_req.zcl_basic_cmd.dst_addr_u.addr_short = thermometer.short_addr;
        esp_zb_zcl_read_attr_cmd_req(&read_req);        
        
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
uint16_t power_outlet_short_addr;

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
            ESP_LOGI(TAG, "Formed network successfully (ieee_address: %02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x, PAN ID: 0x%04hx, Channel:%d, Short Address: 0x%04hx)",
                     ieee_address[7], ieee_address[6], ieee_address[5], ieee_address[4],
                     ieee_address[3], ieee_address[2], ieee_address[1], ieee_address[0],
                     esp_zb_get_pan_id(), esp_zb_get_current_channel(), esp_zb_get_short_address());
            esp_zb_bdb_start_top_level_commissioning(ESP_ZB_BDB_MODE_NETWORK_STEERING);
        } else {
            ESP_LOGI(TAG, "Restart network formation (status: %s)", esp_err_to_name(err_status));
            esp_zb_scheduler_alarm((esp_zb_callback_t)bdb_start_top_level_commissioning_cb, ESP_ZB_BDB_MODE_NETWORK_FORMATION, 1000);
        }
        break;
    case ESP_ZB_BDB_SIGNAL_STEERING:
        
        if (err_status != ESP_OK) {
            ESP_LOGW(TAG, "Stack %s failure with %s status, steering",esp_zb_zdo_signal_to_string(sig_type), esp_err_to_name(err_status));
            esp_zb_scheduler_alarm((esp_zb_callback_t)bdb_start_top_level_commissioning_cb, ESP_ZB_BDB_MODE_NETWORK_STEERING, 1000);
        } else {
            /* device auto start successfully and on a formed network */
            esp_zb_ieee_addr_t extended_pan_id;
            esp_zb_get_extended_pan_id(extended_pan_id);
            ESP_LOGI(TAG, "Joined network successfully (Extended PAN ID: %02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x, PAN ID: 0x%04hx, Channel:%d, Short Address: 0x%04hx)",
                     extended_pan_id[7], extended_pan_id[6], extended_pan_id[5], extended_pan_id[4],
                     extended_pan_id[3], extended_pan_id[2], extended_pan_id[1], extended_pan_id[0],
                     esp_zb_get_pan_id(), esp_zb_get_current_channel(), esp_zb_get_short_address());
        }        
        
        
        break;
    case ESP_ZB_ZDO_SIGNAL_DEVICE_ANNCE:
        dev_annce_params = (esp_zb_zdo_signal_device_annce_params_t *)esp_zb_app_signal_get_params(p_sg_p);
        ESP_LOGI(TAG, "New device found (short: 0x%04hx), Capabilities: %d", dev_annce_params->device_short_addr, dev_annce_params->capability);

        ESP_LOGI(TAG, "IEEE address: %02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x",
                 dev_annce_params->ieee_addr[7], dev_annce_params->ieee_addr[6], dev_annce_params->ieee_addr[5], dev_annce_params->ieee_addr[4],
                 dev_annce_params->ieee_addr[3], dev_annce_params->ieee_addr[2], dev_annce_params->ieee_addr[1], dev_annce_params->ieee_addr[0]);
        
        if(dev_annce_params->capability == 142) {
			power_outlet_short_addr = dev_annce_params->device_short_addr;
			draw_socket_pair_panel(&power_outlet_short_addr, false);
        }
        
        
		esp_zb_zdo_match_desc_req_param_t find_req;
		uint16_t cluster_list[] = {ESP_ZB_ZCL_CLUSTER_ID_TEMP_MEASUREMENT};
		find_req.dst_nwk_addr = dev_annce_params->device_short_addr;
		find_req.addr_of_interest = dev_annce_params->device_short_addr;
		find_req.profile_id = ESP_ZB_AF_HA_PROFILE_ID;
		find_req.num_in_clusters = 2;
		find_req.num_out_clusters = 0;
		find_req.cluster_list = cluster_list;
		esp_zb_zdo_match_cluster(&find_req, user_thermometer_find_cb, NULL);
        
        break;
    case ESP_ZB_NWK_SIGNAL_PERMIT_JOIN_STATUS:
        if (err_status == ESP_OK) {
            if (*(uint8_t *)esp_zb_app_signal_get_params(p_sg_p)) {
                ESP_LOGI(TAG, "Network(0x%04hx) is open for %d seconds", esp_zb_get_pan_id(), *(uint8_t *)esp_zb_app_signal_get_params(p_sg_p));
            } else {
                ESP_LOGW(TAG, "Network(0x%04hx) closed, devices joining not allowed.", esp_zb_get_pan_id());
            }
        }
        break;
    default:
        ESP_LOGI(TAG, "ZDO signal: %s (0x%x), status: %s", esp_zb_zdo_signal_to_string(sig_type), sig_type,
                 esp_err_to_name(err_status));
        break;
    }
}

void rcp_error_handler(uint8_t connect_timeout)
{
    ESP_LOGI(TAG, "RCP connection failed timeout:%d seconds", connect_timeout);
#if(CONFIG_ZIGBEE_GW_AUTO_UPDATE_RCP)
    ESP_LOGI(TAG, "Timeout! Re-flashing RCP");
    esp_zb_gateway_update_rcp();
#endif
}





static esp_err_t zb_attribute_reporting_handler(const esp_zb_zcl_report_attr_message_t *message)
{
    ESP_RETURN_ON_FALSE(message, ESP_FAIL, TAG, "Empty message");
    ESP_RETURN_ON_FALSE(message->status == ESP_ZB_ZCL_STATUS_SUCCESS, ESP_ERR_INVALID_ARG, TAG, "Received message: error status(%d)",
                        message->status);
    ESP_LOGI(TAG, "Reveived report from address(0x%x) src endpoint(%d) to dst endpoint(%d) cluster(0x%x)", message->src_address.u.short_addr,
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

    esp_zb_zcl_read_attr_resp_variable_t *variable = message->variables;
    while (variable) {
        ESP_LOGI(TAG, "Read attribute response: status(%d), cluster(0x%x), attribute(0x%x), type(0x%x), value(%d)", variable->status,
                 message->info.cluster, variable->attribute.id, variable->attribute.data.type,
                 variable->attribute.data.value ? *(uint8_t *)variable->attribute.data.value : 0);
        variable = variable->next;
    }

    return ESP_OK;
}

static esp_err_t zb_configure_report_resp_handler(const esp_zb_zcl_cmd_config_report_resp_message_t *message)
{
    ESP_RETURN_ON_FALSE(message, ESP_FAIL, TAG, "Empty message");
    ESP_RETURN_ON_FALSE(message->info.status == ESP_ZB_ZCL_STATUS_SUCCESS, ESP_ERR_INVALID_ARG, TAG, "Received message: error status(%d)",
                        message->info.status);

    esp_zb_zcl_config_report_resp_variable_t *variable = message->variables;
    while (variable) {
        ESP_LOGI(TAG, "Configure report response: status(%d), cluster(0x%x), attribute(0x%x)", message->info.status, message->info.cluster,
                 variable->attribute_id);
        variable = variable->next;
    }

    return ESP_OK;
}

static esp_err_t zb_action_handler(esp_zb_core_action_callback_id_t callback_id, const void *message)
{
    esp_err_t ret = ESP_OK;
    switch (callback_id) {
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




static void esp_zb_task(void *pvParameters)
{
    /* initialize Zigbee stack */
    esp_zb_cfg_t zb_nwk_cfg = ESP_ZB_ZC_CONFIG();
    esp_zb_init(&zb_nwk_cfg);  
    esp_zb_core_action_handler_register(zb_action_handler); 
    esp_zb_set_primary_network_channel_set(ESP_ZB_PRIMARY_CHANNEL_MASK);
    ESP_ERROR_CHECK(esp_zb_start(false));
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
