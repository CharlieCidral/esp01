#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "NET_9756C7";
const char* password = "H2t46@-_ul67";
const char* serverAddress = "192.168.0.28"; // IP address of your computer running the Python script
const int serverPort = 80; // Port on which your Python server is running

WiFiClient client;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    // Your data to send
    String dataToSend = "Hello from ESP8266!";

    // Construct the URL
    String url = "http://" + String(serverAddress) + ":" + String(serverPort) + "/data";

    http.begin(client, url);
    http.addHeader("Content-Type", "text/plain");

    int httpResponseCode = http.POST(dataToSend);

    if (httpResponseCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
    } else {
      Serial.print("Error on sending POST: ");
      Serial.println(httpResponseCode);
    }

    http.end();
  }
  delay(5000); // Send data every 5 seconds
}
