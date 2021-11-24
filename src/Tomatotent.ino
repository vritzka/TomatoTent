#include "Particle.h"
#include <Arduino.h>
#include "softap_http.h"
#include "tent.h"
#include "screen_manager.h"
#include "assets.h"
#include "api_server.h"
#include "HttpClient.h"

PRODUCT_ID(10167);
PRODUCT_VERSION(34);

Tent tent;
ScreenManager screenManager;
ApiServer server;
HttpClient http;

SYSTEM_MODE(SEMI_AUTOMATIC);
SYSTEM_THREAD(ENABLED);

struct Page {
    const char* url;
    const char* mime_type;
    const char* data;
};

Page myPages[] = {
    { "/index.html", "text/html", index_html },
    { "/rsa-utils/rsa.js", "application/javascript", rsa_js },
    { "/style.css", "text/css", style_css },
    { "/rsa-utils/rng.js", "application/javascript", rng_js },
    { "/rsa-utils/jsbn_2.js", "application/javascript", jsbn_2_js },
    { "/rsa-utils/jsbn_1.js", "application/javascript", jsbn_1_js },
    { "/script.js", "application/javascript", script_js },
    { "/rsa-utils/prng4.js", "application/javascript", prng4_js },
    { nullptr }
};

void myPage(const char* url, ResponseCallback* cb, void* cbArg, Reader* body, Writer* result, void* reserved)
{
    Serial.printlnf("handling page %s", url);

    if (strcmp(url, "/index") == 0) {
        Serial.println("sending redirect");
        Header h("Location: /index.html\r\n");
        cb(cbArg, 0, 301, "text/plain", &h);
        return;
    }

    int8_t idx = 0;
    for (;; idx++) {
        Page& p = myPages[idx];
        if (!p.url) {
            idx = -1;
            break;
        } else if (strcmp(url, p.url) == 0) {
            break;
        }
    }

    if (idx == -1) {
        cb(cbArg, 0, 404, nullptr, nullptr);
    } else {
        cb(cbArg, 0, 200, myPages[idx].mime_type, nullptr);
        result->write(myPages[idx].data);
    }
}

// Press SETUP for 3 seconds to make the Photon enter Listening mode
// Navigate to http://192.168.0.1 to setup Wi-Fi

void setup_handler()
{
    screenManager.wifiSplashScreen();
    tent.stop();
}

void setup_finished_handler()
{
    screenManager.homeScreen();
    tent.start();
}

STARTUP(
    softap_set_application_page_handler(myPage, nullptr);
    pinMode(FAN_SPEED_PIN, OUTPUT);
    analogWrite(FAN_SPEED_PIN, 255, 25000);
    pinMode(FAN_SPEED_PIN_2, OUTPUT);
    if(tent.getHardwareVersion() == 1) {
        analogWrite(FAN_SPEED_PIN_2, 255, 4000);
    } else {
        analogWrite(FAN_SPEED_PIN_2, 0, 4000);
    }
    pinMode(TFT_BRIGHTNESS_PIN, OUTPUT);
    pinMode(GROW_LIGHT_BRIGHTNESS_PIN, OUTPUT);
    pinMode(GROW_LIGHT_ON_OFF_PIN, OUTPUT);
    pinMode(DIM_PIN, INPUT_PULLUP);
    pinMode(HARDWAREFLAG_PIN, INPUT_PULLUP);
)

void firmware_update_handler(system_event_t event, int status)
{
    if (status == firmware_update_begin) {
        screenManager.firmwareUpdateScreen();
    }
}

void network_status_handler(system_event_t event, int status)
{
    if (status == network_status_connected) {

        if(screenManager.current->getName() == "wifiScreen")
            screenManager.wifiScreen();

        http_request_t request;
        http_response_t response;

        http_header_t headers[] = {
            { "Accept", "*/*" },
            { NULL, NULL }
        };

        request.port = 80;
        request.path = "/" + System.deviceID();

        request.hostname = "claim-device.tomatotent.com";
        http.get(request, response, headers);

        request.hostname = "add-to-particle-product.tomatotent.com";
        http.get(request, response, headers);

        if(tent.getHardwareVersion() == 2) {
            request.hostname = "assign-group.tomatotent.com";
            http.get(request, response, headers);
        }        
    }
}

void cloud_status_handler(system_event_t event, int status)
{
    if (status == cloud_status_connected) {
        if(screenManager.current->getName() == "wifiScreen")
            screenManager.wifiScreen();
    }
}

void button_click_handler(system_event_t event, int status)
{
    tent.displayLightHigh();
}

void setup()
{
    //System.disableUpdates();

    Serial.begin(9600);
    System.enableFeature(FEATURE_RESET_INFO);

    System.set(SYSTEM_CONFIG_SOFTAP_PREFIX, "TMT");

    System.on(setup_begin, setup_handler);
    System.on(setup_end, setup_finished_handler);

    WiFi.setHostname("TTNT-" + System.deviceID());

    screenManager.setup();
    screenManager.homeScreen();
    tent.setup();

    System.on(firmware_update, firmware_update_handler);
    System.on(network_status, network_status_handler);
    System.on(cloud_status, cloud_status_handler);
    System.on(button_click, button_click_handler);

    setADCSampleTime(ADC_SampleTime_56Cycles);

    server.begin();
}

void loop(void)
{

    screenManager.tick();

    tent.checkInputs();
    tent.checkSensors();

    if (screenManager.current) {
        screenManager.current->update();
    }

    server.processConnection();
}