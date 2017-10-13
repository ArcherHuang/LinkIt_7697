#include <LWiFi.h>
#include <PubSubClient.h>

char ssid[] = "";
char password[] = "";
char mqtt_server[] = "mqtt.mcs.mediatek.com";
char pub_topic[] = "mcs/deviceId/deviceKey/dataChnId";
char client_Id[] = "linkit-7697";
 
int status = WL_IDLE_STATUS;

WiFiClient mtclient;     
PubSubClient client(mtclient);

// JSON
String msgStr = "";
char json[79];

void setup() {
    //Initialize serial and wait for port to open:
    Serial.begin(9600);

    setup_wifi();
    client.setServer(mqtt_server, 1883);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  msgStr = "";
  char moisture[75];
  sprintf(moisture, "%d", 102);
  msgStr = msgStr + "{\"datapoints\": [{\"values\": {\"value\":" + moisture + "}, \"dataChnId\":\"Moisture\"}]}";
  msgStr.toCharArray(json, 90);
  Serial.print("Publish message: ");
  Serial.println(json);
  Serial.println(msgStr);
  client.publish(pub_topic, json);
  delay(5000);
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
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

