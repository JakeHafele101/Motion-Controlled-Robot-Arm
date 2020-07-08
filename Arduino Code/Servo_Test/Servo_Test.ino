#include <Servo.h>

#define SERVO_PIN_1 3
#define SERVO_PIN_2 4
#define SERVO_PIN_3 5
#define SERVO_PIN_4 6

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

  servo1.write(90);
  servo2.write(90);
  servo3.write(90);
  servo4.write(0);

  delay(10);

}
