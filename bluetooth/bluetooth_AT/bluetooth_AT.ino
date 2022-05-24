
#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(10, 11); // RX | TX
void setup() 
{
  pinMode(9, OUTPUT);  
  digitalWrite(9, HIGH); //kéo điện áp lên mức cao để vào AT commands
  Serial.begin(9600);
  Serial.println("AT commands: ");
  Serial.println("==========================================");
  Serial.println("Func         |CMD          |Response      ");
  Serial.println("Test         |AT           |OK            ");
  Serial.println("Reset        |AT+ORGL      |OK            ");
  Serial.println("Role         |AT+ROLE=0|1  |OK            ");
  Serial.println("Check role   |AT+ROLE?     |0|1           ");
  Serial.println("Display Name |AT+NAME?     |HC-05(default)");
  Serial.println("Display Pass |AT+PSWD?     |1234(default) ");
  Serial.println("Change Name  |AT+NAME=name |OK            ");
  Serial.println("Change Pass  |AT+PSWD=pass |OK            ");
  Serial.println("Connect mode |AT+CMODE=mode|OK            ");
  Serial.println("UART         |AT+UART?     |9600,0,0 ");
  Serial.println("Show address |AT+ADDR?     |xxxx.xx.xxxxxx"); // replace : with ,
  Serial.println("Bind         |AT+BIND=addr |OK            ");
  Serial.println("==========================================");
  Serial.println("Enter AT commands:");
  Bluetooth.begin(38400);  // HC-05 default speed in AT command more
}

void loop()
{
//   Keep reading from HC-05 and send to Arduino Serial Monitor
  if (Bluetooth.available())
    Serial.write(Bluetooth.read());

// Keep reading from Arduino Serial Monitor and send to HC-05
  if (Serial.available())
    Bluetooth.write(Serial.read());
}
