#include "Wiersz.h"

using namespace std;

Wiersz::Wiersz(string name)
{
	if(name.length()<=16) 
	this->_name=name;
	ptrLcd= make_unique<Lcd>(name);
}
void Wiersz::writeLineOnDisplay(char lineNumber)
{
	ptrLcd->writeLine(this->_name,lineNumber);
	
}
