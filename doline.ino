
#define LINE 2
int val = 0;

void setup() {
  Serial.begin(9600);

}

void loop() {
  val = digital.READ(val);
  Serial.print(val);
  delay(1000);
}
