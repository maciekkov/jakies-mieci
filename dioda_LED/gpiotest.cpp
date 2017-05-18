#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "gpio_class.h"

using namespace std;

int main (void)
{
	bool USER = true;
    string inputstate;
    GPIOClass* gpio4  = new GPIOClass("4"); //create new GPIO object to be attached to  GPIO4
    GPIOClass* gpio17 = new GPIOClass("17"); //create new GPIO object to be attached to  GPIO17
	GPIOClass* gpio19 = new GPIOClass("19");
	GPIOClass* gpio6  = new GPIOClass("6");
	
    gpio4 ->export_gpio(); //export GPIO4
    gpio17->export_gpio(); //export GPIO17
    gpio19->export_gpio(); //export GPIO22
    gpio6 ->export_gpio(); //export GPIO6
    cout << " GPIO pins exported" << endl;

    gpio17->setdir_gpio("in"); //GPIO17 set to output
    gpio4 ->setdir_gpio("out"); // GPIO4 set to input
    gpio6 ->setdir_gpio("out"); // GPIO6 set to input
    gpio19 ->setdir_gpio("out"); // GPIO22 set to input

    cout << " Set GPIO pin directions" << endl;
	   
	       gpio4 ->setval_gpio("0");
			gpio6 ->setval_gpio("0");
			gpio19->setval_gpio("0");
	 
	while(USER)
	{
	 gpio17->getval_gpio(inputstate);
		if(inputstate=="0")
		{
		
			while(1){
		  int time=10;
			system("clear");
		  gpio19->setval_gpio("0");
		   cout<<"STOP"<<endl;
		 gpio6 ->setval_gpio("1");
		
		 usleep(5000000);
		 cout<<"READY"<<endl;
		 usleep(1000000);
		 gpio19 ->setval_gpio("1");
		 usleep(1000000);
		 gpio6 ->setval_gpio("0");
		 gpio19->setval_gpio("0");
		 system("clear");
		 cout<<"GO!!!"<<endl;	
		 gpio4 ->setval_gpio("1");
		 while(time>0)
		 {
		 usleep(1000000);
		 time--;
		 system("clear");
		 cout<<"GO!!!"<<endl<<"   "<<time<<endl;
		 }
		 gpio19->setval_gpio("1");
		 usleep(1500000);
		 gpio4->setval_gpio("0");
		}
	}
}
    cout << "Exiting....." << endl;
    return 0;
}
