// DHT
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);

#include "MCS.h"

#define DeviceId ""
#define DeviceKey  ""

MCSDevice mcs(DeviceId, DeviceKey);

MCSControllerFloat tempCon("TemperatureControl");
MCSDisplayFloat tempDis("TemperatureDisplay");

#include <LWiFi.h>
#include <LBLE.h>
#include <LBLEPeriphral.h>

bool _wasConnected;
String _ssidString;
String _passString;

// OLED
#include <Wire.h>  //載入I2C函式庫
#include <SeeedOLED.h> //載入SeeedOLED函式庫

LBLEService _periphralService("D709A00C-DA1A-4726-A33D-CF62B8F4C3D6");

LBLECharacteristicString _ssidRead("61DE21BC-6E02-4631-A0A7-1B6C7AF0DAEE", LBLE_WRITE);
LBLECharacteristicString _passRead("B882467F-77BC-4697-9A4A-4F3366BC6C35", LBLE_WRITE);

void connectMCS(){
  while (!mcs.connected()) {
    mcs.connect();
    if (mcs.connected()) { Serial.println("MCS 已重新連線"); }
  }
  mcs.process(100);

  if(tempCon.updated())
  {
    Serial.print("Temperature updated, new value = ");
    Serial.println(tempCon.value());
  }
  
  float temperature = dht.readTemperature();
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
  
  delay(5000);

}

void connectWiFi(const String ssidString, const String passString)
{
  if (ssidString.length()) {
        const int ssidLen = ssidString.length() + 1;
        const int passLen = passString.length() + 1;
        char ssidCString[ssidLen];
        char passCString[passLen];
        ssidString.toCharArray(ssidCString, ssidLen);
        passString.toCharArray(passCString, passLen);
        
        Serial.print("Connecting to: [");
        Serial.print(String(ssidCString));
        if (passString.length()) {
            Serial.print("] [");
            Serial.print(String(passCString));
        }
        Serial.println("]");
        if (passString.length()) {
            WiFi.begin(ssidCString, passCString);
        } else {
            WiFi.begin(ssidCString);
        }
    }
}

void setup()
{
    Serial.begin(9600);
    LBLE.begin();
    dht.begin();

    mcs.addChannel(tempCon);
    mcs.addChannel(tempDis);
    
    while (!LBLE.ready()) {
      delay(100); 
    }
    _periphralService.addAttribute(_ssidRead);
    _periphralService.addAttribute(_passRead);
    LBLEPeripheral.addService(_periphralService);
    LBLEPeripheral.begin();
    LBLEAdvertisementData _advertisement;
    _advertisement.configAsConnectableDevice("LinkIt 7697");
    LBLEPeripheral.advertise(_advertisement);
    Serial.println("BLE Ready!");

    // OLED
    Wire.begin();
    SeeedOled.init();  
    SeeedOled.clearDisplay();  //清除螢幕
}

void loop()
{
    delay(1000);
    if (_ssidRead.isWritten()) {
        WiFi.disconnect();
        _wasConnected = false;
        _ssidString = _ssidRead.getValue();
        _passString = "";
        Serial.print("New SSID: ");
        Serial.println(_ssidString);
    }
    if (_passRead.isWritten()) {
        WiFi.disconnect();
        _wasConnected = false;
        _passString = _passRead.getValue();
        Serial.print("New Password: ");
        Serial.println(_passString);
        connectWiFi(_ssidString, _passString);
    }
    if (_ssidString.length() &&
      WiFi.status() != WL_CONNECTED) {
      Serial.print("Connecting Status: ");
      Serial.println(WiFi.status());
        connectWiFi(_ssidString, _passString);
    } else if (WiFi.status() == WL_CONNECTED &&
               !_wasConnected) {
      _wasConnected = true;
      Serial.print("Connected to: ");
      Serial.println(_ssidString);
    } else if (WiFi.status() == WL_CONNECTED){
      Serial.println("WL_CONNECTED11");
      connectMCS();
    }
}
