#include <Wire.h>

unsigned char slave_add = 0x36;
unsigned char angle1_add = 0x0C;
unsigned char angle2_add = 0x0D;

unsigned char answer;
unsigned char answer2;
unsigned int real;
float real2;

const long looptime = 10;
unsigned long prevMicros = 0;
unsigned long currMicros;

void setup() {
  Wire.begin();             // Join I2C bus (address is optional for controller device)
  Serial.begin(9600);       // Start serial for output
  Serial.println("Master on");
}

void loop() {
  currMicros = micros();
  if (currMicros - prevMicros >= looptime) {
    prevMicros = currMicros;
    Wire.beginTransmission(slave_add);
    Wire.write(angle1_add);
    Wire.endTransmission(false);

    Wire.beginTransmission(slave_add ^ 0x01);
    Wire.endTransmission(true);

    Wire.requestFrom(slave_add, 2);    // Request 6 bytes from slave device number two

    if (Wire.available()) {
      answer = Wire.read();
      answer2 = Wire.read();
      real = answer;
      real <<= 8;
      real |= answer2;
      real2 = (float) real / (4096.0 - 1.0) * 360.0;
      Serial.println(real2);
      //      Serial.print(answer);
      //      Serial.print("\t");
      //      Serial.println(answer2);
    }
  }
}
