// Write an ECP to display binary equivalent of prime numbers within the range of 0-50
// @ 5 seconds. (Note: Use IsPrime() function) 
#include <lpc21xx.h>

void delay_s(unsigned int delays)
{
    delays= delays*12000000;
	  while(--delays);
}
int prime(int n)
{
   int i=2;
	for(;i<n;i++)
	{ 
	  if(n%i==0)
		{
		    return 0;
		}
	}
	return 1;
}

int main()
{
	int max = 50,i;
	IODIR0=0Xff;
	IOPIN0=0X0f;
	for(i=2;i<=max;i++)
  {
	  if(prime(i))
		{
		  IOPIN0= (IOPIN0 ^ (i<<0));
			delay_s(5);
			
		}
		IOPIN0=0X0f;
	}
}
