#ifndef HTTP_REQUEST_BUILDER_H
#define HTTP_REQUEST_BUILDER_H

#include "config.h"
#include <Arduino.h>
#include <ESP8266HTTPClient.h>

struct HttpHeader {
  String key;
  String value;
};

void sendHttpRequest(const char*, const char*, HttpHeader[], int, String);

#endif
