/*   . Create a display on 8 LED’s (4-active high and 4-active low) connected to port0 (0.0-
0.7) in the given pattern.
a. First all LEDs should be OFF, at 1st second, LED 0 and LED 7 (P0.0 and
P0.7) should be ON
b. At 2nd second, LED 1 and LED 6 (P0.1 and P0.6) should be ON
c. At 3rd second, LED 2 and LED 5 (P0.2 and P0.5) should be ON
d. At 4th second, LED 3 and LED 4 (P0.3 and P0.4) should be ON
e. Repeat above pattern for 5 times and stop the process. 
*/

#include <lpc21xx.h>
#include "delay.h"
#define LEDS 0
main()
{
	  int i=0,j=0;
    IODIR0=0XFF;
	  IOPIN0=0X0F;
	  delay_s(1);
	  
	  for(i=0;i<=4;i++)
	  {
		  for(j=0;j<=3;j++)                                      //  1st type of pattern
			{
				IOPIN0=IOPIN0 ^ ((1<<(7-j)) |(1<<j));
				 delay_s(1);
			   
			}
			
			/*
			for(j=3;j>=0;j--)                                    // 2nd type of pattern 
			{
				IOPIN0=IOPIN0 ^ ((1<<(7-j)) |(1<<j));
				 delay_s(1);
			   
			}
			
		}
			*/
		IOPIN0 =0X0F;
		while(1);
}
