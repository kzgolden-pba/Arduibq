#include "Thermometer.h"
#include "Screen.h"
#include "Bellows.h"
Thermometer thermometer(1);
Screen screen;
Bellows bellows(screen, 225);
void setup(){ 
}
void loop(){
    screen.setTemperatureDisplay(thermometer.getTemperature());
    bellows.pulse(thermometer.getTemperature());
	delay(1000);
}
