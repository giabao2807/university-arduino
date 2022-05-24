#include<Stepper.h>

const int stepsPerRevolution = 2048;
int led_yellow = 13;
int led_red = 12;

Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);


void setup() {
  // put your setup code here, to run once:
  pinMode(led_yellow,OUTPUT);
  pinMode(led_red,OUTPUT);

  myStepper.setSpeed(15);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  myStepper.setSpeed(15);
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  digitalWrite(led_yellow,HIGH);
  delay(500);
  digitalWrite(led_yellow,LOW);

  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  digitalWrite(led_red,HIGH);
  delay(500);
  digitalWrite(led_red,LOW);
}
