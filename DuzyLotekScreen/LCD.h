#ifndef LCD_H
#define LCD_H
#include <wiringPi.h>
#include <lcd.h>
#include <iostream>

using namespace std;

class Lcd
{
private:
	int lcd;
public:
	Lcd(){
	lcd  = lcdInit (2, 16,4, 3, 0,6, 1, 5,4,0,0,0,0);
	}
	bool writeLine(string text,char lineNumber);
};

#endif
