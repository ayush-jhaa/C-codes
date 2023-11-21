/*  Create a display on 8 LED’s (4-active high and 4-active low) using 4 active low
switches connected to port0 (0.16-0.19) in the pattern explained:
a. First all LEDs should be OFF.
b) if 1st switch is pressed, LED 0 and LED 7 (P0.0 and P0.7) should be ON
c) if 2nd switch is pressed, LED 1 and LED 6 (P0.1 and P0.6) should be ON
d) if 3rd switch is pressed, LED 2 and LED 5 (P0.2 and P0.5) should be ON
e) if 4th switch is pressed, LED 3 and LED 4 (P0.3 and P0.4) should be ON 
*/

#include <lpc21xx.h>
#define SW1 16
#define SW2 17
#define SW3 18
#define SW4 19
#define READBIT(WORD,BITPOS) ((WORD>>BITPOS)&1)
int main()
{
    IODIR0=0Xff;
	
	while(1)
	{		
	IOPIN0=0X0f;
	
	  if(!(READBIT(IOPIN0,SW1)))
		{
			  IOPIN0 = IOPIN0^ ((1<<7)|(1<<0));
		    while(!(READBIT(IOPIN0,SW1)));
		}
	//	IOPIN0=0X0f;
		else if(!(READBIT(IOPIN0,SW2)))
		{
			    IOPIN0 = IOPIN0^ ((1<<6)|(1<<1));
		     while(!(READBIT(IOPIN0,SW2)));
		}
	//	IOPIN0=0X0f;
		else if(!(READBIT(IOPIN0,SW3)))
		{
			    IOPIN0 = IOPIN0^ ((1<<5)|(1<<2));
		     while(!(READBIT(IOPIN0,SW3)));
		}
		else if(!(READBIT(IOPIN0,SW4)))
		{ 
			    IOPIN0 = IOPIN0^ ((1<<4)|(1<<3));
		     while(!(READBIT(IOPIN0,SW4)));
		}
  
}
	}
