#ifndef DEVICE_H
#define DEVICE_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
 
class Device
{
public:
    Device();  // create a GPIO object that controls GPIO4 (default
    Device(string x); // create a GPIO object that controls GPIOx, where x is passed to this constructor
    int export_gpio(); // exports GPIO
    int unexport_gpio(); // unexport GPIO
    int setdir_gpio(string dir); // Set GPIO Direction
    int setval_gpio(string val); // Set GPIO Value (putput pins)
    int getval_gpio(string& val); // Get GPIO Value (input/ output pins)
    string get_gpionum(); // return the GPIO number associated with the instance of an object
    
private:
    string gpionum; // GPIO number associated with the instance of an object
};

#endif
