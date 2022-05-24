#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(10, 11); // RX | TX
int gasPin=A0;
void setup() 
{
  Serial.begin(9600);
  Bluetooth.begin(38400);  // HC-05 default speed in AT command more
}
void loop()
{
  int val = analogRead(gasPin);
  Serial.println(val);
  //send data to Slave
  if (val>600){
    Serial.println("co gas");
    Bluetooth.write(1);
  }
  else {
    Bluetooth.write(2);
  }
   delay(200);  
}
