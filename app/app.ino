#include "Thermometer.h"
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 13, 9, 4, 5, 6, 7);
Thermometer thermometer(1);
void setup(){
  lcd.clear(); 
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  Serial.begin(9600);      // open the serial port at 9600 bps:    
}
void loop(){
        lcd.clear();
        lcd.print(thermometer.getTemperature());
	delay(1000);
}
