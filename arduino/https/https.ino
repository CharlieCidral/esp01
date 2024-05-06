#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

const char* ssid = "NET_9756C7";
const char* password = "H2t46@-_ul67";
const char* host = "192.168.0.1";
const int httpsPort = 4210;

void setup() {
  Serial.begin(115200);
  delay(10);

  Serial.println("Conectando ao WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Conectado ao WiFi");

  WiFiClientSecure client;
  Serial.print("Conectando ao servidor HTTPS...");
  if (!client.connect(host, httpsPort)) {
    Serial.println("Falha na conexão");
    return;
  }
  Serial.println("Conectado");

  String url = "/"; // Especifique a URL que deseja acessar no servidor HTTPS
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");
  Serial.println("Requisição enviada");
}

void loop() {

}
