#ifndef MENU_H
#define MENU_H


#include <iostream>
#include "Wiersz.h"
#include <vector>
#include <string>
using namespace std;

class Menu
{
private:
	string _menuName;
	vector<Wiersz>_wiersz;
public:
	Menu();
	Menu(string name);
	 
	void dodajObiekt();
	void run();
	string getVectorName(int num){return this->_wiersz[num].getWierszName();}
	string menuName(){return this->_menuName;}
	int getVectorID(int num){return this->_wiersz[num].getNumID();}
};


#endif //MENU_H
