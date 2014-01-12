#include "Screen.h"
#ifndef Bellows_h
#define Bellows_h
class Bellows {
	public:
		Bellows(Screen screen, int targetTemperature);
		void setTargetTemperature(int targetTemp);
		void pulse(int currentTemp);
	private:
		void _setFanPct(int currentTemp);
		void _setPulseCount();
		void _turnOnFan();
		void _turnOffFan();
		int _pulseCount;
		int _targetTemperature;
		int _fanPct;
		Screen _screen;
};
#endif