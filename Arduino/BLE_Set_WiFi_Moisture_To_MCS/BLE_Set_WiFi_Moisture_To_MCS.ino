// Moisture
#define MoisturePin A0 

#include "MCS.h"

#define DeviceId ""
#define DeviceKey  ""

MCSDevice mcs(DeviceId, DeviceKey);

MCSDisplayFloat tempDis("TemperatureDisplay");

#include <LWiFi.h>
#include <LBLE.h>
#include <LBLEPeriphral.h>

bool _wasConnected;
String _ssidString;
String _passString;
LBLEService _periphralService("D709A00C-DA1A-4726-A33D-CF62B8F4C3D6");

LBLECharacteristicString _ssidRead("61DE21BC-6E02-4631-A0A7-1B6C7AF0DAEE", LBLE_WRITE);
LBLECharacteristicString _passRead("B882467F-77BC-4697-9A4A-4F3366BC6C35", LBLE_WRITE);

void connectMCS(){
  while (!mcs.connected()) {
    mcs.connect();
    if (mcs.connected()) { Serial.println("MCS 已重新連線"); }
  }
  mcs.process(100);
        
  float moistureVal = analogRead(MoisturePin);
  Serial.println(moistureVal);  
  tempDis.set(moistureVal);  
       
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
