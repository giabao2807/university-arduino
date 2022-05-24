#define IR_SEND_PIN 3
#include<IRremote.hpp>
#define SENSOR 0

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  IrSender.begin();
  Serial.print(F("Ready to send IR signals at pin "));
  Serial.println(IR_SEND_PIN);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(SENSOR,INPUT_PULLUP);
}
int value = 0;
uint16_t sAddress = 0x0102;
uint8_t sCommand = 0x34;
uint8_t sRepeats = 0;

void loop() {
  value = analogRead(SENSOR);

  Serial.print(value);
  Serial.println();
 
  if(value > 200){
  // put your main code here, to run repeatedly:
  Serial.println("Sending code from IR TRANSMITTER");
  IrSender.sendNEC(sAddress,sCommand,sRepeats);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);}
  else{
     digitalWrite(LED_BUILTIN, LOW);
  }
}
