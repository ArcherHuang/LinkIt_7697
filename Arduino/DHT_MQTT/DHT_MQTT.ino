#include <LWiFi.h>
#include <PubSubClient.h>

char ssid[] = "";
char password[] = "";
char mqtt_server[] = "";
char sub_topic[] = "7697 subscribe topic";
char pub_topic[] = "mqtt_test";
char client_Id[] = "7697client-01-";
char pub_msg[] = "hello world!";
 
int status = WL_IDLE_STATUS;

WiFiClient mtclient;     
PubSubClient client(mtclient);
long lastMsg = 0;
char msg[50];
int value = 0;

//DHT
#include "DHT.h"
#define DHTPIN A0 
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// JSON
String msgStr = "";
char json[39];

void setup() {
    //Initialize serial and wait for port to open:

    Serial.begin(9600);
    setup_wifi();
    client.setServer(mqtt_server, 1883);
    client.setCallback(callback);
    Serial.println("DHT11 test!");
    dht.begin();
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  char temp[75];
  sprintf(temp, "%3.2f", t);
  char hum[75];
  sprintf(hum, "%3.2f", h);
  
  msgStr = msgStr + "{\"temperature\":" + t + ",\"humidity\":" + h + "}";
  msgStr.toCharArray(json, 39);

  long now = millis();
  if (now - lastMsg > 2000) {
    lastMsg = now;
    ++value;

    Serial.println("Publish Temperature: ");
    Serial.print(temp);
    
//    client.publish(pub_topic,temp);
    client.publish(pub_topic,json);
    msgStr = "";
    
//    Serial.print("Publish message: ");
//    Serial.println(pub_msg);
//    client.publish(pub_topic, pub_msg);
}
}


void printWifiStatus() {                     //print Wifi status
    // print the SSID of the network you're attached to:
    Serial.print("SSID: ");
    Serial.println(WiFi.SSID());

    // print your WiFi shield's IP address:
    IPAddress ip = WiFi.localIP();
    Serial.print("IP Address: ");
    Serial.println(ip);

    // print the received signal strength:
    long rssi = WiFi.RSSI();
    Serial.print("signal strength (RSSI):");
    Serial.print(rssi);
    Serial.println(" dBm");
}

void setup_wifi() {                       //setup Wifi
   // attempt to connect to Wifi network:
   Serial.print("Attempting to connect to SSID: ");
   Serial.println(ssid);
   WiFi.begin(ssid, password);
   while (WiFi.status() != WL_CONNECTED) {
     delay(500);
     Serial.print(".");
    }
    randomSeed(micros());
    Serial.println("Connected to wifi");
    printWifiStatus();
}

void callback(char* topic, byte* payload, unsigned int length) {   //MQTT sub
  Serial.print("Input Message arrived [");
  Serial.print(sub_topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

void reconnect() {  //reconnect MQTT
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = client_Id;
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish(pub_topic, client_Id);
      // ... and resubscribe
      client.subscribe(sub_topic);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

