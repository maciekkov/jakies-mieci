#include <iostream>
 
#include "ControlSystem.h"

using namespace std;
int lcd;
int main()
{
	 lcd = lcdInit (2, 16,4, 3, 0,6, 1, 5,4,0,0,0,0);
    if(lcd)
    {
        cout<<"Error:Screen initializer"<<endl;
        exit(-1);
    }
    
	ControlSystem * control=new ControlSystem;
	control->inicializuj();
	control->uruchom();

    return 0;
}
