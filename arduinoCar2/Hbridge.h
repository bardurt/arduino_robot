// Class definition for WheelPair
// Class represnets a side of a wehicle, steers the power
// to all wheels on that side.

#ifndef Hbridge_h
#define Hbridge_h

#include "Arduino.h"

class Hbridge{
private:
    int pin;
public:
    Hbridge(){};
    Hbridge(int _pin);
    void StartMotors(int _speed);
    void StopMotors();
};
#endif

