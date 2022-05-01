#include "en_motor.h"
#include <MsTimer2.h>

en_motor mt;
int goal = 0;
int pwm = 0;

int PID_val;
float Pv = 4;
float Iv = 1;
float Dv = 1.2;

float err_P;
float err_I;
float err_D;
float err_B;


void setup() {
  MsTimer2::set(50, t_intrrupt);
  MsTimer2::start();
  Serial.begin(4800);
  Serial.println("goal,duration");
}

void loop() {
  if (Serial.available() > 0) {
    String val = Serial.readString();
    goal = val.toInt();
  }
}

void pid_speed() {
  err_P = goal - duration;
  err_I += err_P;
  err_D = err_B - err_P;
  err_B = err_P;
  PID_val = ((err_P * Pv) + (err_I * Iv) + (err_D * Dv));
  if (PID_val >= 110) PID_val = 110;
  if (PID_val <= -110) PID_val = -110;
  pwm=map(PID_val,-110,110,-255,255);
  mt.control('A', pwm);
}



void t_intrrupt() {
  pid_speed();
  Serial.print(goal);
  Serial.print(",");
  Serial.println(duration);
  duration = 0;
}
