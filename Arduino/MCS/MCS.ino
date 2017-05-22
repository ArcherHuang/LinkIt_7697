// DHT
#include "DHT.h"
#define DHTPIN A0      
#define DHTTYPE DHT22  

DHT dht(DHTPIN,DHTTYPE);

// WIFI

#include <LWiFi.h>
#include <HttpClient.h>

char ssid[] = "ArcherGo";      //  your network SSID (name)
char pass[] = "nhfb8820";  // your network password (use for WPA, or use as key for WEP)
#define WIFI_AUTH LWIFI_WPA //the kind of authority of my wifi which is WPA2
#define DEVICEID "Dc0Y0gNb" //the device id given by cloud sandbox
#define DEVICEKEY "5Y5k5LneAqMpA923" //the device key given by cloud sandbox
#define SITE_URL "api.mediatek.com" //the site of the API 

WiFiClient client;
WiFiClient rs_client;
int status = WL_IDLE_STATUS;
int rs_port = 80;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.println("Booting....");
 
  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue:
    while (true);
  }

  String fv = WiFi.firmwareVersion();
  Serial.print("WiFi firmware version: ");
  Serial.println(fv); 
  if (fv != "1.1.0") {
    Serial.println("Please upgrade the firmware");
  }

  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(10000);
  }
  
  Serial.println("Connected to wifi");
  dht.begin();
  
}

void loop() {
  // put your main code here, to run repeatedly:

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

void upload_datapoint(String content) 
{
  
  if (rs_client.connect(SITE_URL, rs_port)) {
    Serial.println("rs_client is built.");
    int thislength = content.length();
    rs_client.print("POST /mcs/v2/devices/");
    rs_client.print(DEVICEID);
    rs_client.println("/datapoints.csv HTTP/1.1");
    rs_client.print("Host: ");
    rs_client.print(SITE_URL);
    rs_client.print(":");
    rs_client.println(3000);
    rs_client.println("Content-Type: text/csv");
    rs_client.print("deviceKey: ");
    rs_client.println(DEVICEKEY);
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

//function to extract decimal part of float
long getDecimal(float val)
{
 int intPart = int(val);
 long decPart = 100 *(val-intPart);                       
 if(decPart>0)return(decPart);           
 else if(decPart<0)return((-1)*decPart); 
 else if(decPart=0)return(00);           
}

