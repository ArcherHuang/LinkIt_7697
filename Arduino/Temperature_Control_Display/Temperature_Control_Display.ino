#include <LWiFi.h>
#include <WiFiClient.h>
#include "MCS.h"

#define _SSID ""
#define _KEY  ""

MCSDevice mcs("DeviceId", "DeviceKey");

MCSControllerFloat tempCon("TemperatureControl");
MCSDisplayFloat tempDis("TemperatureDisplay");

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
  mcs.addChannel(tempCon);
  mcs.addChannel(tempDis);
  
  while(!mcs.connected())
  {
    Serial.println("MCS.connect()...");
    mcs.connect();
  }
  Serial.println("MCS connected !!");

  // read LED value from MCS server
  while(!tempCon.valid())
  {
    Serial.println("read tempCon value from MCS...");
    tempCon.value();
  }
}

void loop() {

  mcs.process(100);
  
  if(tempCon.updated())
  {
    Serial.print("Temperature updated, new value = ");
    Serial.println(tempCon.value());
    tempDis.set(tempCon.value());
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
