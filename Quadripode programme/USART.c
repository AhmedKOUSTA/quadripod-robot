#include<avr/io.h>


//************************************
//*****   initaialisation USART
//***********************************
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


  
//************************************
//*****  lire caractere
//***********************************
char USARTReadChar()
{

   while(!(UCSRA & (1<<RXC)))
   {
      //Do nothing
   }

   return UDR;
}



//************************************
//*****   ecrire caractere
//***********************************
void USARTWriteChar(char data)
{

   while(!(UCSRA & (1<<UDRE)))
   {
      //Do nothing
   }
   UDR=data;
}



//************************************
//*****   roteur a la ligne
//***********************************
void USART_newline(void)
{
         USARTWriteChar('\r');
		 USARTWriteChar('\n');

  return;
}


//************************************
//*****   ecrire chaine de caractere
//***********************************
void USARTWrite_S_Char(char *data)
{
   unsigned char c;

   while(*data)
   {
      USARTWriteChar(*data++);
   }
   USART_newline();
   return;
   
}




