#include <LiquidCrystal.h>
#ifndef Screen_h
#define Screen_h
class Screen {
	public:
		Screen();
    	void setTemperatureDisplay(int temp);
		void setFanPctDisplay(int pct);
	private:
		LiquidCrystal _lcd;
};
#endif
