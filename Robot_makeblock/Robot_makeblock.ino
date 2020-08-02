#include <MeMCore.h>

MeDCMotor left_motor(9);
MeDCMotor right_motor(10);

void moveDrive(int speed, int dir) {
  switch (dir) {
    case 0:
     right_motor.run(speed);
     left_motor.run(-speed);
     break;
    case 1:
     right_motor.run(speed);
     left_motor.run(speed);
     break;
  }
}

void moveTime(int speed, int time, int dir) {
  moveDrive(speed, dir);
  delay(time);
  moveDrive(0, 0);
}

void setup(){
  Serial.begin(115200);
}

void loop(){
  if (Serial.available()) {
    switch (Serial.read()) {
      case '-':
        // Forwards
        moveTime(150, 300, 0);
        break;
      case '.':
        // Backwards
        moveTime(-150, 300, 0);
        break;
      case '/':
        // Left
        moveTime(150, 150, 1);
        break;
      case '0':
        // Right
        moveTime(-150, 150, 1);
        break;
    }
  }
}
