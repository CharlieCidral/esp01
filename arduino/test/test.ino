#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char* ssid = "NET_9756C7";
const char* password = "H2t46@-_ul67";
const char* host = "192.168.0.28"; // IP address of your computer
const int port = 4210; // Port number to send UDP packets

WiFiUDP udp;

void setup() {
  Serial.begin(115200);
  

  Serial.println();
  Serial.println("Connecting to WiFi");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }

  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Send data via UDP
  sendUDP("Hello from ESP8266!");

  delay(1000); // Wait before sending the next packet
}

void sendUDP(String message) {
  udp.beginPacket(host, port);
  udp.print(message);
  udp.endPacket();
}
