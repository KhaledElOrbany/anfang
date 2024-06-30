#ifndef WIFI_CONNECTOR_H
#define WIFI_CONNECTOR_H

#include "config.h"
#include <Arduino.h>
#include <ESP8266WiFi.h>

void connect();
String getMacAddress();

#endif