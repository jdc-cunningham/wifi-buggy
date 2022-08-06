#include "motion.h"
#include "esp-01.h"

void setup()
{
  setupEspSerial();
  setupServos();
}

void loop()
{
  // this is where no threading is a problem
  checkMessages();
}