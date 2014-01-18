#include <Arduino.h>
#include "Screen.h"
#include "Bellows.h"
Bellows::Bellows(Screen screen, int targetTemperature){
	pinMode(2,OUTPUT);
	_screen = screen;
	_previousTemp = 0;
	this->setTargetTemperature(targetTemperature);
}
void Bellows::setTargetTemperature(int targetTemperature){
	_targetTemperature = targetTemperature;
	_screen.setTargetTemperatureDisplay(targetTemperature);
}
bool Bellows::_trendingUpAndClose(int currentTemp) {
	if(currentTemp > _targetTemperature - 5 && currentTemp > _previousTemp) {
		return true;
	}
	return false;
}
void Bellows::pulse(int currentTemp){
	if(currentTemp >= _targetTemperature || _trendingUpAndClose(currentTemp)) {
		_turnOffFan();
	}
	else if (currentTemp < _targetTemperature - 5) {
		_turnOnFan();
	}
	_previousTemp = currentTemp;
}
void Bellows::_turnOnFan(){
	digitalWrite(2,HIGH);
	_screen.setFanStatusDisplay("ON");
}
void Bellows::_turnOffFan(){
	digitalWrite(2,LOW);
	_screen.setFanStatusDisplay("OFF");
}