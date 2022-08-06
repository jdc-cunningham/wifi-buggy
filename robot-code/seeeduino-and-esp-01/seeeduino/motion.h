// stole this code from my old project
// https://github.com/jdc-cunningham/noob-robotics/blob/master/taildragger-ultrasound-mapping/code/motion_1_ultrasonic_od_all_sensors_1__basic-od-logic/motion_1_ultrasonic_od_all_sensors_1__basic-od-logic.ino

#include <Servo.h>

// drive servos
Servo servoLeft;
Servo servoRight;

// wtf are these variables, my own code from almost 3 years ago
int seLeFoPos = 85;
int seRiFoPos = 96;
int seLeBaPos = 95;
int seRiBaPos = 84;
int seLeStPos = 90;
int seRiStPos = 90;

// motions
void moveForward() {
  servoLeft.write(seLeFoPos);
  servoRight.write(seRiFoPos);
  Serial.print("Forward");
  Serial.println();
}

void moveLeft() {
  servoLeft.write(seLeBaPos);
  servoRight.write(seRiFoPos);
  Serial.print("Left");
  Serial.println();
}

void moveRight() {
  servoLeft.write(seLeFoPos);
  servoRight.write(seRiBaPos);
  Serial.print("Right");
  Serial.println();
}

void moveBackward() {
  servoLeft.write(seLeBaPos);
  servoRight.write(seRiBaPos);
  Serial.print("Backward");
  Serial.println();
}

