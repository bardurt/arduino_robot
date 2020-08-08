#ifndef Bluetooth_h
#define Bluetooth_h

#include "Arduino.h"
class Bluetooth{

private:
int statePin;
public:
  Bluetooth();
  Bluetooth(int _statePin);
  //String readData();
  bool isConnected();
  void sendMessage(String _message);
  void readData(String &message);
};
#endif
