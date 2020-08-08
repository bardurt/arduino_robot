#include "Steering.h"

Steering::Steering(){
 controlPinLeft1 = 2;
 controlPinLeft2 = 3;
 controlPinRight1 = 4;
 controlPinRight2 = 5;
 
  pinMode( controlPinLeft1, OUTPUT );
  pinMode( controlPinLeft2, OUTPUT );
  pinMode( controlPinRight1, OUTPUT );
  pinMode( controlPinRight2, OUTPUT );

}

Steering::Steering(int cp1,int cp2, int cp3, int cp4){
  controlPinLeft1 = cp1;
  controlPinLeft2 = cp2;
  controlPinRight1 = cp3;
  controlPinRight2 = cp4;
  
  pinMode( controlPinLeft1, OUTPUT );
  pinMode( controlPinLeft2, OUTPUT );
  pinMode( controlPinRight1, OUTPUT );
  pinMode( controlPinRight2, OUTPUT );
}

void Steering::Right(){
   digitalWrite( controlPinLeft1, LOW );
   digitalWrite( controlPinLeft2, HIGH );
   digitalWrite( controlPinRight1, LOW );
   digitalWrite( controlPinRight2, HIGH );
}

void Steering::Left(){
   digitalWrite( controlPinLeft1, HIGH );
   digitalWrite( controlPinLeft2, LOW );
   digitalWrite( controlPinRight1, HIGH );
   digitalWrite( controlPinRight2, LOW );
}

void Steering::Forward(){
   digitalWrite( controlPinLeft1, LOW );
   digitalWrite( controlPinLeft2, HIGH );
   digitalWrite( controlPinRight1, HIGH );
   digitalWrite( controlPinRight2, LOW );
}

void Steering::Reverse(){
   digitalWrite( controlPinLeft1, HIGH );
   digitalWrite( controlPinLeft2, LOW );
   digitalWrite( controlPinRight1, LOW );
   digitalWrite( controlPinRight2, HIGH );
}


