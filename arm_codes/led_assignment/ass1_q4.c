// 0-255 binary display 4 active low 4 active high

#include <lpc21xx.h>
#include "delay.h"
#define LEDS 0
main()
{
	  int i=0,j=0;
    IODIR0=0XFF;
	  IOPIN0=0X0F;
	  delay_s(1);
	  
	  for(i=0;i<=255;i++)
	  {
	    IOPIN0 =(IOPIN0 ^(i<<LEDS));
			delay_ms(200);
		}
		IOPIN0 =0X0F;
		while(1);
}
