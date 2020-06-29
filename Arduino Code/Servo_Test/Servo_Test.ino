#include <Servo.h>

#define SERVO_PIN_1 2
#define SERVO_PIN_2 3
#define SERVO_PIN_3 4
#define SERVO_PIN_4 5

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

int pos = 0;

void setup() {
  // put your setup code here, to run once:
  servo1.attach(SERVO_PIN_1);
  servo2.attach(SERVO_PIN_2);
  servo3.attach(SERVO_PIN_3);
  servo4.attach(SERVO_PIN_4);
}

void loop() {
  
  pos++;

  if(pos > 180){
    pos = 0;
  }

  servo1.write(0);
  servo2.write(pos);
  servo3.write(pos);
  servo4.write(pos);

  delay(10);

}
