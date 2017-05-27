#include<avr/io.h>
#include<avr/interrupt.h>
#define F_CPU 1000000UL
#include<util/delay.h>
#include "main.h"



//**************************************************
//****configuration du timer 1 pour les servo moteur
//**************************************************
void config_timer1(void)
    {
	 // configuration pour le servo
	 TCCR1B = (1 << WGM12)| (1 << CS10);
     OCR1A = PULSE_MAX_WIDTH + 10 ;
     OCR1B = PULSE_MED_WIDTH ;
     TCNT1 = OCR1B + 10 ;
     TIMSK = (1 << OCIE1A)| (1 << OCIE1B);

  
}


//**************************************************
//****configuration du timer 0 pour le capteur IR 
//**************************************************
void config_timer0(void)
{
	 TCCR0|=(1<<CS01)|(1<<CS00);
     TCNT0 = 0; //reset the timer
	 TIMSK=0x00;
}






//***************************************************
//***configuration des interface de sortie et entrée
//***************************************************
void config_interface(void)
    {
      DDRD|=0xfc;              //TX et RX et des sortie servo moteur
      DDRC=0XFF;               //les sortie de servo moteur
	  PORTB&=0b11111011;       //entrée du capteur IR 
	  DDRA=0b11111110;
	}



//************************
//*****   main
//************************
int main(void)
    {
     
     unsigned char count, code, address;

     int IR_input;
	char stat;


     USARTInit(25);                 //boud rate to 2400
     config_interface();            //configuration des entrée et des sortie de ATMEGA16
     config_timer0();               //configuration timer0 pour IR
	 config_timer1();               //configuration timer1 pour servo moteur
	


	 sei();                         //validé les interruption


	 stand_up_fast();               //initialisation
     

	 USARTWrite_S_Char("   ***********hello human***********  ");
	 USART_newline();
     
	 USARTWrite_S_Char("  This is the quadrapode robot what's your order ");
     USART_newline(); 

	 // boucle infini
     while(1)
	    { 
		if(!(PINA&0x01))
         {
          while((PINB & 0x04));
		  TCNT0 = 0;
         
          while(!(PINB & 0x04));      //while PD2=0
 
          count = TCNT0;
     
          if(count < 30)                   //startbit (2.4 ms)
          {
		 
 
           }
          else
		  {
        
           IR_input = read_IR ();
		
        
           code = (unsigned char) ((IR_input & 0xff00) >> 8);
            address = (unsigned char) (IR_input & 0x00ff);
       
           ordre_quad(code);
	  	   }
         }
		 else
		 {
		 etat=USARTReadChar(); 
         move_to();
		 }
		
        }
        
    }
