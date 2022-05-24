#define DECODE_NEC
#include <Arduino.h>
#define IR_RECEIVE_PIN 2
#define LED_PIN 13
#include<IRremote.hpp>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_PIN,OUTPUT);
  IrReceiver.begin(IR_RECEIVE_PIN);
  Serial.print(F("Ready to receive IR signals: "));
  printActiveIRProtocols(&Serial);
  Serial.print(F(" at pin "));
  Serial.print(IR_RECEIVE_PIN);
//  Serial.print(); 
}
int led_status = 0 ;
void loop() {
  
  // put your main code here, to run repeatedly:
  if(IrReceiver.decode()){
    if(IrReceiver.decodedIRData.protocol != UNKNOWN){
      IrReceiver.printIRResultShort(&Serial);
    }
  
  IrReceiver.resume();
  if(IrReceiver.decodedIRData.command == 0x34){
    Serial.print(" Da Nhan ");
       if(led_status == 0 ){
        digitalWrite(LED_PIN, HIGH);
        led_status = 1;
     }else{
      digitalWrite(LED_PIN,LOW);
      led_status = 0 ;
     }
     }
   }
  
}
