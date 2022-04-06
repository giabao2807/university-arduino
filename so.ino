#include <OneWire.h> 
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 2 
#define BUZZER 4
int toneValue = 0;
float sinValue = 0;
unsigned long tepTimer = 0; 
OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensors(&oneWire);
void setup(void) 
{ 
 // start serial port 
 Serial.begin(9600); 
 Serial.println("Viet temp Demo"); 
 sensors.begin(); 
 pinMode(BUZZER, OUTPUT);
 //pinMode(ONE_WIRE_BUS, INPUT);
} 
void loop(void) 
{ 
 Serial.print(" Requesting temperatures..."); 
 sensors.requestTemperatures();
 Serial.println("DONE"); 
 Serial.print("Temperature is: "); 
 float temp = sensors.getTempCByIndex(0);
 Serial.print(temp); 
   delay(1000); 
   if (temp > 29) {
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
} 
