
#include "encoder.h"          // 모터 구동 헤더파일 
 
encoder myen;
void turnon(){myen.wheelSpeed();}

void setup()
{
  Serial.begin(9600);
  attachInterrupt(0, turnon, CHANGE);  
}

void loop() 
{
  Serial.print("Pulse:");
  Serial.println(myen.duration);
}
