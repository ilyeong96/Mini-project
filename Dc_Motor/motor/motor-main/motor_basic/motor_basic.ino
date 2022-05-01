#include "motor.h"

motor mt;

void setup()
{
  Serial.begin(9600);
}

void loop() 
{
if (Serial.available() > 0)
  {
    char val;
    val = Serial.read();
    mt.drive(val);
  }
}
