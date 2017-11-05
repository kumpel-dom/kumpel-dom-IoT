#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

#include "receive.h"

void setup() {
  connect();
}

void loop() {
  receive();
}