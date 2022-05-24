#define led 13
#define vibrationPin 3
#define ALARM 12

unsigned char state=0;
float sinValue=0;
float toneValue-0;


void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(vibrationPin, INPUT);
  pinMode(ALARM, OUTPUT);
  attachInterrupt(1, blink, FALLING);

}

void loop() {
  if (state != 0) {
    state=0;
    digitalWrite(led,HIGH);
   for (int x = 0; x < 180; x++)
    {
      sinValue = (sin(x * ( PI / 180 )));
      toneValue =  2000 + (int(sinValue * 1000));
      tone(ALARM, toneValue);
      delay(2);
    }
    delay(500);
  } else {
    digitalWrite(led,LOW);
    noTone(ALARM);
  }
}

void blink(){
  state++;
}
