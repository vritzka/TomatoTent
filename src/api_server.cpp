#include "Particle.h"
#define WEBDUINO_FAVICON_DATA ""
#define WEBDUINO_SUPRESS_SERVER_HEADER
#include <WebServer.h>
#include "api_server.h"
#include "tent.h"
#include "screen_manager.h"
#include <ArduinoJson.h>

extern Tent tent;
extern ScreenManager screenManager;
extern uint16_t __system_product_version;

// no-cost stream operator as described at
// http://sundial.org/arduino/?page_id=119
template <class T>
inline Print& operator<<(Print& obj, T arg)
{
    obj.print(arg);
    Particle.process();
    return obj;
}

void defaultCmd(WebServer& server, WebServer::ConnectionType type, char* url_tail, bool tail_complete)
{
    server.httpSuccess("text/html; charset=utf-8");
    server << R"(<!doctype html>
<html lang="en">
<head>
    <title>TomatoTent</title>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/css/bootstrap.min.css" integrity="sha384-Vkoo8x4CGsO3+Hhxv8T/Q5PaXtkKtu6ug5TOeNV6gBiFeWPGFN9MuhOf23Q9Ifjh" crossorigin="anonymous">
</head>
<body>
<div class="container-fluid" style="padding-top: 1em">
    <h2>)"
           << "\xF0\x9F\x8D\x85"
           << R"( TomatoTent</h2>
    <ul>
        <li>View <a href="https://my.tomatotent.com/graphs/)"
           << System.deviceID() << R"(">graphs</a> for your current grow</li>
        <li>Collect <a href="/metrics">metrics</a> for custom monitoring and alerting</li>
        <li>Explore the <a href="/api">API</a> for home automation</li>
    </ul>
</div>
</body>
</html>)";
}

void apiCmd(WebServer& server, WebServer::ConnectionType type, char* url_tail, bool tail_complete)
{
    switch (type) {
    case WebServer::GET: {
        server.httpSuccess("text/plain");
        server << "GET /api/info - Get system information about this device\n";
        server << "GET /api/fan - Get fan mode and speed\n";
        server << "PUT /api/fan - Set fan mode and speed\n";
        break;
    }
    }
}

void apiInfoCmd(WebServer& server, WebServer::ConnectionType type, char* url_tail, bool tail_complete)
{
    const int capa = JSON_OBJECT_SIZE(2) + 40;
    switch (type) {
    case WebServer::GET: {
        StaticJsonDocument<capa> json;
        json["device_id"] = System.deviceID();
        json["version"] = __system_product_version;
        server.httpSuccess();
        serializeJson(json, server);
        break;
    }
    }
}

void apiFanCmd(WebServer& server, WebServer::ConnectionType type, char* url_tail, bool tail_complete)
{
    const int capa = JSON_OBJECT_SIZE(2) + 21;
    switch (type) {
    case WebServer::GET: {
        StaticJsonDocument<capa> json;
        json["mode"] = tent.state.getClimateAutoMode() ? "automatic" : "manual";
        json["speed"] = tent.state.getFanSpeed();
        server.httpSuccess();
        serializeJson(json, server);
        break;
    }
    case WebServer::PUT: {
        StaticJsonDocument<capa> json;
        deserializeJson(json, server);
        if (json["mode"] == "automatic") {
            tent.state.setClimateAutoMode(true);
        } else if (json["mode"] == "manual") {
            tent.state.setClimateAutoMode(false);
            int speed = json["speed"];
            if (speed > 0 && speed <= 100) {
                tent.state.setFanSpeed(speed);
            }
        }
        tent.adjustFan();
        screenManager.markNeedsRedraw(FAN);
        server.httpSeeOther("/api/fan");
        break;
    }
    }
}

void metricsCmd(WebServer& server, WebServer::ConnectionType type, char* url_tail, bool tail_complete)
{
    server.httpSuccess("text/plain; version=0.0.4; charset=utf-8");

    if (tent.rawSensors.tentTemperature != -1) {
        server << "# HELP tomatotent_air_temperature The temperature of the air in Celsius\n";
        server << "# TYPE tomatotent_air_temperature gauge\n";
        server << "tomatotent_air_temperature " << tent.rawSensors.tentTemperature << "\n";
    }

    if (tent.rawSensors.tentHumidity != -1) {
        server << "# HELP tomatotent_air_humidity The relative humidity of the air\n";
        server << "# TYPE tomatotent_air_humidity gauge\n";
        server << "tomatotent_air_humidity " << tent.rawSensors.tentHumidity << "\n";
    }

    if (tent.rawSensors.soilTemperature != -1) {
        server << "# HELP tomatotent_soil_temperature The temperature of the soil in Celsius\n";
        server << "# TYPE tomatotent_soil_temperature gauge\n";
        server << "tomatotent_soil_temperature " << tent.rawSensors.soilTemperature << "\n";
    }

    if (tent.rawSensors.soilMoisture != -1) {
        server << "# HELP tomatotent_soil_moisture The moisture level in the soil\n";
        server << "# TYPE tomatotent_soil_moisture gauge\n";
        server << "tomatotent_soil_moisture " << tent.sensors.waterLevel << "\n";

        server << "# HELP tomatotent_soil_capacitance The capacitance level of the moisture sensor in the soil\n";
        server << "# TYPE tomatotent_soil_capacitance gauge\n";
        server << "tomatotent_soil_capacitance " << tent.rawSensors.soilMoisture << "\n";
    }

    if (tent.state.getDayCount() != -1) {
        server << "# HELP tomatotent_grow_days How many days since the grow started?\n";
        server << "# TYPE tomatotent_grow_days gauge\n";
        server << "tomatotent_grow_days " << tent.state.getDayCount() << "\n";

        server << "# HELP tomatotent_light_on Is it daylight in the tent?\n";
        server << "# TYPE tomatotent_light_on gauge\n";
        server << "tomatotent_light_on " << tent.rawSensors.lightBrightness << "\n";

        server << "# HELP tomatotent_light_period How many minutes of daylight in the tent?\n";
        server << "# TYPE tomatotent_light_period gauge\n";
        server << "tomatotent_light_period " << tent.state.getDayDuration() << "\n";

        server << "# HELP tomatotent_period_progress How many minutes into the current photoperiod?\n";
        server << "# TYPE tomatotent_period_progress gauge\n";
        server << "tomatotent_period_progress " << tent.state.getMinutesInPhotoperiod() << "\n";

        server << "# HELP tomatotent_fan_auto Is the fan running in automatic mode?\n";
        server << "# TYPE tomatotent_fan_auto gauge\n";
        server << "tomatotent_fan_auto " << (tent.state.getClimateAutoMode() ? 1 : 0) << "\n";

        server << "# HELP tomatotent_fan_speed Speed of the fan\n";
        server << "# TYPE tomatotent_fan_speed gauge\n";
        server << "tomatotent_fan_speed " << (tent.state.getFanSpeed()) << "\n";
    }
}

void ApiServer::begin()
{
    WebServer::begin();

    setDefaultCommand(&defaultCmd);
    addCommand("api", &apiCmd);
    addCommand("api/info", &apiInfoCmd);
    addCommand("api/fan", &apiFanCmd);
    addCommand("metrics", &metricsCmd);
}
