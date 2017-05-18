#ifndef CONTROLSYSTEM_H
#define CONTROLSYSTEM_H


#include <iostream>
#include <wiringPi.h>
#include <lcd.h>
#include <cstdlib>
 #include "Device.h"
 #include "Menu.h"
 #include <unistd.h>
 #include <string.h>
 
using namespace std;

class ControlSystem
{
private:
	Menu* menu = new Menu("DUZY LOTEK");
    Duzy_lotek* lotek=new Duzy_lotek;
    string status;
   
public:
	Device* gpio26=new Device("26");
    Device* gpio19=new Device("19");
  Device* gpio13=new Device("13");
    ControlSystem();
   int antyNois(int numGpio);
    void inicializuj();
    void uruchom();
    int   holdButton();
     void wykonaj(int numID);
     friend class Duzy_lotek;
   
    virtual ~ControlSystem();


};

#endif // CONTROLSYSTEM_H
