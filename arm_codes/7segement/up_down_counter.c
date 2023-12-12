
#include<lpc214x.h>
/*
#include"TYPES.h"
#include"DELAY.h"
*#include"DEFINES1.h"*/

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void delay_ms(unsigned int);

#define SETBIT(WORD,BITPOS) (WORD|=(1<<BITPOS))
#define CLRBIT(WORD,BITPOS) (WORD&=~(1<<BITPOS))
#define WRITEBYTE(WORD,BITPOS,BYTE) (WORD=(WORD&~(255<<BITPOS))|((BYTE)<<BITPOS))

#define CA7SEGMUX 0

#define SEL1 16
#define SEL2 17

const u8 seg_lut[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};

int main()
{
	int count=0;
	

WRITEBYTE(IODIR0,CA7SEGMUX,0XFF);
SETBIT(IODIR1,SEL1);
SETBIT(IODIR1,SEL2);

while(1)
{
	while( !((IOPIN0>>12)&1))
	{
		if(count==99)
			count=99;
		else
	   count++;
		 while( !((IOPIN0>>12)&1));
		
		while( ((IOPIN0>>12)&1))
	  {
		
			WRITEBYTE(IOPIN0,CA7SEGMUX,seg_lut[count/10]);
			SETBIT(IOSET1,SEL1);
			delay_ms(1);
			SETBIT(IOCLR1,SEL1);
			WRITEBYTE(IOPIN0,CA7SEGMUX,seg_lut[count%10]);
			SETBIT(IOSET1,SEL2);
			delay_ms(1);
			SETBIT(IOCLR1,SEL2);
			
			if ( !((IOPIN0>>21)&1))
				break;
		
		}	
        break;		
	}
	
	while(!((IOPIN0>>21)&1))
				 {
					 if(count==0)
						 count=0;
					 else
				      count--;
					    while(!((IOPIN0>>21)&1));
					 
					    while( ((IOPIN0>>21)&1))
							{
		
									WRITEBYTE(IOPIN0,CA7SEGMUX,seg_lut[count/10]);
									SETBIT(IOSET1,SEL1);
									delay_ms(1);
									SETBIT(IOCLR1,SEL1);
									WRITEBYTE(IOPIN0,CA7SEGMUX,seg_lut[count%10]);
									SETBIT(IOSET1,SEL2);
									delay_ms(1);
									SETBIT(IOCLR1,SEL2);
								
										if( !((IOPIN0>>12)&1))
												break;
							}
							break;
				 }
	
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
