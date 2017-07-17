// OLED
#include <Wire.h>  //載入I2C函式庫
#include <SeeedOLED.h> //載入SeeedOLED函式庫

// DHT
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  dht.begin();

  // OLED
  Wire.begin();
  SeeedOled.init();  
  SeeedOled.clearDisplay();  //清除螢幕
  SeeedOled.setNormalDisplay(); //設定螢幕為正常模式(非反白)
  SeeedOled.setPageMode();  //設定尋址模式頁模式
  SeeedOled.setTextXY(0,0); //設定啟始坐標
  SeeedOled.putString("Temp & Humi"); 
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

  // OLED
  SeeedOled.setTextXY(1,0); //設定啟始坐標
  SeeedOled.putString("Temp: "); 
  SeeedOled.putNumber(t); 
  SeeedOled.putString(" *C"); 
  SeeedOled.setTextXY(2,0); //設定啟始坐標
  SeeedOled.putString("Humidity: "); 
  SeeedOled.putNumber(h); 
  SeeedOled.putString(" %");
  
  delay(1000); //每秒回傳一次資料
}
