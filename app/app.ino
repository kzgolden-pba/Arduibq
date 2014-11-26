#include "Thermometer.h"
#include "Screen.h"
#include "Bellows.h"

Thermometer thermometer(1);
Screen screen;
Bellows bellows(screen, 225);
void setup(){ 
}
void loop(){
	int buttonNumber = 0;
	buttonNumber = screen.checkButtonPressed();
	if(buttonNumber == 1) {
		bellows.setTargetTemperature(225);
	} else if (buttonNumber == 2) {
		bellows.setTargetTemperature(325);
	}
    screen.setTemperatureDisplay(thermometer.getTemperature());
    bellows.pulse(thermometer.getTemperature());
	delay(1000);
}
