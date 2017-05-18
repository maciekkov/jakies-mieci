#include "ControlSystem.h"

using namespace std;
 extern int lcd;
ControlSystem::ControlSystem()
{
 
	 
}
void ControlSystem::inicializuj()
{
	lotek->wczytaj();
	 
	 wiringPiSetup();
    
    gpio13->export_gpio();
    gpio19->export_gpio();
    gpio26->export_gpio();

    gpio13->setdir_gpio("in");
    gpio19->setdir_gpio("in");
    gpio26->setdir_gpio("in");

    cout<<"GPIO & LCD READY!!"<<endl;
}
int ControlSystem::antyNois(int numGpio)
{ 
	string  stangpio;
	 switch(numGpio)
	 {
		 case 13:
				gpio13->getval_gpio(stangpio);
				if(stangpio=="0")
				{
					usleep(20000);
					gpio13->getval_gpio(stangpio);
					if(stangpio=="0")
					return 0;
				}			
		 case 19:
				gpio19->getval_gpio(stangpio);
				if(stangpio=="0")
				{
					usleep(20000);
					gpio19->getval_gpio(stangpio);
						if(stangpio=="0")
					return 0;
				}
		 case 26:
				gpio26->getval_gpio(stangpio);
				if(stangpio=="0")
				{
					usleep(20000);
					gpio26->getval_gpio(stangpio);
						if(stangpio=="0")
					return 0;
				}			 
		default:
				return 1;			
	}
}
void ControlSystem::uruchom()
{ 
	 
	lcdClear(lcd);
	lcdPosition(lcd,0,5);
	string bufor="PRESS SET";
	string stangpio;
	
	int num=0;
	int numid=0;
	const char* napis;
	napis=bufor.c_str();
	lcdPuts(lcd,napis);	
		while(1){
			gpio26->getval_gpio(stangpio);
			if(stangpio=="0")
			if(!antyNois(26))
			{
				lcdClear(lcd);
				lcdPosition(lcd,0,0);
				bufor=menu->menuName();
				napis=bufor.c_str();
				lcdPuts(lcd,napis);	
				usleep(1000000);
				
			
			while(1)
			{   
					usleep(50000);
					gpio13->getval_gpio(stangpio);
					if(stangpio=="0")
					if(!antyNois(13))
					{ 	++num;
						if(num>3)
					num=0;
					lcdClear(lcd);
					bufor=menu->getVectorName(num);
					napis=bufor.c_str();
					lcdPuts(lcd,napis);
					
					
					} 
				    gpio19->getval_gpio(stangpio);
				    if(stangpio=="0")
					if(!antyNois(19))
					{	--num;
						if(num<0)
						num=3;
						lcdClear(lcd);
						bufor=menu->getVectorName(num);
						napis=bufor.c_str();
						lcdPuts(lcd,napis);		
			        }
				    gpio26->getval_gpio(stangpio);
				    if(stangpio=="0")
					{
						 
						numid=menu->getVectorID(num);
						wykonaj(numid);
					}
		        }			
	        }
	   }			
}
void ControlSystem::wykonaj(int numID)
{
	switch(numID)
	{
		case 1:
		lotek->graj();
		break;
		case 2:
		lotek->dodaj();
		break;
		case 3:
		lotek->usun();
		break;
		case 4:
		lotek->wyswietl();
		break;
		default:
		break;
	}
}
 int  ControlSystem::holdButton()
 {
	 string stangpio;
	 const clock_t begin_time = clock();
		while(stangpio=="0"){
			gpio26->getval_gpio(stangpio);
		}
    return int( clock () - begin_time ) /  CLOCKS_PER_SEC;
	 
 }
ControlSystem::~ControlSystem()
{
   delete  gpio26;
   delete  gpio19;
   delete  gpio13;
   delete 	menu ;
}
