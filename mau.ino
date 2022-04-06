int s0=2, s1=3, s2=4, s3=5;
int Out =6;
unsigned int frequency =0;

void setup() {
  pinMode(s0,OUTPUT);
  pinMode(s1,OUTPUT);
  pinMode(s2,OUTPUT);
  pinMode(s3,OUTPUT);
  digitalWrite(s0,HIGH);
  digitalWrite(s1,LOW);
  Serial.begin(9600);
}

void loop() {
  
  digitalWrite(s2,LOW);
  digitalWrite(s3,LOW);
  frequecy = pulseIn(Out,LOW);
  Serial.print("Red=");
  Serial.println(frequency, DEC);
  delay(500);
  digitalWrite(s2,LOW);
  digitalWrite(s3,HIGH);
  frequecy = pulseIn(Out,LOW);
  Serial.print("Blue=");
  Serial.println(frequency, DEC);
  delay(500);
    digitalWrite(s2,HIGH);
  digitalWrite(s3,HIGH);
  frequecy = pulseIn(Out,LOW);
  Serial.print("Green=");
  Serial.println(frequency, DEC);
  delay(500);
}
