#include "lpc21xx.h"
#include "uart.h"
#include "delay.h"

int main()
{
	unsigned char serdata;
    initUart();
	  while(1)
		{
		    // sendUart('A');
			 // printUart("vector india ");
			 //sendUart(13); //CR
	   //   sendUart(10); //LF
			 //  delay_ms(500);
		   
			/* serdata=recieveUart();
			 if(serdata=='a')
			{
			    IODIR0=0XF00;
				  IOPIN0= 1<<8;
			}
			
				else if(serdata=='b')
			{
			    IODIR0=0XF00;
				  IOPIN0= 1<<9;
			}
			*/
			
			serdata=recieveUart();
			if((serdata >='a') && (serdata<='z') )
			{
			IODIR0=0xff00;
			IOPIN0= ((IOPIN0) |(serdata<<8));
      }	
      
      			
		}
}
