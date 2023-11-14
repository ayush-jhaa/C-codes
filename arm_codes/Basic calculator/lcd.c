// lcd.c
#include <lpc21xx.h>
#include "types.h"
#include "defines.h"
#include "delay.h"
#include "lcd_defines.h"
#include "types.h"


void writeLCD(u8 data)
{
  // cfg pin for wiritng to  lcd
	SCLRBIT(IOCLR0,LCD_RW);
	// WRITE TO THE DATA PINS ANY BYTE
	WRITEBYTE(IOPIN0,LCD_D0,data);
	
	
	//make enable high  
	SSETBIT(IOSET0,LCD_EN);
	delay_us(1);
	
	SSETBIT(IOCLR0,LCD_EN);
	delay_ms(2);
	
}

void cmdLCD(u8 cmd)
{
	 // select command register for writing to
	 SCLRBIT(IOCLR0,LCD_RS);
	
	 writeLCD(cmd);
}

void charLCD(u8 ch)
{
    SSETBIT(IOSET0,LCD_RS);
	  writeLCD(ch);
}

void InitLCD(void)
{
   WRITEBYTE(IODIR0,LCD_D0,0XFF);
	 SETBIT(IODIR0,LCD_RS);
	 SETBIT(IODIR0,LCD_RW);
	 SETBIT(IODIR0,LCD_EN);
	
	 delay_ms(15);
	 cmdLCD(0x30);
	 delay_ms(4);
	 delay_us(200);
	 cmdLCD(0x30);
	 delay_us(100);
	 cmdLCD(0x30);
	
	 cmdLCD	(MODE_8BIT_2LINE);
	 cmdLCD	(DSP_ON_CUR_OFF);
	 cmdLCD	(CLEAR_LCD);
	 cmdLCD	(SHIFT_DISP_RGT);
}

void strLCD(u8 *ptr)
{
   while(*ptr)
	 {
	    charLCD(*ptr++);
	 }
}

void  u32LCD(u32 n)
{
   u8 a[10];
	 s32 i=0;
	 if(n==0)
	 {
	   charLCD('0');
	 }
	 else
	 {
	   while(n)
		 {
		    a[i]=(n%10)+48;
			  n /=10;
			  i++;
		 }
		 
		 for(--i;i>=0;i--)
		 {
		     charLCD(a[i]);
		 }
	 }
}
 void s32LCD( s32 n)
 {
    if(n<0)
		{
		   charLCD('-');
			 n=-n;
		}
		
		u32LCD(n);
 }   

