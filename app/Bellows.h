#include "Screen.h"
#ifndef Bellows_h
#define Bellows_h
class Bellows {
	public:
		Bellows(Screen screen, int targetTemperature);
		void setTargetTemperature(int targetTemp);
		void pulse(int currentTemp);
	private:
		void _turnOnFan();
		void _turnOffFan();
		bool _trendingUpAndClose(int currentTemp);
		int _targetTemperature;
		int _previousTemp;
		Screen _screen;
};
#endif