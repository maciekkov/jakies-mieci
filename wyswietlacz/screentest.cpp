#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <wiringPi.h>
#include <lcd.h>
#include <string.h>
#include <time.h>
 
char level0[8] = { 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b11111};
char level1[8] = { 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b11111, 0b11111};
char level2[8] = { 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b11111, 0b11111, 0b11111};
char level3[8] = { 0b00000, 0b00000, 0b00000, 0b00000, 0b11111, 0b11111, 0b11111, 0b11111};
char level4[8] = { 0b00000, 0b00000, 0b00000, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111};
char level5[8] = { 0b00000, 0b00000, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111};
char level6[8] = { 0b00000, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111};
char level7[8] = { 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111};
 
#define COLUMNS 16
#define LCD_RS  3
#define LCD_E   0
#define LCD_D4  6
#define LCD_D5  1
#define LCD_D6  5
#define LCD_D7  4
 
void uptime(void);
void memory(void);
void volume(void);
void scrollText(void);
void INThandler(int sig);
int mymillis(void);
 
char message[] = "WWW.OZZMAKER.COM";
int count =0;
int j = 0;
FILE *uptime_file, *mem_file;
char *temp;
int lcd;
 
int main()
{
        signal(SIGINT, INThandler);
 
        wiringPiSetup () ;
 
        if (lcd = lcdInit (2, 16,4, LCD_RS, LCD_E ,LCD_D4 , LCD_D5, LCD_D6,LCD_D7,0,0,0,0)){
                printf ("lcdInit failed! \n");
                 return -1 ;
        }
 
        int uptimeTimer;
 
        while(1){
                lcdClear (lcd);
                volume();
                sleep(1);
                memory();
                sleep(4);
                lcdClear (lcd);
                uptimeTimer  = mymillis();
                while ((mymillis() - uptimeTimer) < 5000)
                        uptime();
                sleep(1);
                lcdClear (lcd);
 
                scrollText();
        }
 
}
 
void uptime(void)
{
  unsigned int uptime_unsorted = 0;
  unsigned char c;
  unsigned int DD;
  unsigned int HH;
  unsigned int MM;
  unsigned int SS;
 
  uptime_file=fopen("/proc/uptime","r");
 
  if(NULL != uptime_file)
  {
    while((c=fgetc(uptime_file))!= '.')
      {
        unsigned int i;
        i = atoi(&c);
        uptime_unsorted = (uptime_unsorted * 10) + i;
      }
    SS = uptime_unsorted % 60;
    MM = uptime_unsorted / 60 % 60;
    HH = uptime_unsorted / 60 / 60 % 24;
    DD = uptime_unsorted / 60 / 60 / 24;
    printf("\x1B[2J");
 
    printf("Uptime:D%i,%02i:%02i:%02i\n",DD,HH,MM,SS);
    lcdPosition(lcd,0,0);
    lcdPrintf(lcd,"Uptime:  Days %i", DD);
 
    lcdPosition(lcd,4,1);
    lcdPrintf(lcd,"%02i:%02i:%02i",HH,MM,SS);
 
  }
  else
  {
    printf("Open file \"proc/uptime\" failed!\n");
  }
}
void memory(void)
{
   char MemTotal[35];
    char MemFree[35];
    char total[35];
    char free[35];
        lcdClear (lcd);
 
    mem_file=fopen("/proc/meminfo","r");
 
    if(NULL != mem_file)
    {
    fscanf(mem_file,"%*s%s%*s", MemTotal);
    fscanf(mem_file,"%*s%s%*s", MemFree);
    printf("\x1B[2J");
 
    lcdPosition(lcd,0,0);
    lcdPrintf(lcd,"MemTotal-%sk",MemTotal);
    lcdPosition(lcd,0,1);
    lcdPrintf(lcd,"MemFree -%sk",MemFree);
    fclose(mem_file);
  }
  else
  {
    printf("Open file \"/proc/meminfo\" failed!\n");
  }
}
 
void volume(void)
{
         //Defined custom characters for volume display
        lcdCharDef  (lcd, 0, level0);
        lcdCharDef  (lcd, 1, level1);
        lcdCharDef  (lcd, 2, level2);
        lcdCharDef  (lcd, 3, level3);
        lcdCharDef  (lcd, 4, level4);
        lcdCharDef  (lcd, 5, level5);
        lcdCharDef  (lcd, 6, level6);
        lcdCharDef  (lcd, 7, level7);
 
        lcdClear (lcd);
 
        int i;
        lcdPosition (lcd, 9,1);
        lcdPuts (lcd, ":Volume");
        for (i = 0; i < 7; i++){
                lcdPosition (lcd, i, 1);
                lcdPutchar  (lcd, i);
                usleep(400000);
        }
}
 
void  scrollText(void)
{
        int i,n;
        int h ;
        int tempSpace = 0;
        char scrollPadding[] = "                   ";
 
        int messageLength = strlen (scrollPadding)+strlen(message);
        for (n=0;n<messageLength;n++){ h = COLUMNS; usleep(300000); printf("\x1B[2J"); if ( j > messageLength )
                        j = 0;
                for (i = 0  ; i  < j ; i ++){
                        scrollPadding[h-j] = message[ i];
                h++;
                }
                lcdPosition(lcd,0,0);
                lcdClear (lcd);
                lcdPrintf(lcd,"%s",scrollPadding);
                j++;
        }
 
}
 
void  INThandler(int sig)
{
        lcdClear (lcd);
        fclose(uptime_file);
        signal(sig, SIG_IGN);
        exit(0);
}
 
int mymillis(void)
{
        struct timeval tv;
        gettimeofday(&tv, NULL);
        return (tv.tv_sec) * 1000 + (tv.tv_usec)/1000;
}
