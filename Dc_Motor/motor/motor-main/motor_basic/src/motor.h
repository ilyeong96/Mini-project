#ifndef motor_h
#define motor_h

#include <Arduino.h>

#define E1 10  //  A모터속도
#define M1 12 //   A모터방향
#define E2 11 //   B모터속도
#define M2 13 //   B모터방향

class motor {

  private:

  public:
    motor();
    motor(int V1, int V2);
    void control(char dir , int E);
    void drive(char var);
    int V1 ;
    int V2 ;

};

#endif
