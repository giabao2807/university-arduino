int led = 13;
int LIGHT = 0;
int val = 0;
void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(LIGHT);
  Serial.println(val);
  if(val < 700){
    digitalWrite(led, LOW);
  } else {
    digitalWrite(led, HIGH);
  }
  delay(10);
}
