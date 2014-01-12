#include <Arduino.h>
#include <LiquidCrystal.h>
#include "Screen.h"
Screen::Screen() : _lcd(8, 13, 9, 4, 5, 6, 7) {
	_lcd.clear();
	_lcd.begin(16, 2);
}
void Screen::setTemperatureDisplay(int temp) {
	this->_scrub(0,0,7);
	_lcd.print("Pit:" + (String) temp);
}
void Screen::setFanPctDisplay(int pct) {
	this->_scrub(0,1,8);
	_lcd.print("Fan:" + (String) pct + "%");
}
void Screen::setFanStatusDisplay(String status) {
	this->_scrub(9,1,3);
	_lcd.print(status);
}
void Screen::setPulseDisplay(int pulse){
	this->_scrub(13,1,2);
	_lcd.print(pulse);

}
void Screen::setTargetTemperatureDisplay(int targetTemp) {
	this->_scrub(8,0,8);
	_lcd.print("Targ:" + (String) targetTemp);
}
void Screen::_scrub(int col, int row, int length) {
	_lcd.setCursor(col,row);
	for(int i = 0; i < length; i++){
		_lcd.print(" ");
	}
	_lcd.setCursor(col,row);
}