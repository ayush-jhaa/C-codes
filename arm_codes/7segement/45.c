Non-Multiplexing

Display 0 to 9 on segment 1
#include<lpc21xx.h>

void delay_ms(unsigned int);
unsigned int i,j,k;

unsigned int a[16]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8, 0x80,0x90};

int main()
{
IODIR0=0X000000FF; 

while(1)
{
for(i=0;i<10;i++)
 {
 IOPIN0=a[i];
 delay_ms(1000);
 }
 }
}

void delay_ms(unsigned int count)
{
unsigned int i,j;
for(j=0;j<count;j++)
{
for(i=0;i<2000;i++);
}
}
-----------------------------------------------------------------------------
MULTIPLEXING

Display 4 on segment1 and 5 on segment2

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
#define WRITEBYTE(WORD,BITPOS,BYTE) 
(WORD=(WORD&~(255<<BITPOS))|((BYTE)<<BITPOS))

#define CA7SEGMUX 0

#define SEL1 8
#define SEL2 9

const u8 seg_lut[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};

int main()
{
u8 n=45;
WRITEBYTE(IODIR0,CA7SEGMUX,0XFF);
SETBIT(IODIR0,SEL1);
SETBIT(IODIR0,SEL2);

while(1)
	{
WRITEBYTE(IOPIN0,CA7SEGMUX,seg_lut[n/10]);
SETBIT(IOSET0,SEL1);
delay_ms(1);
SETBIT(IOCLR0,SEL1);
WRITEBYTE(IOPIN0,CA7SEGMUX,seg_lut[n%10]);
SETBIT(IOSET0,SEL2);
delay_ms(1);
SETBIT(IOCLR0,SEL2); 
	}

}


void delay_ms(unsigned int count)
{
 unsigned int i,j;
 for(j=0;j<count;j++)
 {
 for(i=0;i<2000;i++);
 }
}
