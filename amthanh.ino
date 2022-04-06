int pin=0;
int led=13;


void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);

}

void loop() {
  int val=0;
  val =analogRead(pin);
  if (val >500){
    digitalWrite(led,1);
  } 
  Serial.println(val);
  delay(100);

}
