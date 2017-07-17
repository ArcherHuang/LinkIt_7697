// DHT
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();
      
  Serial.print("DHT-Humidity: "); 
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("DHT-Temperature: "); 
  Serial.print(t);
  Serial.println(" *C\t");
        
  delay(1000); //每秒回傳一次資料
}
