#ifndef WIERSZ_H
#define WIERSZ_H


#include <iostream>
#include "duzy_lotek.h"
#include <vector>
#include <string>

using namespace std;

class Wiersz
{
private:
	string _wierszName;
	int _numID;
public:
	Wiersz(){}
	Wiersz(string name,int numID);
	string getWierszName(){return _wierszName;}
	int getNumID(){return _numID;} 
};


#endif //WIERSZ_H
