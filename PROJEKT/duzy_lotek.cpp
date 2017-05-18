#include "duzy_lotek.h"


using namespace std;
extern int lcd;
Duzy_lotek::Duzy_lotek(){
   
   
}
Duzy_lotek::~Duzy_lotek()
{

}
void Duzy_lotek::wczytaj()
{
    fstream file;
     file.open("wyniki.txt");
    if(file.fail())
       {
        cout<<"Error:nie mozna zaladowac pliku \"wyniki.txt\""<<endl;
        exit (-1);
    }
    string bufor;
    while(getline(file,bufor))
    {
        _wyniki.push_back(bufor);
    }
    file.close();
}
void Duzy_lotek::wyswietl()
{
	const char* bufor;
	
		for(int i=0;i<10;i++)
		{
			bufor=_wyniki[i].c_str();
			lcdPuts(lcd,bufor);
		} 
		
}
 void Duzy_lotek::dodaj()
 {

   int num=0;
    int tab[6];
    ostringstream ss;
    string stangpio;
 
    
    for(int i=0; i<6; ++i)
    {
        while(holdButton()<2)
        {
            lcdClear(lcd);
            lcdPrintf(lcd,"PUT YOUR NUMBER:");
             
			if( holdButton()>1);
			{
				   ControlSystem::gpio13->getval_gpio(stangpio);
            if(stangpio=="0")
            if(!antyNois(13))
            {
				lcdClear(lcd);
				lcdPosition(lcd,0,13);
                lcdPrintf(lcd,"%c",num);
                ++num;
                
                if(num>49)
                    num-=49;
            }
			 gpio19->getval_gpio(stangpio);
			if(stangpio=="0")
            if(!antyNois(19))
            {
				lcdClear(lcd);
				lcdPosition(lcd,0,13);
                lcdPrintf(lcd,"%c",num);
                --num;
                  if(num<0)
                    num+=49;
            }
            gpio26->getval_gpio(stangpio);
             if(stangpio=="0")
             if(!antyNois(26))
            {
                 tab[i]=num;
                for(int k=0; k<i; k++)
                {
                    if(tab[i]==tab[k])
                    {
                        lcdPrintf(lcd,"CHOOSE NUMBER       AGAIN");
						usleep(2000000);
                        break;
                    }
                }
            }
        }
	}
 
    }



    string bufor;
    for(int i=0;i<6;i++){
		ss<<tab[i];
      bufor+= ss.str();
  }
     _wyniki.push_back(bufor);

 }

