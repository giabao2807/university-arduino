
#include <Servo.h>
Servo myServo;
int potpin = 0;
int sensor = 2;
int state = LOW;
int val = 0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT);
  Serial.begin(9600);
  myServo.attach(9);
}

void loop() {
  val = digitalRead(sensor);  
  if (val == HIGH) {
    delay(100);
    myServo.write(90);
    delay(5000);
    myServo.write(-90);
    
    if (state == LOW) {
      Serial.println("detect motivation");
      state = HIGH;
    }
  }
    else {
      delay(100);
      if (state == HIGH) {
        Serial.println("No motivation");
        state = LOW;
     }
  }
}
