#include "esp-01.h"

void setup()
{
  setupEspSerial();
}

void loop()
{
  checkMessages();
}