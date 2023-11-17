#include<lpc21xx.h>
#include "types.h"
#include "delay.h"
#include "defines.h"
#include "lcd_defines.h"

int prime(int);
int main()
{
   u8 keyp;
   u32 temp=0;
   InitLCD();
   InitKPM();

   while(1)
   {
        keyp=keyscan();
                if(keyscan()>=0 && keyscan()<=9)
                {
        temp= temp*10 + (keyp-0);
					charLCD(keyp+48);
                }
                else if(keyscan()==14)
                {
									delay_ms(500);
									charLCD(CLEAR_LCD);
                  if(prime(temp))
                  {
                    strLCD("prime");
                        delay_s(2);
                        cmdLCD(CLEAR_LCD);
                  }
                  else
                  {
                     strLCD("NON PRIME");
                         delay_s(2);
                        cmdLCD(CLEAR_LCD);
                  }
                  temp=0;
                }


                while(!colscan());
   }
}
int prime(int num)
{
    u32 i;
        for(i=2;i<num;i++)
        {
            if(num%i==0)
                {
                  break;
                }
        }
        if(i==num)
        {
            return 1;
        }
        else
        {
           return 0;
        }
}
