/*  switches question 6

    . Write an ECP to fulfill the below mentioned operations.
       1. Initially all leds should be off.
       2. Display even numbers on 8 leds with respect to 1 second if sw1 is pressed.
           Continue this process until sw2 is pressed.
       3. Display odd numbers on 8 leds with respect to 1 second if sw2 is pressed.
          Continue this process until sw1 is pressed.
        Note: if number is >255 then roll over to 0 and repeat the operation. 
*/
#include <lpc21xx.h>
#define SW1 16
#define SW2 17
#define READBIT(WORD,BITPOS) ((WORD>>BITPOS)&1)
void delay_s(unsigned int delays)
{
   delays=delays*1200000;
	 while(--delays);
}
int main()
{
	int num;
	IODIR0=0XFF;
	IOPIN0=0X0F;
	
	
	
	while(1)
	{
	    while(!(READBIT(IOPIN0,SW1)))
			{
				num=0;
				  while((READBIT(IOPIN0,SW2)))
				{
			    if(num%2==0)
					{
						 IOPIN0=0X0F;
					   IOPIN0=(IOPIN0^(num>>0));
					}
					delay_s(1);
					num++;
				}
				break;
			
			}
			while(!(READBIT(IOPIN0,SW2)))
			{
				  num=0;
				while((READBIT(IOPIN0,SW1)))
				{
			     if(num%2==1)
           {
						   IOPIN0=0X0F;
					     IOPIN0=(IOPIN0^(num>>0));
					    }
					 delay_s(1);
							num++;
				  }
         break;				
	  	}
}
	
	

   }
