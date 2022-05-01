#include "motor.h"
#include <Arduino.h>

motor::motor()
{
  V1 =100;
  V2 =100;
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
}

motor::motor(int V1, int V2)
{
   this->V1 =V1;
   this->V2 =V2;
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
}


void motor::control(char AB, int E) {
  if (AB == 'A') // A이면 A모터 출력
  {
    if (E > 0) digitalWrite(M1, HIGH);
    else digitalWrite(M1, LOW);
    analogWrite(E1, abs(E));
  }
  else
  {
    if (E > 0) digitalWrite(M2, HIGH);
    else digitalWrite(M2, LOW);
    analogWrite(E2, abs(E));
  }

}

void motor::drive(char val) {
  Serial.println(val);
  switch (val) {
    case 'f': //f - 전진
      control('A', V1);
      control('B', V2);
      break;
    case 'a': //a - 좌회전
      control('A' , V1);
      control('B' , 0);
      break;
    case 's': //s -  정지
      control('A' , 0);
      control('B' , 0);
      break;
    case 'c': //c- 우회전
      control('A' , 0);
      control('B' , V2);
      break;
    case 'd': //d - 후진
      control('A' , -V1);
      control('B' , -V2);
      break;
    default:
      break;
  }
}
