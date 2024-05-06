#include <ESP8266WiFi.h>

const char* ssid = "NET_9756C7";
const char* password = "H2t46@-_ul67";
const char* host = "192.168.0.28"; // Endereço IP do servidor Python
unsigned int port = 4210; // Porta do servidor

WiFiClient client;

#define TOUCH_PIN_2 2 // GPIO2 for the first capacitive touch sensor
#define TOUCH_PIN_3 3 // GPIO0 for the second capacitive touch sensor

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }

  Serial.println("Conectado ao Wi-Fi");
  Serial.print("IP local: ");
  Serial.println(WiFi.localIP());

  pinMode(TOUCH_PIN_2, INPUT);
  pinMode(TOUCH_PIN_3, INPUT);
}

void loop() {
  if (!client.connected()) {
    if (client.connect(host, port)) {
      Serial.println("Conectado ao servidor Python");
    } else {
      Serial.println("Falha na conexão com o servidor");
    }
  }

  int touchDig2 = digitalRead(TOUCH_PIN_2);
  int touchDig3 = digitalRead(TOUCH_PIN_3);

  Serial.println("touchDig2: ");
  Serial.println(touchDig2);
  Serial.println("touchDig3: ");
  Serial.println(touchDig3);

  if (client.connected()) {
    // client.println("GET / HTTP/1.1");
    // client.println("Host0: " + String(host));
    client.println();
    if (touchDig2 > 0) {
      client.println("HIGH2: ");
    } else {
      client.println("LOW2: ");
    }
    client.println();
    if (touchDig3 > 0) {
      client.println("HIGH3: ");
    } else {
      client.println("LOW3: ");
    }
  }

  delay(1000); // Aguarde um tempo antes de enviar mais dados
}
