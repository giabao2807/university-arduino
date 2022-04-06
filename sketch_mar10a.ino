
#include "DHT.h"
#define DHTPin 4
#define DHTType DHT11
DHT HT(DHTPin, DHTType);

float humidity;
float temperatureC;
float temperatureF;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Serial.println("Type,\tstatus,\tHumidity(%),\tTemperature(C)");
  HT.begin();
  delay(1000);
}

void loop() {
  delay(2000);
  humidity = HT.readHumidity();
  temperatureC = HT.readTemperature();
  temperatureF = HT.readTemperature(true);

  Serial.print("Humdity :");
  Serial.print(humidity);
  Serial.print(", Temperature : ");
  Serial.print(temperatureC);
  Serial.print("oC ~");
  Serial.print(temperatureF);
  Serial.print("oF ~ \n");
}
