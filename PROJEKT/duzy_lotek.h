#ifndef DUZY_LOTEK_H
#define DUZY_LOTEK_H
 
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <unistd.h>
#include <wiringPi.h>
#include <lcd.h>
#include "Device.h"
#include "ControlSystem.h"
using namespace std;

class Duzy_lotek :public ControlSystem
{
private:
    vector<string>_wyniki;
    Device* device=new Device;
     
public:
    Duzy_lotek();
    void wczytaj();
    void wyswietl();
    void dodaj();
    void graj(){}
    void usun(){}
    friend class ControlSystem;
    virtual ~Duzy_lotek();


};

#endif // DUZY_LOTEK_H
