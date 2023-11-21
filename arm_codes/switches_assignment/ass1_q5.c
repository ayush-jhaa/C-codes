// switches 5th question assignment 1
/*
         5. PART2: Implement up and down counter. Use two AL switches and 8 leds (4-active
                  high leds and 4-active low leds) as mentioned:
                  As long as sw1 is pressed increment the count value with respect to 1 sec
                  As long as sw2 is pressed decrement count value with respect to 1 sec
                  And display updated count on leds.
                  If both switches are pressed at a time, don’t do any operation on count.
            Note: if count value is 0, at this time if sw2 pressed it should display 0 only on leds and if
                 count value is 255 then if sw1 pressed it should display 255 only on leds. 

*/

#include <lpc21xx.h>
#define SW1 16   // increament count  both swiches are active low
#define SW2 17   // decreament count
#define READBIT(WORD,BITPOS) ((WORD>>BITPOS)&1)

void delay_s(unsigned int delays)
{
   delays *=1200000;
	while(--delays);
}
int main()
{
   int count=0;
	IODIR0=0XFF;
	IOPIN0=0X0F;
	while(1)
	{
	    if(!(READBIT(IOPIN0,SW1)))
			{   
				   IOPIN0=0X0F;
			     ++count;
				 if(count>=255)
				 {
				   IOPIN0=0x0f;
				 }
				 else
				 {
				   IOPIN0= (IOPIN0^(count<<0));
				 }
				 delay_s(1);
				
				
				 
			}
			
			else if(!(READBIT(IOPIN0,SW2)))
			{
				    IOPIN0=0X0F;
			     --count;
				if(count<=0)
				 {
				   IOPIN0=0x0f;
				 }
				 else
				 {
				   IOPIN0= (IOPIN0^(count<<0));
				 }
				 delay_s(1);
			
			}
	}
}
