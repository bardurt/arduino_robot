//main program to run the robot
#include "Robot.h"

 Steering st(2,3,4,5);
 Hbridge left(10);
 Hbridge right(9);
 Robot robot(st);
 Bluetooth bt(13);
 

void setup(){
 Serial.begin(9600);
 robot.setHbridges(left,right);
 robot.setBluetooth(bt);
}

void loop(){
  robot.Run(); 
}
