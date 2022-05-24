#include "DHT.h"
#define DHTPin 4
#define DHTType DHT11
#define PI 3.1412

int BUZZER = 8;
DHT HT(DHTPin, DHTType);

float humidity;
float temperatureC;
float temperatureF;
float sinValue = 0;
float voltValue = 0;
int toneValue = 0;

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
  
  if (temperatureC > 30) {
    for (int x = 0; x < 180; x++) {
      sinValue = (sin(x * ( PI / 180 )));
      toneValue =  2000 + (int(sinValue * 1000));
      tone(BUZZER, toneValue);
      delay(2);
    }
  }
  else {
    noTone(BUZZER);
  }

  Serial.print("Humdity :");
  Serial.print(humidity);
  Serial.print(", Temperature : ");
  Serial.print(temperatureC);
  Serial.print("oC ~");
  Serial.print(temperatureF);
  Serial.print("oF ~\n");
}
