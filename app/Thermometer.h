#include <Arduino.h> 
#ifndef Thermometer_h
#define Thermometer_h

class Thermometer {
	public:
		Thermometer(int signalPin);
		int getTemperature();
	private:
		int _signalPin;
};

#endif
