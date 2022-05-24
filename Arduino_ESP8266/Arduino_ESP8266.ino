#include "Wire.h"

#include <DHT.h>
#define DHTPin 4
#define DHTType DHT11
DHT HT(DHTPin, DHTType);
float humidity;
float temperatureC;
char* temp;
String data= "";
String led = "";
bool on = false;


void receiveEvent(int howMany) {
  Serial.println("receiveEvent");
  led = "";
  while (0 < Wire.available()) {
    char c = (char)Wire.read();      /* receive byte as a character */
    led += String(c);
    Serial.print(c);           /* print the character */
  }
  Serial.println(led);
  if(led == "on"){
    on = true;
  }else if(led == "off"){
    on = false;
  }
}

void requestEvent() {
  Serial.println("receiveEvent");
  data =  String(humidity) + "," + String(temperatureC);
  char temp[data.length()];
  data.toCharArray(temp, data.length());
  Wire.write(temp);  /*send string on request */
}


void setup() {
  HT.begin();
  pinMode(13,OUTPUT);
  Serial.begin(115200);
  Serial.println("Starting ...");
  Wire.begin(8);
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
}

void loop() {
  delay(100);
  humidity = HT.readHumidity();
  temperatureC = HT.readTemperature();

  Serial.print("Humdity :");
  Serial.print(humidity);
  Serial.print(", Temperature : ");
  Serial.print(temperatureC);
  Serial.print("oC ~");
  Serial.println();
  
  if(on == true){
    digitalWrite(13,HIGH);
  }else{
    digitalWrite(13,LOW);
  }
}
