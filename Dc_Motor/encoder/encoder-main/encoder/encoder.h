#ifndef encoder_h
#define encoder_h

#include <Arduino.h>

class encoder {
  private:

  public:
    encoder();//Initialize the module
    byte encoder0pinA = 2;//A pin -> the interrupt pin 0
    byte encoder0pinB = 3;//B pin -> the digital pin 3
    byte encoder0PinALast;
    int duration;//the number of the pulses
    boolean Direction;//the rotation direction
    void wheelSpeed();
};



#endif
