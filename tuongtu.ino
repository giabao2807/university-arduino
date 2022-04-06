int BUZZER = 4;
int TMP36 = 0;

int toneValue = 0;
int digitalValue = 0;

float temp = 0;
float voltValue = 0;
float sinValue = 0;

unsigned long tepTimer = 0; 

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER, OUTPUT);
  pinMode(TMP36, INPUT);
}

void loop() {
  digitalValue = analogRead(TMP36);
  temp = (float) digitalValue * (5 / 10.24);
  //temp = (voltValue - 0.5) * 100;
	
  if (temp > 40) {
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
  if (millis() - tepTimer > 50) {
    tepTimer = millis();
    Serial.print("Nhiet do: ");
    Serial.print(temp);
    Serial.println("C"); 
  } 
}
