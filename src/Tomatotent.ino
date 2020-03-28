#include "Particle.h"
#include <Arduino.h>
#include "softap_http.h"
#include "tent.h"
#include "screen_manager.h"
#include "assets.h"
#include "api_server.h"

PRODUCT_ID(10167);
PRODUCT_VERSION(19);

Tent tent;
ScreenManager screenManager;
ApiServer server;

SYSTEM_MODE(SEMI_AUTOMATIC);

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
    pinMode(TFT_BRIGHTNESS_PIN, OUTPUT);
    pinMode(GROW_LIGHT_BRIGHTNESS_PIN, OUTPUT);
    pinMode(GROW_LIGHT_ON_OFF_PIN, OUTPUT);
    pinMode(DIM_PIN, INPUT_PULLUP);)

void setup()
{
    System.set(SYSTEM_CONFIG_SOFTAP_PREFIX, "TomatoTent");

    System.on(setup_begin, setup_handler);
    System.on(setup_end, setup_finished_handler);

    WiFi.setHostname("TomatoTent-" + System.deviceID());

    if (WiFi.hasCredentials()) {
        Particle.connect();
    } else {
        WiFi.off();
    }

    // Time.zone(+8);

    screenManager.setup();
    screenManager.homeScreen();
    tent.setup();

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
