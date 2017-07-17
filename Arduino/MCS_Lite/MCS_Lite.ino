// DHT
#include "DHT.h"
#define DHTPIN A0      
#define DHTTYPE DHT22  

DHT dht(DHTPIN,DHTTYPE);

// WIFI
#include <LWiFi.h>
#include <HttpClient.h>

char ssid[] = "Input SSID";
char pass[] = "Input Password"; 
#define WIFI_AUTH LWIFI_WPA 
#define deviceId "Input DeviceID" 
#define deviceKey "Input DeviceKey" 
#define server "Input Server IP" 
int rs_port = 3000;
String content; 
WiFiClient rs_client; 
int status = WL_IDLE_STATUS;

void setup() 
{
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.println("Booting....");
 
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    while (true);
  }

  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);
  }

  // you're connected now, so print out the data:
  Serial.print("You're connected to the network");
}

void loop() 
{
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  String uploadHumidity = "Humidity,,";
  String humiString = uploadHumidity + String(int(humidity)) + "." + String(getDecimal(humidity));
  String uploadTemperature = "Temperature,,";
  String tempString = uploadTemperature + String(int(temperature)) + "." + String(getDecimal(temperature));
  String uploadData =  humiString + "\n" +
                       tempString + "\n";
  Serial.println(humiString);    
  Serial.println(tempString);                 
  //String data = "Temperature,,111";
  upload_datapoint(uploadData);
  delay(5000);
}

void upload_datapoint(String content) {
  
  if (rs_client.connect(server, rs_port)) {
    Serial.println("rs_client is built.");
    int thislength = content.length();
    rs_client.print("POST /api/devices/");
    rs_client.print(deviceId);
    rs_client.println("/datapoints.csv HTTP/1.1");
    rs_client.print("Host: ");
    rs_client.print(server);
    rs_client.print(":");
    rs_client.println(3000);
    rs_client.println("Content-Type: text/csv");
    rs_client.print("deviceKey: ");
    rs_client.println(deviceKey);
    rs_client.print("Content-Length: ");
    rs_client.println(thislength);
    rs_client.println();
    rs_client.println(content);
    rs_client.println(); 
    while(!rs_client.available())
    {
      delay(10);
    }
  }
  Serial.println("rs_client is closed.");
  rs_client.stop();
}

long getDecimal(float val)
{
 int intPart = int(val);
 long decPart = 100 *(val-intPart);                       
 if(decPart>0)return(decPart);           
 else if(decPart<0)return((-1)*decPart); 
 else if(decPart=0)return(00);           
}
