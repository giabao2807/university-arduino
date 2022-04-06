#define PI 3.1412

int BUZZER = 4;
int TMP36 = 3;

float temp = 0;
float sinValue = 0;
int toneValue = 0;
unsigned long tepTimer = 0; 

OneWire ds(TMP36);

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  temp = getTemp();
  if (temp > 27) {
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

float getTemp() {
  byte data[12];
  byte addr[8];
  if (!ds.search(addr)) {
    ds.reset_search();
    return -1000;
  }
  if (OneWire::crc8(addr, 7) != addr[7]) {
    Serial.println("CRC is not valid!");
    return -1000;
  }
  if (addr[0] != 0x10 && addr[0] != 0x28) {
    Serial.print("Device is not recognized");
    return -1000;
  }
  ds.reset();
  ds.select(addr);
  ds.write(0x44, 1);
  byte present = ds.reset();
  ds.select(addr);
  ds.write(0xBE);
  for (int i = 0; i < 9; i++) {
    data[i] = ds.read();
  }
  ds.reset_search();
  byte MSB = data[1];
  byte LSB = data[0];
  float tempRead = ((MSB << 8) | LSB);
  float TemperatureSum = tempRead / 16;
  return TemperatureSum;
}
