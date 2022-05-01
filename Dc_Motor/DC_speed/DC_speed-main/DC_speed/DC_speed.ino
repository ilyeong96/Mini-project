#include "en_motor.h"
#include <MsTimer2.h>

en_motor mt;
int goal=0;
int pwm= 0;


void setup() {
  MsTimer2::set(200, t_intrrupt);
  MsTimer2::start();
  Serial.begin(4800);
  Serial.println("goal,duration");
}

void loop(){
  if (Serial.available() > 0){
    String val = Serial.readString();
    goal = val.toInt();
  }  
}

void speed(){
  if (goal < duration) pwm-= 2 ;
  else if (goal > duration) pwm+= 2;
  mt.control('A', pwm);
}

void t_intrrupt() {
  speed();
  Serial.print(goal);
  Serial.print(",");
  Serial.println(duration);
  duration = 0;
}
