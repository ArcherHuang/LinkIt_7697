#include <LWiFi.h>
#include <WiFiClient.h>
#include "MCS.h"

#define _SSID ""
#define _KEY  ""

MCSDevice mcs("DeviceId", "DeviceKey");

MCSControllerFloat temp("Temperature");

void setup() {
  // setup Serial output at 9600
  Serial.begin(9600);

  // setup Wifi connection
  while(WL_CONNECTED != WiFi.status())
  {
    Serial.print("WiFi.begin(");
    Serial.print(_SSID);
    Serial.print(",");
    Serial.print(_KEY);
    Serial.println(")...");
    WiFi.begin(_SSID, _KEY);
  }
  Serial.println("WiFi connected !!");

  // setup MCS connection
  mcs.addChannel(temp);
  while(!mcs.connected())
  {
    Serial.println("MCS.connect()...");
    mcs.connect();
  }
  Serial.println("MCS connected !!");

  // read LED value from MCS server
  while(!temp.valid())
  {
    Serial.println("read temp value from MCS...");
    temp.value();
  }
}

void loop() {

  mcs.process(100);
  
  if(temp.updated())
  {
    Serial.print("Temperature updated, new value = ");
    Serial.println(temp.value());
  }
  
  // check if need to re-connect
  while(!mcs.connected())
  {
    Serial.println("re-connect to MCS...");
    mcs.connect();
    if(mcs.connected())
      Serial.println("MCS connected !!");
  }
}
