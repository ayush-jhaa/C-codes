#include<lpc214x.h>

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void delay_ms(unsigned int);
void delay_s(unsigned int);

#define SETBIT(WORD,BITPOS) (WORD|=(1<<BITPOS))
#define CLRBIT(WORD,BITPOS) (WORD&=~(1<<BITPOS))
#define WRITEBYTE(WORD,BITPOS,BYTE) (WORD=(WORD&~(255<<BITPOS))|((BYTE)<<BITPOS))

#define CA7SEGMUX 0

#define SEL1 16
#define SEL2 17

const u8 seg_lut[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};

int isprime(int n)
{
   int i,flag=1;
	// int num=2;

	    for(i=2;i<n;i++)
	    {
				   flag=1;
			     if(n%i==0)
					 {
					    flag=0;
						  break;
					 }
			}
			if(flag)
				return 1;
			
			else
				return 0;
}
	
int main()
{
 int sum ,n=2;
WRITEBYTE(IODIR0,CA7SEGMUX,0XFF);
SETBIT(IODIR1,SEL1);
SETBIT(IODIR1,SEL2);

while(1)
{
	if(n>99)
		n=2;
	if(isprime(n))
	sum=n;
	
	n++;
WRITEBYTE(IOPIN0,CA7SEGMUX,seg_lut[sum/10]);
SETBIT(IOSET1,SEL1);
delay_ms(1);
SETBIT(IOCLR1,SEL1);
WRITEBYTE(IOPIN0,CA7SEGMUX,seg_lut[sum%10]);
SETBIT(IOSET1,SEL2);
delay_ms(1);
SETBIT(IOCLR1,SEL2); 
	//delay_s(1);
	
}
}


void delay_ms(unsigned int count)
{
 unsigned int i,j;
 for(j=0;j<count;j++)
 {
 for(i=0;i<300000;i++);
 }
}

/*void delay_s(unsigned int count)
{
 unsigned int i,j;
 for(j=0;j<count;j++)
 {
 for(i=0;i<1000000;i++);
 }
}
*/
