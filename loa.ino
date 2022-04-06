#define PI 3.1412

int led = 13;
int sensor = 2;
int state = LOW;
int val = 0;

int BUZZER = 4;
int TMP36 = 0;

int toneValue = 0;
int digitalValue = 0;

float temp = 0;
float voltValue = 0;
float sinValue = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(BUZZER, OUTPUT);
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(sensor);  
  if (val = HIGH) {
         Serial.println("Anything.... ");
        for (int x = 0; x < 180; x++) {
        sinValue = (sin(x * ( PI / 180 )));
        toneValue =  2000 + (int(sinValue * 1000));
        tone(BUZZER, toneValue);
        delay(2);
       }
  }
    else {
      Serial.println("No ");
      noTone(BUZZER);
     } 
  }
