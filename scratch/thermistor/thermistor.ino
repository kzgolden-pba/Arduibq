#include <LiquidCrystal.h>
#define TP 2      //Trig_pin
LiquidCrystal lcd(8, 13, 9, 4, 5, 6, 7);

int thermister_temp(int aval) {
	double R, T;

	// These were calculated from the thermister data sheet
	//	A = 2.3067434E-4;
	//	B = 2.3696596E-4;
	//	C = 1.2636414E-7;
	//
	// This is the value of the other half of the voltage divider
	//	Rknown = 22200;

	// Do the log once so as not to do it 4 times in the equation
	//	R = log(((1024/(double)aval)-1)*(double)22200);
	R = log((1 / ((1024 / (double) aval) - 1)) * (double) 1014000);
	//lcd.print("A="); lcd.print(aval); lcd.print(" R="); lcd.print(R);
	// Compute degrees C
	T = (1 / ((4.717016E-4) + (1.90988E-4) * R + (9.955908E-8) * R * R * R)) - 273.25;
	// return degrees F
	return ((int) ((T * 9.0) / 5.0 + 32.0));
}

void CelsiusToFarenheit(float const tCel, float &tFar) {
	tFar = tCel * 1.8 + 32;
}
void setup() {
  lcd.clear(); 
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  Serial.begin(9600);      // open the serial port at 9600 bps:    
  pinMode(TP,OUTPUT);       // set TP output for trigger  
}

void loop() {
    unsigned int signal = 0;
    unsigned int pit_temp = 0;
    signal = analogRead(1);
    pit_temp = thermister_temp(signal);
    Serial.print("Temp: ");
    Serial.print(pit_temp);
    Serial.print(", Signal: ");
    Serial.print(signal);
    Serial.println("");
    lcd.setCursor(0,0);
    lcd.print("Pit: ");
    lcd.print(pit_temp);
    lcd.print("deg");
    lcd.setCursor(0,1);
    lcd.print("Fan: ");
    
    if(pit_temp > 82){
      digitalWrite(TP,HIGH);
      lcd.print("ON ");
    }
    else {
      digitalWrite(TP,LOW);
      lcd.print("OFF");
    }
    Serial.println(digitalRead(2));
    delay(1000);
}

