#define joyX A0
#define joyY A1

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int xValue;
  int yValue;
  int button;
  xValue = analogRead(joyX);
  yValue = analogRead(joyY);
  button = digitalRead(2);
  Serial.print(xValue);
  Serial.print("\t");
  Serial.print(yValue);
  Serial.print("\n");
  Serial.print(button);
  delay(500);
}
