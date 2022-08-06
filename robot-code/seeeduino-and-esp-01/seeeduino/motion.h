// stole this code from my old project
// https://github.com/jdc-cunningham/noob-robotics/blob/master/taildragger-ultrasound-mapping/code/motion_1_ultrasonic_od_all_sensors_1__basic-od-logic/motion_1_ultrasonic_od_all_sensors_1__basic-od-logic.ino

#include <Servo.h>

// drive servos
Servo servoLeft;
Servo servoRight;

// wtf are these variables, my own code from almost 3 years ago
int seLeFoPos = 85;
int seRiFoPos = 97; // these determine the speed, higher value from midpoint eg. 90 the faster it rotates
int seLeBaPos = 95;
int seRiBaPos = 84;
int seLeStPos = 90;
int seRiStPos = 90;

bool isMovingForward = false;
bool isMovingBackwards = false;
bool isTurningLeft = false;
bool isTurningRight = false;

bool loggingEnabled = true;
String activeDirection = "";

int motionIncrementer = 0; // cap this
int maxMotionVal = 2;

int motionDelay = 250;

void setupServos()
{
  servoLeft.attach(0);
  servoRight.attach(3);
}

// motions
void moveForward() {
  servoLeft.write(seLeFoPos);
  servoRight.write(seRiFoPos);

  if (loggingEnabled)
  {
    Serial.print("Forward");
    Serial.println();
  }
}

void turnLeft() {
  servoLeft.write(seLeBaPos);
  servoRight.write(seRiFoPos);

  if (loggingEnabled)
  {
    Serial.print("Left");
    Serial.println();
  }
}

void turnRight() {
  servoLeft.write(seLeFoPos);
  servoRight.write(seRiBaPos);

  if (loggingEnabled)
  {
    Serial.print("Right");
    Serial.println();
  }
}

void moveBackward() {
  servoLeft.write(seLeBaPos);
  servoRight.write(seRiBaPos);

  if (loggingEnabled)
  {
    Serial.print("Backward");
    Serial.println();
  }
}

void stopMoving()
{
  servoLeft.write(seLeStPos);
  servoRight.write(seRiStPos);
}