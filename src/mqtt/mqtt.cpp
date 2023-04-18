#include <Arduino.h>            // Main Arduino Library
#include <ESP8266WiFi.h>        // WiFi Library
#include <PubSubClient.h>       // MQTT Library
#include "mqtt.h"               // MQTT Code 
#include "wifi/wifi.h"          // Wifi Code
#include <string>
using namespace std;


// MQTT Settings
const char *mqtt_username = MQTT_USERNAME;
const char *mqtt_password = MQTT_PASSWD;
const char *mqtt_broker = MQTT_BROKER_SERVER;
const int mqtt_port = MQTT_SERVER_PORT;


PubSubClient client(espClient);


void mqttConnect() {

  // Connecting to a mqtt broker
  client.setServer(mqtt_broker, mqtt_port);
  

  while (!client.connected()) {

      Serial.printf("The client %s is conneting to the MQTT Broker Server\n", espClientMACsimple.c_str());
      if (client.connect(espClientHostname.c_str(), mqtt_username, mqtt_password)) {

      } else {
          Serial.print("Failed with state: ");
          Serial.print(client.state());
          delay(2000);
      }
  }
}


void mqttPublish(int value) {

  // Define MQTT Topic
  String device_topic = "sensors/teste/";
  device_topic.concat(espClientMACsimple);

  // Convert String to char
  int stringLength = device_topic.length() + 1; 
  char characterArray[stringLength];
  device_topic.toCharArray(characterArray, stringLength);

  // Define MQTT Topic to Publish
  char *topic = characterArray;


  // Start a new line
  Serial.println();

  // Convert int to char*
  string str = to_string(value);
  const char* level = str.c_str();

  // print in serial
  Serial.print("Level of water converted: ");
  Serial.print(level);
  Serial.println();

  //Publish the data to the topic
  client.publish(topic, level);
  client.loop();
}