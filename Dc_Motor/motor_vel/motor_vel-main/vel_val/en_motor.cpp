#include "en_motor.h"
#include <Arduino.h>
#include <MsTimer2.h>

int encoder0PinALast = 1;
boolean Direction = 1;
int duration = 0;



void en_motor::position(int val)
{
  if (val <= duration)
  {
    while (val <= duration)
    {
      en_motor::control('A', -100);

      Serial.print("Pulse:");
      Serial.println(duration);
    }
  }
    
  else if (val >= duration)
  {
    while (val>= duration)
    {
      en_motor::control('A', 100);

      Serial.print("Pulse:");
      Serial.println(duration);
    }
   
  }
 en_motor::control('A', 0);
  
}


void wheelSpeed()
{
  int Lstate = digitalRead(encoder0pinA);
  if ((encoder0PinALast == LOW) && Lstate == HIGH)
  {
    int val = digitalRead(encoder0pinB);
    if (val == LOW && Direction)
    {
      Direction = false; //Reverse
    }
    else if (val == HIGH && !Direction)
    {
      Direction = true;  //Forward
    }
  }
  encoder0PinALast = Lstate;

  if (Direction)  duration++;
  else  duration--;
}



en_motor::en_motor()
{
  Direction = true;//default -> Forward
  pinMode(encoder0pinB, INPUT_PULLUP);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  attachInterrupt(0, wheelSpeed, CHANGE);

}


void en_motor::control(char AB, int E)
{
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

void en_motor::drive(char val)
{
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
