int pinA0 = A0;
int pinD0 = 2;
#define ALARM 12
int led =13;

float sinValue=0;
float toneValue=0;

void setup() {
  Serial.begin(9600);
  pinMode(pinA0, INPUT);
  pinMode(pinD0, INPUT);
  pinMode(led, OUTPUT);
  pinMode(ALARM, OUTPUT);
}

void loop() {
  int valA0 = analogRead(pinA0);
  Serial.print("Analog Value: ");
  Serial.println(valA0);
  if (valA0 < 800) {
       for (int x = 0; x < 180; x++)
    {
      sinValue = (sin(x * ( PI / 180 )));
      toneValue =  2000 + (int(sinValue * 1000));
      tone(ALARM, toneValue);
      delay(2);
    }
    delay(500);
    digitalWrite(led,HIGH);
    Serial.println("FLAME DETECTED!");
  }
  else {
    noTone(ALARM);
    Serial.println();
  }
  delay(100);
}
