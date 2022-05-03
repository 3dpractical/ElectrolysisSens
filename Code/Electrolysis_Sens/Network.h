#ifndef Network.h
#define Network.h

#include <WiFi.h>
#include <WiFiMulti.h>
#include "Essential.h"
#include <HTTPClient.h>

WiFiMulti wifiMulti;
HTTPClient http;

String payload;
String host = "skripsi.apibrawijaya.com";

uint8_t networkInit() {
  WiFi.begin("iPhone", "asampeke");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    if (++wifiTick >= 10)
      break;
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  return 1;
}

void DB_stream() {
  if ((WiFi.status() == WL_CONNECTED)) {
      http.begin("http://skripsi.apibrawijaya.com/get.php?h2=" +  String(h2) + "&ph=" + String(ph) + "&arus=" + String(amp));
      if (http.GET() && HTTP_CODE_OK) {
        if (http.getString() == "1") {
          Serial.println("Parsing data successful");
        } else {
          Serial.println("Parsing data failed");
        }
      }
    
  } 
  else
    Serial.println("Network error");
}

#endif
