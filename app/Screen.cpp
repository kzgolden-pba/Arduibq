#include <Arduino.h>
#include <LiquidCrystal.h>
#include "Screen.h"
Screen::Screen() : _lcd(8, 13, 9, 4, 5, 6, 7) {
	_lcd.clear();
	_lcd.begin(16, 2);
}
void Screen::setTemperatureDisplay(int temp) {
	_lcd.home();
	_lcd.print("Temp: " + (String) temp);
}
void Screen::setFanPctDisplay(int pct) {
	_lcd.setCursor(0, 1);
	_lcd.print("Fan: " + (String) pct + "%");
}