

#include "Hbridge.h"


Hbridge::Hbridge(int _pin){
  pin = _pin;
  
  // set pin to output
  pinMode( pin, OUTPUT );
 
}

void Hbridge::StartMotors(int _speed){
  
  // set power on
   analogWrite( pin, _speed );
}

void Hbridge::StopMotors(){
  
  // set power off
    digitalWrite( pin, LOW );
}

