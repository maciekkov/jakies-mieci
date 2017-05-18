#include "LCD.h"

bool Lcd::writeLine(string text,char lineNumber)
{
	lcdClear(lcd);
	lcdPosition(lcd,lineNumber,0);
	lcdPuts(lcd,text.c_str());

}
