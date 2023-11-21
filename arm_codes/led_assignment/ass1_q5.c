/*
  Write an ECP to find the second highest digit in a given integer and display its binary
equivalent on 8-LEDS (4-Active High LEDS& 4-Active Low LEDS). 

*/
#include <lpc21xx.h>
#define LEDS 0
int second(int num)
{
    int sh=-1,h=-1,rem;
	  while(num)
		{
		//	num /=10;
			rem= num%10;
			if(rem>h)
			{
				sh=h;
			   h=rem;
				// sh=h;
			}
		  else if( (rem>sh) && (rem !=h) )
			{
			    sh=rem;
			}

      num /=10;			
		}
		
		return sh;
}
int main()
{
	 int num=5948,collect;
   IODIR0= 0X0F;
	 IOPIN0= 0X0F;
	
	 collect=second(num);
    IOPIN0 =	IOPIN0 ^ (collect<<LEDS);
	 while(1);
}
