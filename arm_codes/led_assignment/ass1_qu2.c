#include <lpc21xx.h>
#include "delay.h"
#define LEDS 0
main()
{
	  int i=0;
    IODIR0=0XFF;
	  IOPIN0=0X0F;
	  
	  for(i=0;i<=7;i++)
	  {
		   IOPIN0=IOPIN0^1 << i;

			 delay_ms(500);
		}
		IOPIN0 =0X0F;
		while(1);
}
