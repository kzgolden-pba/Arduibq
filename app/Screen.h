#include <LiquidCrystal.h>
#ifndef Screen_h
#define Screen_h
class Screen {
	public:
		Screen();
    	void setTemperatureDisplay(int temp);
		void setFanPctDisplay(int pct);
		void setTargetTemperatureDisplay(int targetTemperature);
		void setFanStatusDisplay(String status);
		void setPulseDisplay(int pulse);
	private:
		void _scrub(int col, int row, int length);
		LiquidCrystal _lcd;
};
#endif
