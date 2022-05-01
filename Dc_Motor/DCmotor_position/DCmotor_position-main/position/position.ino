#include "en_motor.h"          

en_motor mt;


void setup()
{
  Serial.begin(9600);

}

void loop() 
{
  
if (Serial.available() > 0)
  {
    String val = Serial.readString();
    char cTempData[5];
    val.substring(0,5).toCharArray(cTempData,6);
    int val2=atoi(cTempData);
    Serial.println(val2);
    delay(300);
    mt.position(val2);
  }


}
