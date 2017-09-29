#include <LWiFi.h>
#include <WiFiClient.h>
#include "MCS.h"

// DHT
#include "DHT.h"
#define DHTPIN 2      
#define DHTTYPE DHT11  

DHT dht(DHTPIN,DHTTYPE);

// OLED
#include <Wire.h>  //載入I2C函式庫
#include <SeeedOLED.h> //載入SeeedOLED函式庫

#define _SSID ""
#define _KEY  ""

MCSDevice mcs("DeviceId", "DeviceKey");

MCSControllerFloat tempCon("TemperatureControl");
MCSDisplayFloat tempDis("TemperatureDisplay");

void setup() {
  // setup Serial output at 9600
  Serial.begin(9600);
  dht.begin();
  
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

  // OLED
  Wire.begin();
  SeeedOled.init();  
  SeeedOled.clearDisplay();  //清除螢幕
}

void loop() {

  mcs.process(100);
  
  if(tempCon.updated())
  {
    Serial.print("Temperature updated, new value = ");
    Serial.println(tempCon.value());
  }

  float temperature = dht.readTemperature();
  Serial.print("Original Temperature: ");
  Serial.println(temperature);

  float newTemperature = temperature+tempCon.value();
  Serial.print("New Temperature: ");
  Serial.println(newTemperature);
  tempDis.set(newTemperature);

  // OLED
  SeeedOled.setTextXY(0,0); //設定啟始坐標
  SeeedOled.putString("Ori Temp: "); 
  SeeedOled.putNumber(temperature); 
  SeeedOled.putString(" *C"); 
  SeeedOled.setTextXY(1,0); //設定啟始坐標
  SeeedOled.putString("New Temp: "); 
  SeeedOled.putNumber(newTemperature); 
  SeeedOled.putString(" *C");
  
  // check if need to re-connect
  while(!mcs.connected())
  {
    Serial.println("re-connect to MCS...");
    mcs.connect();
    if(mcs.connected())
      Serial.println("MCS connected !!");
  }

  delay(5000);
}
