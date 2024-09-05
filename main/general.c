#include "general.h"

static const char *TAG = "general.c";

static nvs_handle_t storage_handle;
SemaphoreHandle_t xGuiSemaphore;
static esp_err_t err;
static char somestring[36];
static esp_http_client_handle_t client;

tent_data_t my_tent;

static esp_err_t https_post_request(char post_data[]);
static void post_vital_data();

/////////////////////////////////////////////////////////
////////////////////// TIME /////////////////////////////
/////////////////////////////////////////////////////////

uint32_t seconds_left_in_period;
uint16_t minutes_left_in_period;
uint16_t hours_left_in_period;

void heartbeat(bool count_day) {
	
	if (my_tent.seconds == 86400) {
		my_tent.seconds = 0;
		if(my_tent.is_drying)
			make_it_drying(count_day);
	}
	
	if(my_tent.seconds % 1800 == 0)
		lv_slider_set_value(ui_NowSlider, (my_tent.seconds/30/60), LV_ANIM_OFF);

	if(my_tent.seconds % 5 == 0) {
		read_scd40();
	}	
	
	if(my_tent.seconds % 60 == 0) {	
		setGrowLampBrightness();
		post_vital_data();
	}
	
		if(my_tent.seconds < my_tent.day_period_seconds) { //day
			if(!my_tent.is_day && !my_tent.is_drying)
				make_it_day(count_day);
			
			seconds_left_in_period = my_tent.day_period_seconds - my_tent.seconds;
		} else { 
			if(my_tent.is_day)                              //night
				make_it_night();         
			seconds_left_in_period = 86400 - my_tent.seconds;
		}
	
	minutes_left_in_period = seconds_left_in_period / 60;
	hours_left_in_period = minutes_left_in_period / 60;

	if(my_tent.is_day) {
		my_tent.period_progress = my_tent.seconds;
	} else {
		my_tent.period_progress = my_tent.seconds-my_tent.day_period_seconds;
	}
	
	if(seconds_left_in_period > 59) {
		
		if (my_tent.seconds % 2) {
			lv_label_set_text_fmt(ui_TimeLeftLabel, "- %d hrs   %d min", hours_left_in_period, minutes_left_in_period % 60);
		} else {
			lv_label_set_text_fmt(ui_TimeLeftLabel, "- %d hrs . %d min", hours_left_in_period, minutes_left_in_period % 60);
		}
		
	} else {
		lv_label_set_text_fmt(ui_TimeLeftLabel, "- %lu", seconds_left_in_period);
	}
	
	if(my_tent.seconds % 300 == 0) {
	err = nvs_open("storage", NVS_READWRITE, &storage_handle);
		if (err != ESP_OK) {
			printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
		} else {
			err = nvs_set_u32(storage_handle, "seconds", my_tent.seconds+1);
			err = nvs_commit(storage_handle);
			printf((err != ESP_OK) ? "Failed!\n" : "Saved Seconds\n");
			nvs_close(storage_handle);
		}
		if(count_day)
			chart_add_climate_point();
	}
	
	if(my_tent.seconds < 120 && (my_tent.seconds % 10 == 0)) //to quickly display something on the graph for newly started grows
		chart_add_climate_point();
		
	if(my_tent.grow_lamp_dimmed) {	
		static uint64_t dimmer_timer_raw_count;
		gptimer_get_raw_count(grow_lamp_dimmer_timer_handle, &dimmer_timer_raw_count);
		
		uint16_t dimmed_seconds = dimmer_timer_raw_count/1000000;
		lv_arc_set_value(ui_DimmerArc, 900-dimmed_seconds);
		lv_bar_set_value(ui_DimmerBar2, 900-dimmed_seconds, LV_ANIM_OFF);
		
		if(dimmed_seconds == 899) {
			HideDimmerIndication_Animation(ui_DimmerIconPanel, 0);
			HideDimmerIndication2_Animation(ui_DimmerIconPanel2, 0);
			lv_arc_set_value(ui_DimmerArc, 900);
			lv_bar_set_value(ui_DimmerBar2, 900, LV_ANIM_OFF);
			ESP_LOGI(TAG, "Un-Dimmed");		
			setGrowLampBrightness();			
		}
	}
	
}

void make_it_day(bool count_day) {
	ESP_LOGI(TAG, "Making it Day");
	my_tent.is_day = true;
	lv_obj_set_style_bg_color(ui_HomeScreen, lv_color_hex(0x28652A), LV_PART_MAIN | LV_STATE_DEFAULT );
	lv_obj_set_style_bg_color(ui_GraphScreen, lv_color_hex(0x28652A), LV_PART_MAIN | LV_STATE_DEFAULT );
	lv_img_set_src(ui_HomeSky, &ui_img_791711567);
	if(count_day) {
		ESP_LOGI(TAG, "Counting the Day");
		increase_day_counter(NULL);
	}
}

void make_it_night() {
	ESP_LOGI(TAG, "Making it Night");
	my_tent.is_day = false;
	lv_obj_set_style_bg_color(ui_HomeScreen, lv_color_hex(0x0E114D), LV_PART_MAIN | LV_STATE_DEFAULT );
	lv_obj_set_style_bg_color(ui_GraphScreen, lv_color_hex(0x0E114D), LV_PART_MAIN | LV_STATE_DEFAULT );
	lv_img_set_src(ui_HomeSky, &ui_img_432815713);
	lv_slider_set_value(ui_LightDurationSlider, my_tent.light_duration_slider_value, LV_ANIM_OFF);
}

void make_it_drying(bool count_day) {
	ESP_LOGI(TAG, "Making it Drying");
	my_tent.is_day = false;
	my_tent.is_drying = true;
	lv_obj_set_style_bg_color(ui_HomeScreen, lv_color_hex(0x6f623c), LV_PART_MAIN | LV_STATE_DEFAULT );
	lv_obj_set_style_bg_color(ui_GraphScreen, lv_color_hex(0x6f623c), LV_PART_MAIN | LV_STATE_DEFAULT );
	lv_img_set_src(ui_HomeSky, &ui_img_bud_png);
	if(count_day) {
		ESP_LOGI(TAG, "Counting the Day");
		increase_day_counter(NULL);
	}
}

/////////////////////////////////////////////////////////
/////////////////// CLIMATE /////////////////////////////
/////////////////////////////////////////////////////////

void update_temp_units(uint16_t temp_unit) {
	
	if(temp_unit == 1) { //F
		lv_obj_add_state(ui_TempUnitSwitch, LV_STATE_CHECKED);
		lv_dropdown_set_options(ui_TemperatureDropdown, "53°F\n57°F\n60°F\n63°F\n66°F\n68°F\n70°F\n72°F\n74°F\n76°F\n78°F");
		lv_label_set_text(ui_HomeTempUnitLabel, "°F");
		lv_label_set_text(ui_TempUnitLabel2, "°F");
	} else {
		lv_dropdown_set_options(ui_TemperatureDropdown, "12°C\n14°C\n16°C\n18°C\n20°C\n22°C\n24°C\n26°C\n28°C\n30°C\n32°C");
		lv_label_set_text(ui_HomeTempUnitLabel, "°C");
		lv_label_set_text(ui_TempUnitLabel2, "°C"); 
	}
	lv_dropdown_set_selected(ui_TemperatureDropdown, my_tent.target_temperature_sel_index);
}

void set_target_climate() {

	if(my_tent.climate_mode == 1) { //manual
		
		ESP_LOGI(TAG, "Manual Climate");
		static char buf[3];
		lv_dropdown_get_selected_str(ui_HumidityDropdown, buf, sizeof(buf));

		sscanf(buf, "%hhd", &my_tent.target_humidity);

		lv_dropdown_get_selected_str(ui_TemperatureDropdown, buf, sizeof(buf));
		
		if(my_tent.temp_unit == 1) { //f
			sscanf(buf, "%f", &my_tent.target_temperature_f);
			my_tent.target_temperature_c = CELSIUS(my_tent.target_temperature_f);
		} else { //f
			sscanf(buf, "%f", &my_tent.target_temperature_c);
			my_tent.target_temperature_f = FAHRENHEIT(my_tent.target_temperature_c);
		}	
		ESP_LOGI(TAG, "Target Hum:%d", my_tent.target_humidity);	
		ESP_LOGI(TAG, "Target T C:%.2f", my_tent.target_temperature_c);
		ESP_LOGI(TAG, "Target T F:%.2f", my_tent.target_temperature_f);
	} else { //auto
		
		ESP_LOGI(TAG, "Auto CLimate");
		my_tent.target_humidity = 66;
		my_tent.target_temperature_c = 22;
		my_tent.target_temperature_f = 71.6;
				
	}
}

/////////////////////////////////////////////////////////
/////////////////    SENSOR     /////////////////////////
/////////////////////////////////////////////////////////
 #define TEMPERATURE_OFFSET          (4.0)
 #define SENSOR_ALTITUDE             (0)
 char scale = SCALE_CELCIUS;
void init_scd40() {

 ESP_LOGI(TAG, "SCD40 Sensor serial number 0x%012llX", scd4x_get_serial_number());

 	vTaskDelay(500 / portTICK_PERIOD_MS);
     float temperature_offset = scd4x_get_temperature_offset();
     vTaskDelay(500 / portTICK_PERIOD_MS);
     uint16_t sensor_altitude = scd4x_get_sensor_altitude();

     if(temperature_offset != SCD41_READ_ERROR && sensor_altitude != SCD41_READ_ERROR) {

         if(temperature_offset != TEMPERATURE_OFFSET) {
             ESP_LOGW(TAG, "Temperature offset calibration from %.1f °%c to %.1f °%c", temperature_offset, scale, TEMPERATURE_OFFSET, scale);

             vTaskDelay(500 / portTICK_PERIOD_MS);
             ESP_ERROR_CHECK_WITHOUT_ABORT(scd4x_set_temperature_offset(TEMPERATURE_OFFSET));

            vTaskDelay(500 / portTICK_PERIOD_MS);

            ESP_ERROR_CHECK_WITHOUT_ABORT(scd4x_set_temperature_offset(TEMPERATURE_OFFSET));

             vTaskDelay(500 / portTICK_PERIOD_MS);
             ESP_ERROR_CHECK_WITHOUT_ABORT(scd4x_persist_settings());

             vTaskDelay(500 / portTICK_PERIOD_MS);
             temperature_offset = scd4x_get_temperature_offset();
         }

         if(sensor_altitude != SENSOR_ALTITUDE) {
             ESP_LOGW(TAG, "Sensor altitude calibration from %d m to %d m", sensor_altitude, SENSOR_ALTITUDE);

             vTaskDelay(500 / portTICK_PERIOD_MS);
             ESP_ERROR_CHECK_WITHOUT_ABORT(scd4x_set_sensor_altitude(SENSOR_ALTITUDE));

             vTaskDelay(500 / portTICK_PERIOD_MS);
             ESP_ERROR_CHECK_WITHOUT_ABORT(scd4x_persist_settings());

             vTaskDelay(500 / portTICK_PERIOD_MS);
             sensor_altitude = scd4x_get_sensor_altitude();
         }
         ESP_LOGI(TAG, "Temperature offset %.1f °%c - Sensor altitude %d %s", temperature_offset, scale, sensor_altitude, scale == SCALE_CELCIUS ? "m" : "ft");
     } else {
         ESP_LOGE(TAG, "Sensor offset/altitude read error!");
     }

     vTaskDelay(500 / portTICK_PERIOD_MS);

 	scd4x_start_periodic_measurement();
}

void read_scd40() {

	scd4x_sensors_values_t sensors_values = {
 		.co2 = 0x00,
 		.temperature = 0x00,
 		.humidity = 0x00
     };

	float es;
    float ae;

	 ESP_LOGI(TAG, "Sensor");

 			if(scd4x_read_measurement(&sensors_values) != ESP_OK) {
 				ESP_LOGE(TAG, "Sensors read measurement error!");
                my_tent.temperature_c = 0;
 			    my_tent.temperature_f = 0;
 			    my_tent.humidity = 0;
 			    my_tent.co2 = 0;
                my_tent.vpd = 0;
                update_displayed_values();
                setFanSpeed();
 			}

 			my_tent.temperature_c = sensors_values.temperature;
 			my_tent.temperature_f = FAHRENHEIT(sensors_values.temperature);
 			my_tent.humidity = sensors_values.humidity;
 			my_tent.co2 = sensors_values.co2;
            
            es = 0.61078 * exp(17.2694 * my_tent.temperature_c / (my_tent.temperature_c + 238.3));
            ae = my_tent.humidity / 100 * es;
            my_tent.vpd = es - ae;  //kPa

 			ESP_LOGI(TAG, "CO₂ %d ppm - Temperature %2.1f - Humidity %d%% - VPD %2.1f", my_tent.co2, my_tent.temperature_c, my_tent.humidity, my_tent.vpd);
            update_displayed_values();
            setFanSpeed();

}
/////////////////////////////////////////////////////////
///////////////// LEDC (PWM) ////////////////////////////
/////////////////////////////////////////////////////////

void init_ledc(void)
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

static int s_retry_num = 0;
#define EXAMPLE_ESP_MAXIMUM_RETRY  2
static EventGroupHandle_t s_wifi_event_group;
#define WIFI_CONNECTED_BIT BIT0
#define WIFI_FAIL_BIT      BIT1
#define ESP_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_OPEN
#define ESP_WIFI_SAE_MODE WPA3_SAE_PWE_HUNT_AND_PECK
//#define EXAMPLE_H2E_IDENTIFIER ""

uint16_t number = DEFAULT_SCAN_LIST_SIZE;
wifi_ap_record_t ap_info[DEFAULT_SCAN_LIST_SIZE];
uint16_t ap_count = 0;

static void wifi_event_handler(void* arg, esp_event_base_t event_base, int32_t event_id, void* event_data)
{
	if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_SCAN_DONE)
	{

        memset(ap_info, 0, sizeof(ap_info));
		
		char* ssid = "";
		err = nvs_open("storage", NVS_READWRITE, &storage_handle);
		if (err != ESP_OK) {
			printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
		} else { 
		
		size_t required_size = 1;
		nvs_get_str(storage_handle, "ssid", NULL, &required_size);
		ssid = malloc(required_size);
		err = nvs_get_str(storage_handle, "ssid", ssid, &required_size);
		nvs_close(storage_handle);
		//ESP_LOGI(TAG, "SSID %s", ssid);
		}
		
		//memset(ap_info, 0, sizeof(ap_info));
		ESP_ERROR_CHECK(esp_wifi_scan_get_ap_num(&ap_count));
        ESP_ERROR_CHECK(esp_wifi_scan_get_ap_records(&number, ap_info));

        ESP_LOGI(TAG, "Total APs scanned = %u, actual AP number ap_info holds = %u", ap_count, number);
		
		uint8_t saved_ssid_index = 232;

		for (int i = 0; (i < DEFAULT_SCAN_LIST_SIZE) && (i < ap_count); i++) {
			ESP_LOGI(TAG, "SSID \t\t%s", ap_info[i].ssid);
			ESP_LOGI(TAG, "RSSI \t\t%d", ap_info[i].rssi);
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
				
		if (ap_count == 0) {
			lv_dropdown_add_option(ui_WifiDropdown, "No Wifi Networks found", 0);
		} else if (saved_ssid_index != 232) {
			//lv_dropdown_set_selected(ui_WifiDropdown, saved_ssid_index);
		}
		
	}
	
    if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_START) {
		ESP_LOGI(TAG, "Wifi Connecting started");
        lv_label_set_text(ui_WifiStatusLabel, "On");
        esp_wifi_connect();
    } else if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_DISCONNECTED) {
		my_tent.wifi_connected = 0;
        if (s_retry_num < EXAMPLE_ESP_MAXIMUM_RETRY) {
            esp_wifi_connect();
            s_retry_num++;
            ESP_LOGI(TAG, "retry to connect to the AP");
            lv_label_set_text(ui_WifiStatusLabel, "re-trying");
        } else {
            xEventGroupSetBits(s_wifi_event_group, WIFI_FAIL_BIT);
        }
        ESP_LOGI(TAG,"connect to the AP fail");
        lv_label_set_text(ui_WifiStatusLabel, "couldn't connect");
    } else if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP) {
        ip_event_got_ip_t* event = (ip_event_got_ip_t*) event_data;
        ESP_LOGI(TAG, "got ip:" IPSTR, IP2STR(&event->ip_info.ip));
        lv_label_set_text(ui_WifiStatusLabel, "connected"); 
		my_tent.wifi_connected = 1;
		esp_sntp_config_t config = ESP_NETIF_SNTP_DEFAULT_CONFIG_MULTIPLE(2, ESP_SNTP_SERVER_LIST("time.windows.com", "pool.ntp.org" ) );
		esp_netif_sntp_init(&config);
        s_retry_num = 0;
        xEventGroupSetBits(s_wifi_event_group, WIFI_CONNECTED_BIT);
    }
}

esp_netif_t *sta_netif;
//static EventGroupHandle_t s_wifi_event_group;
#define WIFI_CONNECTED_BIT BIT0
#define WIFI_FAIL_BIT      BIT1

void wifi_init(void)
{

    s_wifi_event_group = xEventGroupCreate();

    ESP_ERROR_CHECK(esp_netif_init());
    sta_netif = esp_netif_create_default_wifi_sta();
    assert(sta_netif);

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));


    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_start());
    
}

void wifi_scan(void)
{
    esp_wifi_scan_start(NULL, false);
    scanning_Animation(ui_scanning,0);
	lv_dropdown_clear_options(ui_WifiDropdown);
}


void wifi_connect(void)
{
	esp_wifi_disconnect();
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
	esp_netif_sntp_deinit();
	lv_dropdown_clear_options(ui_WifiDropdown);
	
}

void draw_qr_codes() {
	
	lv_color_t bg_color = lv_palette_lighten(LV_PALETTE_LIGHT_BLUE, 5);
    lv_color_t fg_color = lv_palette_darken(LV_PALETTE_BLUE, 4);

    lv_obj_t * qr = lv_qrcode_create(ui_QrCode1, 120, fg_color, bg_color);

    /*Set data*/
    char qr_url[58];
	snprintf(qr_url, 58, "https://my.tomatotent.com/graphs/%s", my_tent.device_id);

    lv_qrcode_update(qr, qr_url, strlen(qr_url)); 
    lv_obj_center(qr);

    /*Add a border with bg_color*/
    lv_obj_set_style_border_color(qr, bg_color, 0);
    lv_obj_set_style_border_width(qr, 5, 0);
}

/////////////////////////////////////////////////////////
///////////////// Event Loop ////////////////////////////
/////////////////////////////////////////////////////////
esp_event_handler_instance_t instance_any_id;
esp_event_handler_instance_t instance_got_ip;
static EventGroupHandle_t s_wifi_event_group;

void event_loop_init(void) {
	ESP_ERROR_CHECK(esp_event_loop_create_default());

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
}

/////////////////////////////////////////////////////////
///////////////////////  I2C  ///////////////////////////
/////////////////////////////////////////////////////////

void init_i2c() {


  ESP_LOGI(TAG, "Initialize I2C");

  const i2c_config_t i2c_conf = {
      .mode = I2C_MODE_MASTER,
      .sda_io_num = 48,
      .scl_io_num = 47,
      .sda_pullup_en = GPIO_PULLUP_ENABLE,
      .scl_pullup_en = GPIO_PULLUP_ENABLE,
      .master.clk_speed = 400000,
  };

  /* Initialize I2C */
  ESP_ERROR_CHECK(i2c_param_config(I2C_BUS_0, &i2c_conf));
  ESP_ERROR_CHECK(i2c_driver_install(I2C_BUS_0, i2c_conf.mode, 0, 0, 0));	
	
	 i2c_config_t i2c_config = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = I2C_MASTER_SDA,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_io_num = I2C_MASTER_SCL,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = I2C_MASTER_FREQ_HZ
    };

    ESP_ERROR_CHECK(i2c_param_config(I2C_MASTER_NUM, &i2c_config));
    ESP_ERROR_CHECK(i2c_driver_install(I2C_MASTER_NUM, i2c_config.mode, I2C_MASTER_RX_BUF_DISABLE, I2C_MASTER_TX_BUF_DISABLE, 0));
	
}


/////////////////////////////////////////////////////////
////////////////////////  FAN   /////////////////////////
/////////////////////////////////////////////////////////
static int8_t diff_temp, diff_hum;
static uint8_t fan_speed_temp, fan_speed_hum, fanspeed_range;
void setFanSpeed() {
		
	diff_temp = my_tent.temperature_c - my_tent.target_temperature_c;
	
	if(diff_temp > 5) {
		diff_temp = 5;
	} else if(diff_temp < -5) {
		diff_temp = -5;
	}
	
	//ESP_LOGI(TAG, "Diff Temp: %d", diff_temp);
	
	fanspeed_range = my_tent.fanspeed_slider_value - my_tent.fanspeed_slider_left_value;
		
	switch(diff_temp) {
	  case -5:
		fan_speed_temp = my_tent.fanspeed_slider_left_value;
		break;
	  case -4:
		fan_speed_temp = my_tent.fanspeed_slider_left_value + (fanspeed_range / 10);
		break;
	  case -3:
		fan_speed_temp = my_tent.fanspeed_slider_left_value + ( (fanspeed_range / 10) * 2);
		break;
	  case -2:
		fan_speed_temp = my_tent.fanspeed_slider_left_value + ( (fanspeed_range / 10) * 3);
		break;
	  case -1:
		fan_speed_temp = my_tent.fanspeed_slider_left_value + ( (fanspeed_range / 10) * 4);
		break;
	  case 0:
		fan_speed_temp = my_tent.fanspeed_slider_left_value + ( (fanspeed_range / 10) * 5);
		break;
	  case 1:
		fan_speed_temp = my_tent.fanspeed_slider_left_value + ( (fanspeed_range / 10) * 6);
		break;
	  case 2:
		fan_speed_temp = my_tent.fanspeed_slider_left_value + ( (fanspeed_range / 10) * 7);
		break;
	  case 3:
		fan_speed_temp = my_tent.fanspeed_slider_left_value + ( (fanspeed_range / 10) * 8);
		break;
	  case 4:
		fan_speed_temp = my_tent.fanspeed_slider_left_value + ( (fanspeed_range / 10) * 9);
		break;
	  case 5:
		fan_speed_temp = my_tent.fanspeed_slider_value;
		break;
	  default:
		fan_speed_temp = my_tent.fanspeed_slider_left_value + ( (fanspeed_range / 10) * 6);
	}
	
	//ESP_LOGI(TAG, "Fanspeed by Temp: %d%%", fan_speed_temp);

	diff_hum = my_tent.humidity - my_tent.target_humidity;

	//ESP_LOGI(TAG, "Diff Hum: %d%%", diff_hum);
	
	if(diff_hum > 10) {
		diff_hum = 10;
	} else if(diff_hum < -10) {
		diff_hum = -10;
	}	
	
	switch(diff_hum) {
	  case -10:
		fan_speed_hum = my_tent.fanspeed_slider_left_value;
		break;
	  case -9:	
		fan_speed_hum = my_tent.fanspeed_slider_left_value + (fanspeed_range / 20);
		break;
	  case -8:	
		fan_speed_hum = my_tent.fanspeed_slider_left_value + ( (fanspeed_range / 20) * 2);
		break;
	  case -7:
		fan_speed_hum = my_tent.fanspeed_slider_left_value + ( (fanspeed_range / 20) * 3);
		break;
	  case -6:
		fan_speed_hum = my_tent.fanspeed_slider_left_value + ( (fanspeed_range / 20) * 4);
		break;
	  case -5:
		fan_speed_hum = my_tent.fanspeed_slider_left_value + ( (fanspeed_range / 20) * 5);
		break;
	  case -4:
		fan_speed_hum = my_tent.fanspeed_slider_left_value + ( (fanspeed_range / 20) * 6);
		break;
	  case -3:
		fan_speed_hum = my_tent.fanspeed_slider_left_value + ( (fanspeed_range / 20) * 7);
		break;
	  case -2:
		fan_speed_hum = my_tent.fanspeed_slider_left_value + ( (fanspeed_range / 20) * 8);
		break;
	  case -1:
		fan_speed_hum = my_tent.fanspeed_slider_left_value + ( (fanspeed_range / 20) * 9);
		break;
	  case 0:
		fan_speed_hum = my_tent.fanspeed_slider_left_value + ( (fanspeed_range / 20) * 10);
	    break;
	  case 1:
		fan_speed_hum = my_tent.fanspeed_slider_left_value + ( (fanspeed_range / 20) * 11);
		break;
	  case 2:	
		fan_speed_hum = my_tent.fanspeed_slider_left_value + ( (fanspeed_range / 20) * 12);
		break;
	  case 3:	
		fan_speed_hum = my_tent.fanspeed_slider_left_value + ( (fanspeed_range / 20) * 13);
		break;
	  case 4:
		fan_speed_hum = my_tent.fanspeed_slider_left_value + ( (fanspeed_range / 20) * 14);
		break;
	  case 5:
		fan_speed_hum = my_tent.fanspeed_slider_left_value + ( (fanspeed_range / 20) * 15);
		break;
	  case 6:
		fan_speed_hum = my_tent.fanspeed_slider_left_value + ( (fanspeed_range / 20) * 16);
		break;
	  case 7:
		fan_speed_hum = my_tent.fanspeed_slider_left_value + ( (fanspeed_range / 20) * 17);
		break;
	  case 8:
		fan_speed_hum = my_tent.fanspeed_slider_left_value + ( (fanspeed_range / 20) * 18);
		break;
	  case 9:
		fan_speed_hum = my_tent.fanspeed_slider_left_value + ( (fanspeed_range / 20) * 19);
		break;
	  case 10:
		fan_speed_hum = my_tent.fanspeed_slider_value;
		break;
	  default:
	  fan_speed_hum = my_tent.fanspeed_slider_left_value + ( (fanspeed_range / 20) * 11);	  	  	  	  	  	  	  	  	  	
	}

	//ESP_LOGI(TAG, "Fanspeed by Hum: %d%%", fan_speed_hum);

	if(my_tent.seconds == 0) {
		my_tent.fanspeed = 0;	
	} else {
		my_tent.fanspeed = fan_speed_hum > fan_speed_temp? fan_speed_hum:fan_speed_temp;
	}

	ESP_LOGI(TAG, "Fanspeed: %d%%", my_tent.fanspeed);
	ESP_ERROR_CHECK(ledc_set_duty(LEDC_MODE, LEDC_FAN_CHANNEL, (128-1)*(float)my_tent.fanspeed / 100));
    ESP_ERROR_CHECK(ledc_update_duty(LEDC_MODE, LEDC_FAN_CHANNEL));	

}


/////////////////////////////////////////////////////////
///////////////////  GROW LAMP   ////////////////////////
/////////////////////////////////////////////////////////

static uint16_t dimmer_brightness;
void setGrowLampBrightness() {

	if(my_tent.is_drying) {
		dimmer_brightness = 0;
	} else {

	
		if(my_tent.is_day) {
			
			ESP_LOGI(TAG, "Daytime");
			
			if(my_tent.seconds < (15*60)) {  // sunrise
				
				ESP_LOGI(TAG, "Sunrise");
				
				dimmer_brightness = (my_tent.led_brightness_slider_value / 14) * (my_tent.seconds/60);
				lv_label_set_text_fmt(ui_LEDBrightnessLabel, "%d %%", my_tent.led_brightness_slider_value);

			} else if( (my_tent.seconds >= (my_tent.day_period_seconds - (15*60)) ) ) {   // sunset
			
				ESP_LOGI(TAG, "Sunset");
				dimmer_brightness = (my_tent.led_brightness_slider_value / 14) * ((my_tent.day_period_seconds - my_tent.seconds)/60);
					lv_label_set_text_fmt(ui_LEDBrightnessLabel, "%d %%", my_tent.led_brightness_slider_value);
			} else {
				
				ESP_LOGI(TAG, "Normal Daytime");
				dimmer_brightness = my_tent.led_brightness_slider_value; // normal daytime
				lv_label_set_text_fmt(ui_LEDBrightnessLabel, "%d %%", my_tent.led_brightness_slider_value);
			}
			
			if(my_tent.grow_lamp_dimmed && dimmer_brightness > 15) {
				dimmer_brightness = 15;
				lv_label_set_text_fmt(ui_LEDBrightnessLabel, "%d %%", my_tent.led_brightness_slider_value);
			}
		} else { // night
			
			ESP_LOGI(TAG, "Nighttime");
			dimmer_brightness = 0;
			lv_label_set_text_fmt(ui_LEDBrightnessLabel, "%d %%", my_tent.led_brightness_slider_value);
					
		}
	}
	ESP_LOGI(TAG, "dimmer_brightness %d%%", dimmer_brightness);
	
	my_tent.dimmer_brightness_duty = (64)*((float)dimmer_brightness / 100);	
	ESP_ERROR_CHECK(ledc_set_duty(LEDC_MODE, LEDC_DIMMER_CHANNEL, my_tent.dimmer_brightness_duty));
    ESP_ERROR_CHECK(ledc_update_duty(LEDC_MODE, LEDC_DIMMER_CHANNEL));	
	
}

/////////////////////////////////////////////////////////
////////////////////  CHART  ////////////////////////////
/////////////////////////////////////////////////////////

lv_chart_series_t * chart_series_temperature;
lv_chart_series_t * chart_series_humidity;
lv_chart_series_t * chart_series_fanspeed;
lv_chart_series_t * chart_series_co2;

void chart_init() {

chart_series_temperature = lv_chart_add_series(ui_Chart, lv_color_hex(0xEF5F3C), LV_CHART_AXIS_PRIMARY_Y);
chart_series_humidity = lv_chart_add_series(ui_Chart, lv_color_hex(0x3CB7FF), LV_CHART_AXIS_PRIMARY_Y);
chart_series_fanspeed = lv_chart_add_series(ui_Chart, lv_color_hex(0x787373), LV_CHART_AXIS_PRIMARY_Y);
chart_series_co2 = lv_chart_add_series(ui_Chart, lv_color_hex(0xAFBDC4), LV_CHART_AXIS_SECONDARY_Y);

//lv_chart_set_zoom_x(ui_Chart, 256);

lv_obj_add_state(ui_TempSeriesPanel, LV_STATE_CHECKED);
lv_obj_add_state(ui_HumiditySeriesPanel, LV_STATE_CHECKED);
lv_obj_add_state(ui_CO2SeriesPanel, LV_STATE_CHECKED);

lv_chart_hide_series(ui_Chart, chart_series_fanspeed, true);	

	int i = 0;
	while(i < 0) {
		lv_chart_set_next_value(ui_Chart, chart_series_temperature, lv_rand(18,25));
		lv_chart_set_next_value(ui_Chart, chart_series_humidity, lv_rand(50,60));
		lv_chart_set_next_value(ui_Chart, chart_series_fanspeed, lv_rand(60,80));
		lv_chart_set_next_value(ui_Chart, chart_series_co2, lv_rand(350,450));
		i++;
	}
	
}

void chart_add_climate_point() {
	
	if(my_tent.temp_unit) {
		lv_chart_set_next_value(ui_Chart, chart_series_temperature, my_tent.temperature_f);
	} else {
		lv_chart_set_next_value(ui_Chart, chart_series_temperature, my_tent.temperature_c);
	}
	lv_chart_set_next_value(ui_Chart, chart_series_humidity, my_tent.humidity);
	lv_chart_set_next_value(ui_Chart, chart_series_fanspeed, my_tent.fanspeed);
	lv_chart_set_next_value(ui_Chart, chart_series_co2, my_tent.co2);
	}


/////////////////////////////////////////////////////////
///////////////////  HELPERS  ///////////////////////////
/////////////////////////////////////////////////////////

void update_displayed_values() {
	
	if(my_tent.temp_unit) {
		lv_label_set_text_fmt(ui_TemperatureLabel, "%2.0f", my_tent.temperature_f);
		lv_label_set_text_fmt(ui_TemperatureLabel2, "%2.0f", my_tent.temperature_f);
	} else {
		lv_label_set_text_fmt(ui_TemperatureLabel, "%2.0f", my_tent.temperature_c);
		lv_label_set_text_fmt(ui_TemperatureLabel2, "%2.0f", my_tent.temperature_c);
	}
	
	lv_label_set_text_fmt(ui_HumidityLabel, "%d", my_tent.humidity);
	lv_label_set_text_fmt(ui_HumidityLabel2, "%d", my_tent.humidity);
	
	lv_label_set_text_fmt(ui_FanSpeedLabel, "%d%%", my_tent.fanspeed);
	lv_label_set_text_fmt(ui_FanSpeedLabel2, "%d", my_tent.fanspeed);
	lv_label_set_text_fmt(ui_FanSpeedLabel3, "%d%%", my_tent.fanspeed);
	
	lv_label_set_text_fmt(ui_VPDLabel, "%.1f kpa", my_tent.vpd);
	lv_label_set_text_fmt(ui_VPDLabel2, "%.1f", my_tent.vpd);
	
	lv_label_set_text_fmt(ui_Co2Label, "%d", my_tent.co2);
	lv_label_set_text_fmt(ui_Co2Label2, "%d", my_tent.co2);
}

long map(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

#define MAX_HTTP_RECV_BUFFER 512
#define MAX_HTTP_OUTPUT_BUFFER 2048

static esp_err_t _http_event_handler(esp_http_client_event_t *evt)
{
    static char *output_buffer;  // Buffer to store response of http request from event handler
    static int output_len;       // Stores number of bytes read
    switch(evt->event_id) {
        case HTTP_EVENT_ERROR:
            ESP_LOGD(TAG, "HTTP_EVENT_ERROR");
            break;
        case HTTP_EVENT_ON_CONNECTED:
            ESP_LOGD(TAG, "HTTP_EVENT_ON_CONNECTED");
            break;
        case HTTP_EVENT_HEADER_SENT:
            ESP_LOGD(TAG, "HTTP_EVENT_HEADER_SENT");
            break;
        case HTTP_EVENT_ON_HEADER:
            ESP_LOGD(TAG, "HTTP_EVENT_ON_HEADER, key=%s, value=%s", evt->header_key, evt->header_value);
            break;
        case HTTP_EVENT_ON_DATA:
            ESP_LOGD(TAG, "HTTP_EVENT_ON_DATA, len=%d", evt->data_len);
            // Clean the buffer in case of a new request
            if (output_len == 0 && evt->user_data) {
                // we are just starting to copy the output data into the use
                memset(evt->user_data, 0, MAX_HTTP_OUTPUT_BUFFER);
            }
            /*
             *  Check for chunked encoding is added as the URL for chunked encoding used in this example returns binary data.
             *  However, event handler can also be used in case chunked encoding is used.
             */
            if (!esp_http_client_is_chunked_response(evt->client)) {
                // If user_data buffer is configured, copy the response into the buffer
                int copy_len = 0;
                if (evt->user_data) {
                    // The last byte in evt->user_data is kept for the NULL character in case of out-of-bound access.
                    copy_len = MIN(evt->data_len, (MAX_HTTP_OUTPUT_BUFFER - output_len));
                    if (copy_len) {
                        memcpy(evt->user_data + output_len, evt->data, copy_len);
                    }
                } else {
                    int content_len = esp_http_client_get_content_length(evt->client);
                    if (output_buffer == NULL) {
                        // We initialize output_buffer with 0 because it is used by strlen() and similar functions therefore should be null terminated.
                        output_buffer = (char *) calloc(content_len + 1, sizeof(char));
                        output_len = 0;
                        if (output_buffer == NULL) {
                            ESP_LOGE(TAG, "Failed to allocate memory for output buffer");
                            return ESP_FAIL;
                        }
                    }
                    copy_len = MIN(evt->data_len, (content_len - output_len));
                    if (copy_len) {
                        memcpy(output_buffer + output_len, evt->data, copy_len);
                    }
                }
                output_len += copy_len;
            }

            break;
        case HTTP_EVENT_ON_FINISH:
            ESP_LOGD(TAG, "HTTP_EVENT_ON_FINISH");
            if (output_buffer != NULL) {
                ESP_LOG_BUFFER_HEX(TAG, output_buffer, output_len);
                free(output_buffer);
                output_buffer = NULL;
            }
            output_len = 0;
            break;
        case HTTP_EVENT_DISCONNECTED:
            ESP_LOGI(TAG, "HTTP_EVENT_DISCONNECTED");
            int mbedtls_err = 0;
            esp_err_t err = esp_tls_get_and_clear_last_error((esp_tls_error_handle_t)evt->data, &mbedtls_err, NULL);
            if (err != 0) {
                ESP_LOGI(TAG, "Last esp error code: 0x%x", err);
                ESP_LOGI(TAG, "Last mbedtls failure: 0x%x", mbedtls_err);
            }
            if (output_buffer != NULL) {
                free(output_buffer);
                output_buffer = NULL;
            }
            output_len = 0;
            break;
        case HTTP_EVENT_REDIRECT:
            ESP_LOGD(TAG, "HTTP_EVENT_REDIRECT");
            esp_http_client_set_header(evt->client, "From", "user@example.com");
            esp_http_client_set_header(evt->client, "Accept", "text/html");
            esp_http_client_set_redirection(evt->client);
            break;
    }
    return ESP_OK;
}


void init_http_client() {
    esp_http_client_config_t config = {
        .host = "graphite-blocks-prod-us-central1.grafana.net",
        .path = "/graphite/metrics",
        .transport_type = HTTP_TRANSPORT_OVER_SSL,
        .event_handler = _http_event_handler,
        .crt_bundle_attach = esp_crt_bundle_attach,
        .is_async = true,
        .username = "10495",
        .password = "eyJrIjoiZWUzZDMxNDMzZmFiZWUwY2U2YWMxMDdjYmFjYmIzNDNmODRlODgwNiIsIm4iOiJtZXRyaWNzIHB1c2giLCJpZCI6MzUwMDg5fQ",
        .timeout_ms = 5000,
        .auth_type = HTTP_AUTH_TYPE_BASIC,
    };

    client = esp_http_client_init(&config);
    
    esp_http_client_set_method(client, HTTP_METHOD_POST);
    esp_http_client_set_header(client, "Content-Type", "application/json");
}

static esp_err_t https_post_request(char post_data[])
{
     esp_http_client_set_post_field(client, post_data, strlen(post_data));

    while (1) {
        err = esp_http_client_perform(client);
        if (err != ESP_ERR_HTTP_EAGAIN) {
            break;
        }
    }
    if (err == ESP_OK) {
        ESP_LOGI(TAG, "HTTPS Status = %d, content_length = %"PRId64,
                esp_http_client_get_status_code(client),
                esp_http_client_get_content_length(client));
    } else {
        ESP_LOGE(TAG, "Error perform http request %s", esp_err_to_name(err));
    }
    return err;
   // esp_http_client_cleanup(client);

}

static void post_vital_data()
{
    if(my_tent.wifi_connected == 0 || my_tent.temperature_c == 0)
        return;

    time_t now;
    time(&now);

    char buf[64];
    cJSON *root,*air_temperature,*air_humidity,*grow_days,*light_on,*light_period,*period_progress,*fan_auto,*fan_speed,*co2;

    root=cJSON_CreateArray();

    air_temperature=cJSON_CreateObject();
    sprintf(buf,"devices.%s.air_temperature", my_tent.device_id);
    cJSON_AddItemToObject(air_temperature, "name", cJSON_CreateString(buf));
    cJSON_AddNumberToObject(air_temperature,"interval",	60);
    sprintf(buf,"%.2f", my_tent.temperature_c);
    cJSON_AddNumberToObject(air_temperature,"value", strtod(buf, NULL));
    cJSON_AddNumberToObject(air_temperature,"time", now);
    root->child=air_temperature;

    air_humidity=cJSON_CreateObject();
    sprintf(buf,"devices.%s.air_humidity", my_tent.device_id);
    cJSON_AddItemToObject(air_humidity, "name", cJSON_CreateString(buf));
    cJSON_AddNumberToObject(air_humidity,"interval",	60);
    cJSON_AddNumberToObject(air_humidity,"value", my_tent.humidity);
    cJSON_AddNumberToObject(air_humidity,"time", now);
    air_temperature->next=air_humidity; 

    co2=cJSON_CreateObject();
    sprintf(buf,"devices.%s.co2", my_tent.device_id);
    cJSON_AddItemToObject(co2, "name", cJSON_CreateString(buf));
    cJSON_AddNumberToObject(co2,"interval",	60);
    cJSON_AddNumberToObject(co2,"value", my_tent.co2);
    cJSON_AddNumberToObject(co2,"time", now);
    air_humidity->next=co2;    

    grow_days=cJSON_CreateObject();
    sprintf(buf,"devices.%s.grow_days", my_tent.device_id);
    cJSON_AddItemToObject(grow_days, "name", cJSON_CreateString(buf));
    cJSON_AddNumberToObject(grow_days,"interval",	60);
    cJSON_AddNumberToObject(grow_days,"value", my_tent.days);
    cJSON_AddNumberToObject(grow_days,"time", now);
    co2->next=grow_days;        

    light_on=cJSON_CreateObject();
    sprintf(buf,"devices.%s.light_on", my_tent.device_id);
    cJSON_AddItemToObject(light_on, "name", cJSON_CreateString(buf));
    cJSON_AddNumberToObject(light_on,"interval", 60);
    sprintf(buf,"%.2f", (float)my_tent.led_brightness_slider_value/100);
    cJSON_AddNumberToObject(light_on,"value", strtod(buf, NULL));
    cJSON_AddNumberToObject(light_on,"time", now);
    grow_days->next=light_on; 

    light_period=cJSON_CreateObject();
    sprintf(buf,"devices.%s.light_period", my_tent.device_id);
    cJSON_AddItemToObject(light_period, "name", cJSON_CreateString(buf));
    cJSON_AddNumberToObject(light_period,"interval", 60);
    cJSON_AddNumberToObject(light_period,"value", my_tent.light_duration*60.0);
    cJSON_AddNumberToObject(light_period,"time", now);
    light_on->next=light_period; 

    period_progress=cJSON_CreateObject();
    sprintf(buf,"devices.%s.period_progress", my_tent.device_id);
    cJSON_AddItemToObject(period_progress, "name", cJSON_CreateString(buf));
    cJSON_AddNumberToObject(period_progress,"interval", 60);
    cJSON_AddNumberToObject(period_progress,"value", my_tent.period_progress/60);
    cJSON_AddNumberToObject(period_progress,"time", now);
    light_period->next=period_progress; 

    fan_auto=cJSON_CreateObject();
    sprintf(buf,"devices.%s.fan_auto", my_tent.device_id);
    cJSON_AddItemToObject(fan_auto, "name", cJSON_CreateString(buf));
    cJSON_AddNumberToObject(fan_auto,"interval", 60);
    my_tent.climate_mode ? cJSON_AddNumberToObject(fan_auto,"value", 0) : cJSON_AddNumberToObject(fan_auto,"value", 1);
    cJSON_AddNumberToObject(fan_auto,"time", now);
    period_progress->next=fan_auto; 

    fan_speed=cJSON_CreateObject();
    sprintf(buf,"devices.%s.fan_speed", my_tent.device_id);
    cJSON_AddItemToObject(fan_speed, "name", cJSON_CreateString(buf));
    cJSON_AddNumberToObject(fan_speed,"interval", 60);
    cJSON_AddNumberToObject(fan_speed,"value", my_tent.fanspeed);
    cJSON_AddNumberToObject(fan_speed,"time", now);
    fan_auto->next=fan_speed; 

    char *rendered=cJSON_Print(root);
    //ESP_LOGI(TAG, "JSON: %s", rendered);

    https_post_request(rendered);
}