#include "general.h"

static const char *TAG = "general.c";

static nvs_handle_t storage_handle;
static esp_err_t err;
static char somestring[36];

/////////////////////////////////////////////////////////
////////////////////// TIME /////////////////////////////
/////////////////////////////////////////////////////////

timer_queue_element_t tenttime;
uint32_t seconds_left_in_period;
uint16_t minutes_left_in_period;
uint16_t hours_left_in_period;

void update_time_left(bool count_day) {
	
    if(tenttime.seconds == 86400) {
		increase_day_counter(NULL);
		tenttime.seconds = 0;
	}		
	
	if(tenttime.seconds < tenttime.day_period_seconds) { //day
		if(!tenttime.is_day)
			make_it_day(count_day);
		seconds_left_in_period = tenttime.day_period_seconds - tenttime.seconds;
	} else { 
		if(tenttime.is_day)                              //night
			make_it_night();         
		seconds_left_in_period = 86400 - tenttime.seconds;
	}
	
	minutes_left_in_period = seconds_left_in_period / 60;
	hours_left_in_period = minutes_left_in_period / 60;
	
	if (tenttime.seconds % 2) {
		lv_label_set_text_fmt(ui_TimeLeftLabel, "- %d hrs   %d min", hours_left_in_period, minutes_left_in_period % 60);
	} else {
		lv_label_set_text_fmt(ui_TimeLeftLabel, "- %d hrs . %d min", hours_left_in_period, minutes_left_in_period % 60);
	}
	
	if(tenttime.seconds % 300 == 0) {
	err = nvs_open("storage", NVS_READWRITE, &storage_handle);
		if (err != ESP_OK) {
			printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
		} else {
			err = nvs_set_u32(storage_handle, "seconds", tenttime.seconds);
			err = nvs_commit(storage_handle);
			printf((err != ESP_OK) ? "Failed!\n" : "Saved Seconds\n");
			nvs_close(storage_handle);
		}
		
	}
	
}

void make_it_day(bool count_day) {
	tenttime.is_day = true;
	lv_obj_set_style_bg_color(ui_HomeScreen, lv_color_hex(0x28652A), LV_PART_MAIN | LV_STATE_DEFAULT );
	lv_img_set_src(ui_HomeSky, &ui_img_791711567);
	if(count_day)
		increase_day_counter(NULL);

}

void make_it_night() {
	tenttime.is_day = false;
	lv_obj_set_style_bg_color(ui_HomeScreen, lv_color_hex(0x0E114D), LV_PART_MAIN | LV_STATE_DEFAULT );
	lv_img_set_src(ui_HomeSky, &ui_img_432815713);
}

/////////////////////////////////////////////////////////
///////////////// TEMP UNIT /////////////////////////////
/////////////////////////////////////////////////////////

void update_temp_units(uint16_t temp_unit) {
	
	if(temp_unit == 1) { //F
		lv_obj_add_state(ui_TempUnitSwitch, LV_STATE_CHECKED);
		lv_dropdown_set_options(ui_TemperatureDropdown, "53°F\n57°F\n60°F\n63°F\n66°F\n68°F\n70°F\n72°F\n74°F\n76°F\n78°F\n");
		lv_label_set_text(ui_HomeTempUnitLabel, "°F");
	} else {
		lv_dropdown_set_options(ui_TemperatureDropdown, "12°C\n14°C\n16°C\n18°C\n20°C\n22°C\n24°C\n26°C\n28°C\n30°C\n32°C");
		lv_label_set_text(ui_HomeTempUnitLabel, "°C"); 
	}
	
}

/////////////////////////////////////////////////////////
///////////////// LEDC (PWM) ////////////////////////////
/////////////////////////////////////////////////////////

void ledc_init(void)
{
  // Prepare and then apply the LEDC PWM BACKLIGHT timer configuration
    ledc_timer_config_t ledc_timer = {
        .speed_mode       = LEDC_MODE,
        .timer_num        = LEDC_BACKLIGHT_TIMER,
        .duty_resolution  = LEDC_BACKLIGHT_DUTY_RES,
        .freq_hz          = LEDC_BACKLIGHT_FREQUENCY,  // Set output frequency
        .clk_cfg          = LEDC_AUTO_CLK
    };
    ESP_ERROR_CHECK(ledc_timer_config(&ledc_timer));

    // Prepare and then apply the LEDC PWM channel configuration
    ledc_channel_config_t ledc_channel = {
        .speed_mode     = LEDC_MODE,
        .channel        = LEDC_BACKLIGHT_CHANNEL,
        .timer_sel      = LEDC_BACKLIGHT_TIMER,
        .intr_type      = LEDC_INTR_DISABLE,
        .gpio_num       = LEDC_BACKLIGHT_OUTPUT_IO,
        .duty           = 0, // Set duty to 0%
        .hpoint         = 0
    };
    ESP_ERROR_CHECK(ledc_channel_config(&ledc_channel));  
    
  // FAN PWM
    ledc_timer_config_t ledc_fan_timer = {
        .speed_mode       = LEDC_MODE,
        .timer_num        = LEDC_FAN_TIMER,
        .duty_resolution  = LEDC_FAN_DUTY_RES,
        .freq_hz          = LEDC_FAN_FREQUENCY,  // Set output frequency
        .clk_cfg          = LEDC_AUTO_CLK
    };
    ESP_ERROR_CHECK(ledc_timer_config(&ledc_fan_timer));

    ledc_channel_config_t ledc_fan_channel = {
        .speed_mode     = LEDC_MODE,
        .channel        = LEDC_FAN_CHANNEL,
        .timer_sel      = LEDC_FAN_TIMER,
        .intr_type      = LEDC_INTR_DISABLE,
        .gpio_num       = LEDC_FAN_OUTPUT_IO,
        .duty           = 0, // Set duty to 0%
        .hpoint         = 0
    };
    ESP_ERROR_CHECK(ledc_channel_config(&ledc_fan_channel));      
   
  // DIMMER PWM
    ledc_timer_config_t ledc_dimmer_timer = {
        .speed_mode       = LEDC_MODE,
        .timer_num        = LEDC_DIMMER_TIMER,
        .duty_resolution  = LEDC_DIMMER_DUTY_RES,
        .freq_hz          = LEDC_DIMMER_FREQUENCY,  // Set output frequency
        .clk_cfg          = LEDC_AUTO_CLK
    };
    ESP_ERROR_CHECK(ledc_timer_config(&ledc_dimmer_timer));

    ledc_channel_config_t ledc_dimmer_channel = {
        .speed_mode     = LEDC_MODE,
        .channel        = LEDC_DIMMER_CHANNEL,
        .timer_sel      = LEDC_DIMMER_TIMER,
        .intr_type      = LEDC_INTR_DISABLE,
        .gpio_num       = LEDC_DIMMER_OUTPUT_IO,
        .duty           = 0, // Set duty to 0%
        .hpoint         = 0
    };
    ESP_ERROR_CHECK(ledc_channel_config(&ledc_dimmer_channel));       
    
}



/////////////////////////////////////////////////////////
///////////////// Event Loop ////////////////////////////
/////////////////////////////////////////////////////////


void event_loop_init(void) {
	//ESP_ERROR_CHECK(esp_event_loop_create_default());
	//ESP_ERROR_CHECK(esp_event_handler_instance_register(WIFI_EVENT, WIFI_EVENT_SCAN_DONE, wifi_scan_done_handler, NULL, NULL));
}

/////////////////////////////////////////////////////////
///////////////// WIFI //////////////////////////////////
/////////////////////////////////////////////////////////

#define DEFAULT_SCAN_LIST_SIZE 12

static void print_auth_mode(int authmode)
{
    switch (authmode) {
    case WIFI_AUTH_OPEN:
        ESP_LOGI(TAG, "Authmode \tWIFI_AUTH_OPEN");
        break;
    case WIFI_AUTH_OWE:
        ESP_LOGI(TAG, "Authmode \tWIFI_AUTH_OWE");
        break;
    case WIFI_AUTH_WEP:
        ESP_LOGI(TAG, "Authmode \tWIFI_AUTH_WEP");
        break;
    case WIFI_AUTH_WPA_PSK:
        ESP_LOGI(TAG, "Authmode \tWIFI_AUTH_WPA_PSK");
        break;
    case WIFI_AUTH_WPA2_PSK:
        ESP_LOGI(TAG, "Authmode \tWIFI_AUTH_WPA2_PSK");
        break;
    case WIFI_AUTH_WPA_WPA2_PSK:
        ESP_LOGI(TAG, "Authmode \tWIFI_AUTH_WPA_WPA2_PSK");
        break;
    case WIFI_AUTH_WPA2_ENTERPRISE:
        ESP_LOGI(TAG, "Authmode \tWIFI_AUTH_WPA2_ENTERPRISE");
        break;
    case WIFI_AUTH_WPA3_PSK:
        ESP_LOGI(TAG, "Authmode \tWIFI_AUTH_WPA3_PSK");
        break;
    case WIFI_AUTH_WPA2_WPA3_PSK:
        ESP_LOGI(TAG, "Authmode \tWIFI_AUTH_WPA2_WPA3_PSK");
        break;
    default:
        ESP_LOGI(TAG, "Authmode \tWIFI_AUTH_UNKNOWN");
        break;
    }
}

static void print_cipher_type(int pairwise_cipher, int group_cipher)
{
    switch (pairwise_cipher) {
    case WIFI_CIPHER_TYPE_NONE:
        ESP_LOGI(TAG, "Pairwise Cipher \tWIFI_CIPHER_TYPE_NONE");
        break;
    case WIFI_CIPHER_TYPE_WEP40:
        ESP_LOGI(TAG, "Pairwise Cipher \tWIFI_CIPHER_TYPE_WEP40");
        break;
    case WIFI_CIPHER_TYPE_WEP104:
        ESP_LOGI(TAG, "Pairwise Cipher \tWIFI_CIPHER_TYPE_WEP104");
        break;
    case WIFI_CIPHER_TYPE_TKIP:
        ESP_LOGI(TAG, "Pairwise Cipher \tWIFI_CIPHER_TYPE_TKIP");
        break;
    case WIFI_CIPHER_TYPE_CCMP:
        ESP_LOGI(TAG, "Pairwise Cipher \tWIFI_CIPHER_TYPE_CCMP");
        break;
    case WIFI_CIPHER_TYPE_TKIP_CCMP:
        ESP_LOGI(TAG, "Pairwise Cipher \tWIFI_CIPHER_TYPE_TKIP_CCMP");
        break;
    case WIFI_CIPHER_TYPE_AES_CMAC128:
        ESP_LOGI(TAG, "Pairwise Cipher \tWIFI_CIPHER_TYPE_AES_CMAC128");
        break;
    case WIFI_CIPHER_TYPE_SMS4:
        ESP_LOGI(TAG, "Pairwise Cipher \tWIFI_CIPHER_TYPE_SMS4");
        break;
    case WIFI_CIPHER_TYPE_GCMP:
        ESP_LOGI(TAG, "Pairwise Cipher \tWIFI_CIPHER_TYPE_GCMP");
        break;
    case WIFI_CIPHER_TYPE_GCMP256:
        ESP_LOGI(TAG, "Pairwise Cipher \tWIFI_CIPHER_TYPE_GCMP256");
        break;
    default:
        ESP_LOGI(TAG, "Pairwise Cipher \tWIFI_CIPHER_TYPE_UNKNOWN");
        break;
    }

switch (group_cipher) {
    case WIFI_CIPHER_TYPE_NONE:
        ESP_LOGI(TAG, "Group Cipher \tWIFI_CIPHER_TYPE_NONE");
        break;
    case WIFI_CIPHER_TYPE_WEP40:
        ESP_LOGI(TAG, "Group Cipher \tWIFI_CIPHER_TYPE_WEP40");
        break;
    case WIFI_CIPHER_TYPE_WEP104:
        ESP_LOGI(TAG, "Group Cipher \tWIFI_CIPHER_TYPE_WEP104");
        break;
    case WIFI_CIPHER_TYPE_TKIP:
        ESP_LOGI(TAG, "Group Cipher \tWIFI_CIPHER_TYPE_TKIP");
        break;
    case WIFI_CIPHER_TYPE_CCMP:
        ESP_LOGI(TAG, "Group Cipher \tWIFI_CIPHER_TYPE_CCMP");
        break;
    case WIFI_CIPHER_TYPE_TKIP_CCMP:
        ESP_LOGI(TAG, "Group Cipher \tWIFI_CIPHER_TYPE_TKIP_CCMP");
        break;
    case WIFI_CIPHER_TYPE_SMS4:
        ESP_LOGI(TAG, "Group Cipher \tWIFI_CIPHER_TYPE_SMS4");
        break;
    case WIFI_CIPHER_TYPE_GCMP:
        ESP_LOGI(TAG, "Group Cipher \tWIFI_CIPHER_TYPE_GCMP");
        break;
    case WIFI_CIPHER_TYPE_GCMP256:
        ESP_LOGI(TAG, "Group Cipher \tWIFI_CIPHER_TYPE_GCMP256");
        break;
    default:
        ESP_LOGI(TAG, "Group Cipher \tWIFI_CIPHER_TYPE_UNKNOWN");
        break;
    }
}

uint16_t number = DEFAULT_SCAN_LIST_SIZE;
wifi_ap_record_t ap_info[DEFAULT_SCAN_LIST_SIZE];
uint16_t ap_count = 0;   

static int s_retry_num = 0;
#define EXAMPLE_ESP_MAXIMUM_RETRY  5
static EventGroupHandle_t s_wifi_event_group;
#define WIFI_CONNECTED_BIT BIT0
#define WIFI_FAIL_BIT      BIT1
#define ESP_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_OPEN
#define ESP_WIFI_SAE_MODE WPA3_SAE_PWE_HUNT_AND_PECK
//#define EXAMPLE_H2E_IDENTIFIER ""

static void wifi_event_handler(void* arg, esp_event_base_t event_base, int32_t event_id, void* event_data)
{
	if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_SCAN_DONE)
	{
		char* ssid = "";
		err = nvs_open("storage", NVS_READONLY, &storage_handle);
		if (err != ESP_OK) {
			printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
		} else { 
		
		size_t required_size;
		nvs_get_str(storage_handle, "ssid", NULL, &required_size);
		ssid = malloc(required_size);
		err = nvs_get_str(storage_handle, "ssid", ssid, &required_size);
		nvs_close(storage_handle);
		//ESP_LOGI(TAG, "SSID %s", ssid);
		}
		
		memset(ap_info, 0, sizeof(ap_info));
		ESP_ERROR_CHECK(esp_wifi_scan_get_ap_records(&number, ap_info));
		ESP_ERROR_CHECK(esp_wifi_scan_get_ap_num(&ap_count));
		
		uint8_t saved_ssid_index = 232;

		for (int i = 0; (i < DEFAULT_SCAN_LIST_SIZE) && (i < ap_count); i++) {
			//ESP_LOGI(TAG, "SSID \t\t%s", ap_info[i].ssid);
			//ESP_LOGI(TAG, "RSSI \t\t%d", ap_info[i].rssi);
			sprintf(somestring, "%s", ap_info[i].ssid);
			lv_dropdown_add_option(ui_WifiDropdown, somestring, i);
			//print_auth_mode(ap_info[i].authmode);
			if (ap_info[i].authmode != WIFI_AUTH_WEP) {
				//print_cipher_type(ap_info[i].pairwise_cipher, ap_info[i].group_cipher);
			}
			//ESP_LOGI(TAG, "Channel \t\t%d\n", ap_info[i].primary);
			
			if( strcmp( somestring, ssid ) == 0 )
				saved_ssid_index = i;
			
		}
		
		lv_label_set_text(ui_WifiStatusLabel, "");
		
		if (ap_count == 0) {
			lv_dropdown_add_option(ui_WifiDropdown, "No Wifi Networks found", 0);
		} else if (saved_ssid_index != 232) {
			lv_dropdown_set_selected(ui_WifiDropdown, saved_ssid_index);
			//lv_label_set_text(ui_WifiStatusLabel, "connecting ...");
			//wifi_connect();
		}
		
	}
	
    if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_START) {
        esp_wifi_connect();
    } else if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_DISCONNECTED) {
        if (s_retry_num < EXAMPLE_ESP_MAXIMUM_RETRY) {
            esp_wifi_connect();
            s_retry_num++;
            ESP_LOGI(TAG, "retry to connect to the AP");
        } else {
            xEventGroupSetBits(s_wifi_event_group, WIFI_FAIL_BIT);
        }
        ESP_LOGI(TAG,"connect to the AP fail");
    } else if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP) {
        ip_event_got_ip_t* event = (ip_event_got_ip_t*) event_data;
        ESP_LOGI(TAG, "got ip:" IPSTR, IP2STR(&event->ip_info.ip));
        lv_label_set_text(ui_WifiStatusLabel, "connected"); 
        s_retry_num = 0;
        xEventGroupSetBits(s_wifi_event_group, WIFI_CONNECTED_BIT);
    }
}

esp_netif_t *sta_netif;
esp_event_handler_instance_t instance_any_id;
esp_event_handler_instance_t instance_got_ip;
static EventGroupHandle_t s_wifi_event_group;
#define WIFI_CONNECTED_BIT BIT0
#define WIFI_FAIL_BIT      BIT1

void wifi_init(void)
{
    s_wifi_event_group = xEventGroupCreate();

    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    sta_netif = esp_netif_create_default_wifi_sta();

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

    esp_event_handler_instance_t instance_any_id;
    esp_event_handler_instance_t instance_got_ip;
    ESP_ERROR_CHECK(esp_event_handler_instance_register(WIFI_EVENT,
                                                        ESP_EVENT_ANY_ID,
                                                        &wifi_event_handler,
                                                        NULL,
                                                        &instance_any_id));
    ESP_ERROR_CHECK(esp_event_handler_instance_register(IP_EVENT,
                                                        IP_EVENT_STA_GOT_IP,
                                                        &wifi_event_handler,
                                                        NULL,
                                                        &instance_got_ip));


    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_start());
    
}

void wifi_scan(void)
{
	lv_dropdown_clear_options(ui_WifiDropdown);
    esp_wifi_scan_start(NULL, false);
    lv_label_set_text(ui_WifiStatusLabel, "searching...");  
}


void wifi_connect(void)
{
	
	const char *pw = lv_textarea_get_text(ui_WifiPassword);
	char ssid[128];
    lv_dropdown_get_selected_str(ui_WifiDropdown, ssid, sizeof(ssid));
        
    wifi_config_t wifi_config = {};
    strcpy((char *)wifi_config.sta.ssid, ssid);
    strcpy((char *)wifi_config.sta.password, pw);  //"kk1wnxz3rbq6t",
            /* Authmode threshold resets to WPA2 as default if password matches WPA2 standards (pasword len => 8).
             * If you want to connect the device to deprecated WEP/WPA networks, Please set the threshold value
             * to WIFI_AUTH_WEP/WIFI_AUTH_WPA_PSK and set the password with length and format matching to
             * WIFI_AUTH_WEP/WIFI_AUTH_WPA_PSK standards.
             */    
    wifi_config.sta.threshold.authmode = ESP_WIFI_SCAN_AUTH_MODE_THRESHOLD;
    wifi_config.sta.sae_pwe_h2e = WPA3_SAE_PWE_BOTH;    
	//wifi_config.sta.sae_pwe_h2e = EXAMPLE_H2E_IDENTIFIER;
	
    ESP_LOGI(TAG, "wifi_init_sta finished.");
    
    ESP_ERROR_CHECK(esp_wifi_stop() );
    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config) );
    ESP_ERROR_CHECK(esp_wifi_start() );
    
    /* Waiting until either the connection is established (WIFI_CONNECTED_BIT) or connection failed for the maximum
     * number of re-tries (WIFI_FAIL_BIT). The bits are set by wifi_event_handler() (see above) */
    EventBits_t bits = xEventGroupWaitBits(s_wifi_event_group,
            WIFI_CONNECTED_BIT | WIFI_FAIL_BIT,
            pdFALSE,
            pdFALSE,
            portMAX_DELAY);

    /* xEventGroupWaitBits() returns the bits before the call returned, hence we can test which event actually
     * happened. */
    if (bits & WIFI_CONNECTED_BIT) {
        ESP_LOGI(TAG, "connected to ap SSID:%s password:%s", "SSID", "PASS");
    } else if (bits & WIFI_FAIL_BIT) {
        ESP_LOGI(TAG, "Failed to connect to SSID:%s, password:%s", "SSID", "PASS");
    } else {
        ESP_LOGE(TAG, "UNEXPECTED EVENT");
    }
}

void wifi_off(void)
{
	esp_netif_destroy_default_wifi(sta_netif);
	esp_wifi_disconnect();
	esp_wifi_stop();
	esp_wifi_deinit();
	esp_event_loop_delete_default();
	lv_dropdown_clear_options(ui_WifiDropdown);
}
