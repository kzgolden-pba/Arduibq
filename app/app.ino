#include "Thermometer.h"
#include "Screen.h"
Thermometer thermometer(1);
Screen screen;
void setup(){ 
}
void loop(){
    screen.setTemperatureDisplay(thermometer.getTemperature());
    delay(1000);
    screen.setFanPctDisplay(100);
	delay(1000);
}
