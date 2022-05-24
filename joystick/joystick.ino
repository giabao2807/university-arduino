#define joyX A0
#define joyY A1
#define PI 3.1412

int BUZZER = 8;
int toneValue = 0;
int digitalValue = 0;

float temp = 0;
float voltValue = 0;
float sinValue = 0;
int button = 0;


int ledPin[] = {10,11,12,13};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin[0],OUTPUT);
  pinMode(ledPin[1],OUTPUT);
  pinMode(ledPin[2],OUTPUT);
  pinMode(ledPin[3],OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int xValue;
  int yValue;
  xValue = analogRead(joyX);
  yValue = analogRead(joyY);
  button = digitalRead(2);
  if (xValue > 600) {
    turnoff();
    digitalWrite(ledPin[0],HIGH);
  }
  else if (xValue < 400) {
    turnoff();
    digitalWrite(ledPin[1],HIGH);
  }
  else if (yValue > 600) {
    turnoff();
    digitalWrite(ledPin[2],HIGH);
  }
  else if (yValue < 400) {
    turnoff();
    digitalWrite(ledPin[3],HIGH);
  }
  if (button == 1) {
    
    for (int x = 0; x < 180; x++) {
        sinValue = (sin(x * ( PI / 180 )));
        toneValue =  2000 + (int(sinValue * 1000));
        tone(BUZZER, toneValue);
        delay(2);
    }
  } 
  else {
    noTone(BUZZER);
  }
  Serial.print(xValue);
  Serial.print("\t");
  Serial.print(yValue);
  Serial.print("\n");
  Serial.print(button);
}

void turnoff(){
  for (int i=0;i<4;i++){
    digitalWrite(ledPin[i],LOW);
  }
}
