#ifndef Steering_h
#define Steering_h

#include "Arduino.h"

class Steering{
private:
  int controlPinLeft1;
  int controlPinLeft2;
  int controlPinRight1;
  int controlPinRight2;;
public:
  Steering();
  Steering(int cp1,int cp2, int cp3, int cp4);
  void Left();
  void Right();
  void Forward();
  void Reverse();
  
};
#endif

