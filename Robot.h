#ifndef Robot_H
#define Robot_H

#include "Steering.h"
#include "Hbridge.h"
#include "Bluetooth.h"


class Robot{
private:  
  Steering steering;
  Hbridge leftSide;
  Hbridge rightSide;
  Bluetooth bluetooth;
  int carSpeed;
public:
  Robot(Steering st);
  void setBluetooth(Bluetooth bt);
  void setHbridges(Hbridge left, Hbridge right);
  void DriveForward(int _speed);
  void DriveLeft(int _speed);
  void DriveRight(int _speed);
  void DriveReverse(int _speed);
  void StopCar();
  void Run();
};

#endif
