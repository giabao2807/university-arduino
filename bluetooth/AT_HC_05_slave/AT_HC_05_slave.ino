#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(10, 11); //RX | TX
int led=13;
void setup() 
{
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  Bluetooth.begin(38400);// HC-05 default speed in AT command more
}
void loop()
{
//  receive data from Master
  if (Bluetooth.available()){
    int receive=(Bluetooth.read());
    Serial.println(receive);
    if (receive==1){
      digitalWrite(led,HIGH);
    }
    else {
      digitalWrite(led,LOW);
    }
  }}
