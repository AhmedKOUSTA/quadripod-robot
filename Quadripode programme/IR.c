#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>




#include "main.h"



//*********************************************************************
//***Function de lecture du code infra rouge
//*********************************************************************  
int read_IR (void)
{
    unsigned char pulseCount=0,  code = 0, address = 0, timerCount;
        unsigned int IR_input;
         
  
      // Commande

        while(pulseCount < 7)
        {
           while(PINB & 0x04);   // while PD2=1
           TCNT0 = 0;
           
           while(!(PINB & 0x04));  // while PD2=0
           pulseCount++;
         
           timerCount = TCNT0;
         
           if(timerCount > 14)
                   code = code | (1 << (pulseCount-1));
           else
                   code = code & ~(1 << (pulseCount-1));  
         }
   
      //Address

         pulseCount = 0;
         while(pulseCount < 5)
         {
           while(PINB & 0x04);
           TCNT0 = 0;
		   
           
           while(!(PINB & 0x04));
           pulseCount++;
         
           timerCount = TCNT0;
         
           if(timerCount > 14)
              address = address | (1 << (pulseCount-1));
           else
              address = address & ~(1 << (pulseCount-1));  
         }
     
	 //   Commande _Address       

         IR_input = (((unsigned int)code) << 8) | address;

         
		  
         return(IR_input);

		 
}


//*****************************
//***envoyer command au quad
//*****************************
void ordre_quad(char code)
{
   USARTWrite_S_Char(" ******SENDING TO MAIN *** ");
        USART_newline();
	switch(code)
	{
		case 0x19 : 
		            if(etat=='4')
					 {
					  etat='3';
					 }
					 else
					 {
					  etat='4';
					 }
		break;

		case 0x15 : etat='1';  //
		break;

		case 0x2D : etat='9';   // forward  serch
		break;

		case 0x17 : etat='6';   // moveleft  <<
		break;

		case 0x56 :  etat='7';   // move right  >>
		break;

		case 0x1B :  etat='B';   // turn left rew
		break;

    	case 0x1A : etat='8';    // gangnam style  play		  
		break;

		case 0x1C :  etat='C';   // turn right  FF
		break;

		case 0x18 :  etat='D';   // hello stop
		break;

		case 0x23 : etat='F';   // gangnam style 2  slow
		break;

     	case 0x47 :etat='E';   // gangnam style 2  slow
		break;

    	case 0x5A : etat='G';   // gangnam style 2  slow
		break;
    

	    default :
		return;
	}
	move_to();
}
