#include <Arduino.h>
#include <wifi/wifi.h>
#include <ESP8266WiFi.h>
#include <iostream>
#include "mqtt/mqtt.h"

// pin sensor
int sensorPin = A0;
int digitalPin = D1;

int level = 0; // start level

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  wifiConnect();                  // Wifi Connection
  mqttConnect();                  // MQTT Setup
  pinMode(digitalPin, OUTPUT);
  digitalWrite(digitalPin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(digitalPin, HIGH);
  delay(1000);
  level = analogRead(sensorPin);
  digitalWrite(digitalPin, LOW);
  Serial.print("Level of water: ");
  Serial.println(level);


  // Verify internet connection to publish the reads
  if (WiFi.status() == WL_CONNECTED)
  {
    mqttPublish(level);                           // MQTT Publish
    
  }
  else
  {
    wifiReconnect();                              // Wifi Reconnect
    if (WiFi.status() == WL_CONNECTED)
    {
      mqttPublish(level);                         // MQTT Publish
    }
  }

  delay(10000);
  wifiReconnect();                                // Wifi Reconnect
}
