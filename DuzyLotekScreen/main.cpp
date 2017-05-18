#include "LCD.h"
#include <iostream>
#include "Wiersz.h"

using namespace std;

int main()
{
	wiringPiSetup();
	
	Wiersz * wiersz=new Wiersz("ALICJA GOTUJ OBIAD!!");
	wiersz->writeLineOnDisplay(0);
	
	cin.get();
	
	return 0;
}
