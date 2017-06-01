// DHT
#include "DHT.h"
#define DHTPIN A0      
#define DHTTYPE DHT22  

DHT dht(DHTPIN,DHTTYPE);

// WIFI
#include <LWiFi.h>
#include "MCS.h"

char _lwifi_ssid[] = "";
char _lwifi_pass[] = "";
MCSDevice mcs("DeviceId", "DeviceKey");

MCSDisplayFloat Temperature("Temperature");
MCSDisplayFloat Humidity("Humidity");
void setup()
{
  Serial.begin(9600);

  mcs.addChannel(Temperature);
  mcs.addChannel(Humidity);
  Serial.println("WIFI 連線開始");
  while (WiFi.begin(_lwifi_ssid, _lwifi_pass) != WL_CONNECTED) { delay(1000); }
  Serial.println("WIFI 連線成功");
  Serial.println("MCS 連線開始");
  Serial.println("MCS 連線成功");while(!mcs.connected()) { mcs.connect(); }
  Serial.begin(9600);
}

void loop()
{
  while (!mcs.connected()) {
  mcs.connect();
  if (mcs.connected()) { Serial.println("MCS 已重新連線"); }
  }
  mcs.process(100);
  
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  Serial.println(temperature);    
  Serial.println(humidity); 
  Temperature.set(temperature);
  Humidity.set(humidity);
  delay(5000);
}
