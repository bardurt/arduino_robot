#include "Robot.h"

Robot::Robot(Steering st){

 steering = st; 
 carSpeed = 255;
}

void Robot::setBluetooth(Bluetooth bt){
  bluetooth = bt;
}

void Robot::setHbridges(Hbridge left, Hbridge right){
  leftSide = left;
  rightSide = right;
}

void Robot::DriveForward(int _speed){

   steering.Forward();
   rightSide.StartMotors(_speed); 
   leftSide.StartMotors(_speed);
}

void Robot::DriveLeft(int _speed){

   steering.Left();   
   leftSide.StartMotors(_speed);
   rightSide.StartMotors(_speed);
}

void Robot::DriveRight(int _speed){

   steering.Right(); 
   leftSide.StartMotors(_speed);
   rightSide.StartMotors(_speed);
}

void Robot::DriveReverse(int _speed){
 
   steering.Reverse();
   leftSide.StartMotors(_speed);
   rightSide.StartMotors(_speed);
}

void Robot::StopCar(){
  
   leftSide.StopMotors();
   rightSide.StopMotors();
}

// variables for driving and setting speed and hearbeat timer
String cmd = "";
String speedC ="";
bool readingSpeed = false;
unsigned long sendTime = 0;

// function to start robot 
void Robot::Run(){
  
  // robot stops if there is no connection
  if(!bluetooth.isConnected()){
          StopCar();
  }
  else
  {   
    // send out a heartbeat
    if(abs(millis()- sendTime) > 1000){
         bluetooth.sendMessage("O");
         sendTime = millis();
    }
     
    // read data from bluetooth module
    cmd == "";
    bluetooth.readData(cmd);
    
    // check if speed should be changed
    if(cmd == "|")
      readingSpeed = true;
      
    // set the received value for speed to actual speed
    if(cmd == "#"){
      readingSpeed = false;
      Serial.println(speedC);
      int tmpSpeed = speedC.toInt();
      if(tmpSpeed >= 0 && tmpSpeed <= 255){
        carSpeed = tmpSpeed;
      }
      speedC ="";
    }
    
    // set the speed value
    if(readingSpeed){
      if(cmd != "|")
        speedC += cmd;
    }
    
    // check if the robot should drive
    if(cmd.equals("f")){
          readingSpeed = false;
          DriveForward(carSpeed);
    }
    else if(cmd.equals("b")){
          readingSpeed = false;
          DriveReverse(carSpeed);
    }
    else if(cmd.equals("l")){
          readingSpeed = false;
          DriveLeft(carSpeed);
    }
    else if(cmd.equals("r")){
          readingSpeed = false;
          DriveRight(carSpeed);
    }
    else if(cmd.equals("s")){
          readingSpeed = false;
          StopCar();
    }
  }
}

