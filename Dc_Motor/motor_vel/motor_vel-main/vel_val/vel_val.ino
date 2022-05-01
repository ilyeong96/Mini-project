#include "en_motor.h"   
#include <MsTimer2.h>       

en_motor mt;


void setup(){
  MsTimer2::set(100, t_intrrupt);
  MsTimer2::start();
  Serial.begin(9600);
  }

void loop() 
{ 
if (Serial.available() > 0)
  {
    String val = Serial.readString();
    int val2 = val.toInt();
    mt.control('A',val2);
  }
}


void t_intrrupt() {
  Serial.print("Pulse:");
  Serial.println(duration);
  duration = 0;
}
