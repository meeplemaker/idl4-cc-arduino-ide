#include <UIPEthernet.h>
#include "PubSubClient.h"

#define CLIENT_ID       "Nano"
#define INTERVAL        3000 // 3 sec delay between publishing
uint8_t mac[6] = {0x00,0x01,0x02,0x03,0x04,0x05};

EthernetClient ethClient;
PubSubClient mqttClient;

long previousMillis;

void setup() {
  // setup serial communication
  Serial.begin(9600);
  // setup ethernet communication using DHCP
  if(Ethernet.begin(mac) == 0) {
    Serial.println(F("Ethernet configuration using DHCP failed"));
    for(;;);
  }
  // setup mqtt client
  mqttClient.setClient(ethClient);
  mqttClient.setServer("themotherpi.local",1883);
  Serial.println("MQTT client configured");

  previousMillis = millis();
}

void loop() {
 if(millis() - previousMillis > INTERVAL) {
    sendData();
    previousMillis = millis();
  }
  mqttClient.loop();
}

void sendData() {
  if(mqttClient.connect(CLIENT_ID)) {
     mqttClient.publish("TEST", "data");
     Serial.println("test");
  }
  
}
