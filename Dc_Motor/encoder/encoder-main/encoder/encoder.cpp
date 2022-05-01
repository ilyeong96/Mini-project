#include "encoder.h"
#include <Arduino.h>

encoder::encoder()
{
  Direction = true;//default -> Forward
  pinMode(encoder0pinB, INPUT);
}

void encoder::wheelSpeed()
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
