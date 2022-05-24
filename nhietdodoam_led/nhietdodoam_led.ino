
#include "DHT.h"
#define DHTPin 4
#define DHTType DHT11

int BUZZER = 8;
DHT HT(DHTPin, DHTType);

float humidity;
float temperatureC;
float temperatureF;

void setup() {
  Serial.begin(9600);
  HT.begin();
  delay(1000);
}

void loop() {
  delay(2000);
  humidity = HT.readHumidity();
  temperatureC = HT.readTemperature();
  temperatureF = HT.readTemperature(true);
  
  if (temperatureC > 30) {
    digitalWrite(13, HIGH);
   } else {
    digitalWrite(13, LOW);
   }

  Serial.print("Humdity :");
  Serial.print(humidity);
  Serial.print(", Temperature : ");
  Serial.print(temperatureC);
  Serial.print("oC ~");
  Serial.print(temperatureF);
  Serial.print("oF ~\n");
}
