#include <Servo.h>

short const right_in = 4;
short const left_in = 2;
short const servo_out = 9;

Servo servo_1;

void setup() {
  pinMode(right_in, INPUT);
  pinMode(left_in, INPUT);
  servo_1.attach(servo_out);
  servo_1.write(0);
  // waiting for servo's initial position
  delay(1000);
}

short pos = 0;

void loop() {
  short const right_val = digitalRead(right_in);
  short const left_val = digitalRead(left_in);
  if (right_val && pos > 0) {
    --pos;
    servo_1.write(pos);
    delay(5);
  } else if (left_val && pos < 180) {
    ++pos;
    servo_1.write(pos);
    delay(5);
  }
}
