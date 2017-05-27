#include<avr/io.h>


void USARTInit(uint16_t ubrr_value)
{

   //Set Baud rate

   UBRRL = ubrr_value;
   UBRRH = (ubrr_value>>8);

   /*Set Frame Format


   >> Asynchronous mode
   >> No Parity
   >> 1 StopBit

   >> char size 8

   */

   UCSRC=(1<<URSEL)|(3<<UCSZ0);


   //Enable The receiver and transmitter

   UCSRB=(1<<RXEN)|(1<<TXEN);


}


//This function is used to read the available data
//from USART. This function will wait untill data is
//available.
char USARTReadChar()
{
   //Wait untill a data is available

   while(!(UCSRA & (1<<RXC)))
   {
      //Do nothing
   }

   //Now USART has got data from host
   //and is available is buffer

   return UDR;
}

//This fuction writes the given "data" to
//the USART which then transmit it via TX line
void USARTWriteChar(char data)
{
   //Wait untill the transmitter is ready

   while(!(UCSRA & (1<<UDRE)))
   {
      //Do nothing
   }

   //Now write the data to USART buffer

   UDR=data;
}

void USART_newline(void)
{
    USARTWriteChar('\r');
		 USARTWriteChar('\n');

  return;
}

void USARTWrite_S_Char(char *data)
{
   unsigned char c;

   while(*data)
   {
      USARTWriteChar(*data++);
   }
   USART_newline();
   return;
   //Now write the data to USART buffer
}

char char2int(char a)
{
    if ((a>='0') && (a<='9'))   return (a-48);
	else  { 
		USARTWrite_S_Char(" this is not a nomber");
		return 0;   // optimisation: fonction goto
	}
}
char read_nomber(void)
    {
	 char data;
	 char data1;
	 char data2;
	 char data3;
	 char data4;

	 data1=USARTReadChar();
	 USARTWriteChar(data1);
	 data1=char2int(data1);

	 data2=USARTReadChar();
	 USARTWriteChar(data2);
	 data2=char2int(data2);

	 data3=USARTReadChar();
	 USARTWriteChar(data3);
	 data3=char2int(data3);

     data4=USARTReadChar();
	 USARTWriteChar(data4);
	 data4=char2int(data4);


	 data=(data1*1000)+(data2*100)+(data3*10)+data4;


	 return data;
	}

