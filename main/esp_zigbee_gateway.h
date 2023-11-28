#ifndef ESP_ZIGBEE_GATEWAY_H
#define ESP_ZIGBEE_GATEWAY_H
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
#include "lvgl.h"
#include "ui_events.h"
#include "ui.h"
#include "general.h"
#include <fcntl.h>
#include <string.h>
#include "esp_log.h"
#include "esp_netif.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_vfs_eventfd.h"
#include "esp_spiffs.h"
#include "esp_wifi.h"
#include "nvs_flash.h"
#include "protocol_examples_common.h"
#include "esp_rcp_update.h"
#include "esp_coexist_internal.h"
#include "esp_err.h"
#include "esp_check.h"
#include "esp_zigbee_core.h"
#include "zcl/esp_zigbee_zcl_common.h"
#include "ha/esp_zigbee_ha_standard.h"
//#include "light_driver.h"
#include "esp_vfs_dev.h"
#include "esp_vfs_usb_serial_jtag.h"
#include "driver/usb_serial_jtag.h"



/* Zigbee Configuration */
#define MAX_CHILDREN                    10          /* the max amount of connected devices */
#define INSTALLCODE_POLICY_ENABLE       false       /* enable the install code policy for security */
#define HA_ONOFF_SWITCH_ENDPOINT        1  
#define HA_THERMOMETER_ENDPOINT			2
#define ESP_ZB_PRIMARY_CHANNEL_MASK     (1l << 13)  /* Zigbee primary channel mask use in the example */
#define ESP_ZB_SECONDARY_CHANNEL_MASK   (1l << 13) 

#define RCP_VERSION_MAX_SIZE            80
#define HOST_RESET_PIN_TO_RCP_RESET     CONFIG_PIN_TO_RCP_RESET
#define HOST_BOOT_PIN_TO_RCP_BOOT       CONFIG_PIN_TO_RCP_BOOT
#define HOST_RX_PIN_TO_RCP_TX           CONFIG_PIN_TO_RCP_TX
#define HOST_TX_PIN_TO_RCP_RX           CONFIG_PIN_TO_RCP_RX

#define ESP_ZB_ZC_CONFIG()                                                              \
    {                                                                                   \
        .esp_zb_role = ESP_ZB_DEVICE_TYPE_COORDINATOR,                                  \
        .install_code_policy = INSTALLCODE_POLICY_ENABLE,                               \
        .nwk_cfg.zczr_cfg = {                                                           \
            .max_children = MAX_CHILDREN,                                               \
        },                                                                              \
    }
    
  #define ED_AGING_TIMEOUT                ESP_ZB_ED_AGING_TIMEOUT_64MIN
#define ED_KEEP_ALIVE                   3000    /* 3000 millisecond */  
    #define ESP_ZB_ZED_CONFIG()                                         \
    {                                                               \
        .esp_zb_role = ESP_ZB_DEVICE_TYPE_ED,                       \
        .install_code_policy = INSTALLCODE_POLICY_ENABLE,           \
        .nwk_cfg.zed_cfg = {                                        \
            .ed_timeout = ED_AGING_TIMEOUT,                         \
            .keep_alive = ED_KEEP_ALIVE,                            \
        },                                                          \
    }
    

#if CONFIG_ZB_RADIO_NATIVE
#define ESP_ZB_DEFAULT_RADIO_CONFIG()                           \
    {                                                           \
        .radio_mode = RADIO_MODE_NATIVE,                        \
    }
#else
#define ESP_ZB_DEFAULT_RADIO_CONFIG()                           \
    {                                                           \
        .radio_mode = RADIO_MODE_UART_RCP,                      \
            .radio_uart_config = {                              \
            .port = 1,                                          \
            .uart_config =                                      \
                {                                               \
                    .baud_rate = 115200,                        \
                    .data_bits = UART_DATA_8_BITS,              \
                    .parity = UART_PARITY_DISABLE,              \
                    .stop_bits = UART_STOP_BITS_1,              \
                    .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,      \
                    .rx_flow_ctrl_thresh = 0,                   \
                    .source_clk = UART_SCLK_DEFAULT,            \
                },                                              \
            .rx_pin = HOST_RX_PIN_TO_RCP_TX,                    \
            .tx_pin = HOST_TX_PIN_TO_RCP_RX,                    \
        },                                                       \
    }
#endif

#define ESP_ZB_DEFAULT_HOST_CONFIG()                            \
    {                                                           \
        .host_connection_mode = HOST_CONNECTION_MODE_NONE,      \
    }

#define ESP_ZB_RCP_UPDATE_CONFIG()                                                                                                  \
    {                                                                                                                               \
        .rcp_type = RCP_TYPE_ESP32H2_UART, .uart_rx_pin = HOST_RX_PIN_TO_RCP_TX, .uart_tx_pin = HOST_TX_PIN_TO_RCP_RX,              \
        .uart_port = 1, .uart_baudrate = 115200, .reset_pin = HOST_RESET_PIN_TO_RCP_RESET, .boot_pin = HOST_BOOT_PIN_TO_RCP_BOOT,   \
        .update_baudrate = 460800, .firmware_dir = "/rcp_fw/ot_rcp", .target_chip = ESP32C6_CHIP,                                   \
    }
    
esp_err_t init_spiffs(void);  
void leave_device(lv_event_t * e);
void pair_socket(lv_event_t * e);    
void vCreateZigbeeTask(void);

#endif
