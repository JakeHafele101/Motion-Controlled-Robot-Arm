#include<Wire.h>;

#define FLEX_PIN A0

const int MPU_ADDRESS=0x68;
int axisX, axisY, axisZ;
int x, y, z;

int minVal = 265;
int maxVal = 402;

void setup() {
  Wire.begin();
  Wire.beginTransmission(MPU_ADDRESS);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.begin(9600);
}

void loop() {
  Wire.beginTransmission(MPU_ADDRESS);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDRESS, 14, true);

  axisX = Wire.read()<<8|Wire.read(); //Reads axis values from MPU
  axisY = Wire.read()<<8|Wire.read();
  axisZ = Wire.read()<<8|Wire.read();

  int xAng = map(axisX, minVal, maxVal, -90, 90); //Remaps sensor values between -90 to 90
  int yAng = map(axisY, minVal, maxVal, -90, 90);
  int zAng = map(axisZ, minVal, maxVal, -90, 90);

  x = RAD_TO_DEG * (atan2(-yAng, -zAng) + PI); //Convert from radians into degrees
  y = RAD_TO_DEG * (atan2(-xAng, -zAng) + PI);
  z = RAD_TO_DEG * (atan2(-xAng, -yAng) + PI);
  
  int flexValue = analogRead(FLEX_PIN); //Flex sensor code
  serial.println(flexValue);

}
