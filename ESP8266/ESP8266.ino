#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include "Wire.h"
#include "html.h"

#define D1 4
#define D2 5
const char* ssid     = "D205";      //Thay tên wifi ở đây
const char* password = "20152018";  //Thay tên password ở đây

ESP8266WebServer server(80);

String data = "";
String test = "1234567890.,";

void ketnoi() {
  String s = MAIN_page;
  server.send(200, "text/html", s);
}

void getData() {
  Wire.beginTransmission(8);
  Wire.endTransmission();
  Wire.requestFrom(8, 13);
  data = "";
  while (Wire.available()) {
    char c = (char)Wire.read();
    if (test.indexOf(String(c)) >= 0) {
      data += String(c);
    }
  }

  Serial.println(data);
  if (data == "") {
    server.send(200, "text/plane", "Cảm biến không hoạt động");
  } else {
    server.send(200, "text/plane", data);
  }
}

void ledon() {
  Wire.beginTransmission(8);
  Wire.write("on");
  Wire.endTransmission();
}
void ledoff() {
  Wire.beginTransmission(8);
  Wire.write("off");
  Wire.endTransmission();
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Wire.begin(D1, D2);
  delay(10);
  Serial.print("Connecting...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
  server.begin();
  Serial.println("Server started");
  Serial.print("IP Address of network: "); // will IP address on Serial Monitor
  Serial.println(WiFi.localIP());
  Serial.print("Copy and paste the following URL: http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

  server.on("/", ketnoi);
  server.on("/getData", getData);
  server.on("/ON", ledon);
  server.on("/OFF", ledoff);
}

void loop() {
  server.handleClient();
}
