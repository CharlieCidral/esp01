#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char* ssid = "NET_9756C7";
const char* password = "H2t46@-_ul67";
const char* host = "192.168.0.28"; // IP address of your computer
unsigned int port = 4210;  // local port to listen on

WiFiUDP udp;

#define TOUCH_PIN_2 2 // GPIO0 for the first capacitive touch sensor
#define TOUCH_PIN_3 3 // GPIO2 for the second capacitive touch sensor

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Serial.println();
  // Serial.println("Connecting to WiFi");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    // Serial.print(".");
  }
  // Serial.println("WiFi connected");
  // Serial.println("IP address: ");
  // Serial.println(WiFi.localIP());

  pinMode(TOUCH_PIN_2, INPUT);
  pinMode(TOUCH_PIN_3, INPUT);
}

void loop() {

  int touchDig2 = digitalRead(TOUCH_PIN_2);
  int touchDig3 = digitalRead(TOUCH_PIN_3);

  Serial.println("touchDig2: ");
  Serial.println(touchDig2);
  Serial.println("touchDig3: ");
  Serial.println(touchDig3);

  if (touchDig2 > 0) {
    sendUDP("HIGH2: ");
  } 

  delay(1000);
}

void sendUDP(String message) {
  udp.beginPacket(host, port);
  udp.print(message);
  udp.endPacket();
}
