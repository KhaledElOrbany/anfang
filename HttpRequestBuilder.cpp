#include "HttpRequestBuilder.h"

void sendHttpRequest(const char* path, const char* type, HttpHeader headers[], int headerCount, String body = "") {
  WiFiClient client;
  HTTPClient http;

  // Construct the full URL
  String url = String(BASE_URL) + String(path);

  // Begin the HTTP connection
  http.begin(client, url);

  // Add headers
  for (int i = 0; i < headerCount; i++) {
    http.addHeader(headers[i].key, headers[i].value);
  }

  if (!body.isEmpty()) {
    Serial.println("body: " + body);
  }

  // Send request based on type
  int httpCode;
  if (strcmp(type, "POST") == 0) {
    httpCode = http.POST(body);
  } else if (strcmp(type, "PUT") == 0) {
    httpCode = http.PUT(body);
  } else if (strcmp(type, "PATCH") == 0) {
    httpCode = http.PATCH(body);
  } else if (strcmp(type, "DELETE") == 0) {
    httpCode = http.sendRequest("DELETE", body);
  } else {
    httpCode = http.GET();
  }

  // Check the returning code
  if (httpCode > 0) {
    String payload = http.getString();
    Serial.println(httpCode);
    Serial.println(payload);
  } else {
    Serial.printf("Error in HTTP request: %s\n", http.errorToString(httpCode).c_str());
  }

  // End the connection
  http.end();
}