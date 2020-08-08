#include "Bluetooth.h"

Bluetooth::Bluetooth(){}

Bluetooth::Bluetooth(int _statePin){
    statePin = _statePin;
    pinMode(statePin, INPUT);
}

bool Bluetooth::isConnected(){

  if(digitalRead(statePin) == HIGH){
    return true;
  } else {
    return false;
  }
}


void Bluetooth::sendMessage(String _message){
    Serial.println(_message);
}

void Bluetooth::readData(String &Message){

	Message = "";
	int i = 0;
	while(Serial.available() > 0) {
  	  char in = Serial.read();
  	  Message.concat(in);
  	  return;
 	}
}



