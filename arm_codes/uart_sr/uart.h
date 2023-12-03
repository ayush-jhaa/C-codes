void initUart(void);
void sendUart(unsigned char mydata);
unsigned  char recieveUart(void);
void printUart( unsigned char mydata[]);

void initUart(void)
{
   PINSEL0=0X05;
	 U0LCR=0X83;  // DLAB=1 ,11 8bit uart
	 U0DLL=0X87;   // setting the baud rate
	 U0DLM=0X01; 
	 U0LCR=0X03;  // after setting baud rate clear dlab bit=0 for using thr and rbr register.
	
}
void sendUart(unsigned char mydata)
{
    U0THR =mydata;
	  
	  while( (U0LSR &(0X01<<5))==0); //THRE
}

unsigned  char recieveUart(void)
{
	  unsigned char mydata;
    while(((U0LSR) &(0X01))==0);
	  mydata= U0RBR;
	  return mydata;
}

void printUart(unsigned char mydata[])
{
     unsigned int i=0;
	   while(mydata[i] != '\0')
		 {
		    sendUart(mydata[i]);
			  i++;
		 }
}
