#include <Servo.h>

int led = 13;
int LIGHT = 0;
int val = 0;
int pos =0;

Servo myservo;
const int ServoPin = 9;
const int trigPin = 7;
const int echoPin = 6;
long duration;
int distance;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(ServoPin);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(LIGHT);
  Serial.print("Light's value: ");
  Serial.println(val);

  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin,HIGH);

  distance = duration*0.034/2;
  Serial.print("Distance Measured = ");
  Serial.print(distance);
  Serial.println("cm");

  
  if(val < 700){
    digitalWrite(led, LOW);
    if (distance < 10) {
         myservo.write(90);
         delay(200);
    } else {
        myservo.write(-90);
    }
  } else {
      if (distance < 10) {
         digitalWrite(led, HIGH);
         myservo.write(90);
         delay(200);
    } else {
         digitalWrite(led, LOW);
         myservo.write(-90);
    }
  }
  delay(500);
}
