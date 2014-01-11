#include <LiquidCrystal.h>
#include "./lib/Thermometer/Thermometer.h"

Thermometer thermometer(1);

void setup(){
  lcd.clear(); 
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
}

void loop(){
	lcd.clear();
	lcd.print(thermometer.getTemperature());
	delay(1000);
}
