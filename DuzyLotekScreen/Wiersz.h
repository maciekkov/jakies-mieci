#ifndef WIERSZ_H
#define WIERSZ_H

#include <iostream>
#include <string>
#include "LCD.h"
using namespace std;
class Wiersz
{
private:
	string _name;
	unique_ptr<Lcd>ptrLcd;
public:
	
	Wiersz(string name);
	void writeLineOnDisplay(char lineNumber);

	
};

#endif //WIERSZ_H
