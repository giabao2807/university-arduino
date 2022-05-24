int led = 13;
int LIGHT = 0;
int val = 0;
int sensor = 2;
int state = LOW;

//co nguoi + toi thi den sang

void setup() {
  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT);
  pinMode(LIGHT, INPUT);
  Serial.begin(9600);
}

void loop() {
  //read value for light
  light_value = analogRead(LIGHT);
  sensor_value = digitalRead(sensor);

  if (light_value > 700 && sensor_value = HIGH){
    digitalWrite(led, HIGH);
    delay(100);

    if (state == LOW) {
      Serial.println("detect motivation");
      state = HIGH;
    }
  } else {
    digitalWrite(led, HIGH);
    delay(100);

    if (state == LOW) {
      Serial.println("detect motivation");
      state = HIGH;
    }
  }
  

}
