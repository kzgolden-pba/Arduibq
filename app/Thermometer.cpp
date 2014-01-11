/*
  Thermometer.cpp - Library for reading PIT thermometer that comes with Maverick ET-732
  wireless grill thermometer
*/

#include <Arduino.h>
#include "Thermometer.h"

Thermometer::Thermometer(int signalPin) {
	pinMode(signalPin, OUTPUT);
	_signalPin = signalPin;
}
int Thermometer::getTemperature() {
	double forwardResistorOhms = 1014000, 
			input = analogRead(_signalPin),
			thermistorOhms = log((1 / ((1024 / (double) input) - 1)) * (double) forwardResistorOhms),
			temp = (1 / ((4.717016E-4) + (1.90988E-4) * thermistorOhms + (9.955908E-8) * thermistorOhms * thermistorOhms * thermistorOhms)) - 273.25;
        int fTemp = ((int)((temp * 9.0) / 5.0 + 32.0));
	// return degrees F
        return fTemp;
}
