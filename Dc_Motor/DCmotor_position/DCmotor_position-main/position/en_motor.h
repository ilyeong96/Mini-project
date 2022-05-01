#ifndef en_motor_h
#define en_motor_h

#include <Arduino.h>

#define E1 10  //  A모터속도
#define M1 12 //   A모터방향
#define E2 11 //   B모터속도
#define M2 13 //   B모터방향
#define encoder0pinA 2 //A pin -> the interrupt pin 0
#define encoder0pinB  3//B pin -> the digital pin 3

extern int encoder0PinALast;
extern boolean Direction;
extern int duration;

void wheelSpeed();

class en_motor{
  private:

  public:
    en_motor();//Initialize the module 
    void en_motor::position(int val);
    void control(char dir , int E);
    void drive(char var);
    int V1 = 100;
    int V2 = 100;
};




#endif
