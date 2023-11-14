#include <lpc21xx.h>
#include "defines.h"
#include "delay.h"
#define LEDS 8  // O.O to 0.3 active low // 0.4 to 0.7 active high
int main()
{
	  u8 keyv=0; 
	  InitKPM();
    WRITEBYTE(IODIR0, LEDS, 0XFF); //  
	  WRITEBYTE(IOPIN0, LEDS, 0X0F);
	  while(1)
		{	
		if((keyscan()>=0) && (keyscan()<10))
		{
	  keyv=keyv*10+keyscan();
		}
		else if(keyscan()>=10)
		{
     IOPIN0 = (IOPIN0 & 0x0F00);
		 IOPIN0 =(IOPIN0 |0X0F00);
			IOPIN0= IOPIN0^ (keyv << LEDS);
    }
		
		while(!colscan());
					} 
}
