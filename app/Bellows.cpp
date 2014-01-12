#include <Arduino.h>
#include "Screen.h"
#include "Bellows.h"
Bellows::Bellows(Screen screen, int targetTemperature){
	pinMode(2,OUTPUT);
	_screen = screen;
	_fanPct  = 100;
	_pulseCount = 1;
	this->setTargetTemperature(targetTemperature);
}
void Bellows::setTargetTemperature(int targetTemperature){
	_targetTemperature = targetTemperature;
	_screen.setTargetTemperatureDisplay(targetTemperature);
}
void Bellows::pulse(int currentTemp){
	_setFanPct(currentTemp);
	if(_pulseCount * 10 > _fanPct) {
		_turnOffFan();
	} else {
		_turnOnFan();
	}
	_setPulseCount();
}
void Bellows::_setPulseCount() {
	_screen.setPulseDisplay(_pulseCount);
	if(_pulseCount < 10) {
		_pulseCount = _pulseCount + 1;
	}
	else {
		_pulseCount = 1;
	}
}
void Bellows::_setFanPct(int currentTemp){
	if(currentTemp > _targetTemperature && _fanPct >= 10) {
		_fanPct = _fanPct - 10;
	}
	else if (currentTemp < _targetTemperature && _fanPct < 100) {
		_fanPct = _fanPct + 10;
	}
	_screen.setFanPctDisplay(_fanPct);
}
void Bellows::_turnOnFan(){
	digitalWrite(2,HIGH);
	_screen.setFanStatusDisplay("ON");
}
void Bellows::_turnOffFan(){
	digitalWrite(2,LOW);
	_screen.setFanStatusDisplay("OFF");
}