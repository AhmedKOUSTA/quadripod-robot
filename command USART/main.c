#include<avr/io.h>
#include<avr/interrupt.h>

#include<util/delay.h>



#include "main.h"


void config_timer(void)
    {
	 // configuration pour le servo
	 TCCR1B = (1 << WGM12)| (1 << CS10);
     OCR1A = PULSE_MAX_WIDTH + 10 ;
     OCR1B = PULSE_MED_WIDTH ;
     TCNT1 = OCR1B + 10 ;
     TIMSK = (1 << OCIE1A)| (1 << OCIE1B);

  
}



void config_interface(void)
    {
      DDRD|=0xfc;  //declaration de port c comme sortie des servo
      DDRC=0XFF;
	}


	
void position_sleep(void)
{
    
    move_servo(0,SLEEP_SERVO_0);          //pulse_widths[2]=2400;
    move_servo(1,SLEEP_SERVO_0);          //pulse_widths[1]=1400;
    move_servo(2,SLEEP_SERVO_0);          //pulse_widths[0]=1400;
	move_servo(3,SLEEP_SERVO_0);
	move_servo(4,SLEEP_SERVO_0);
	move_servo(5,SLEEP_SERVO_0);
	move_servo(6,SLEEP_SERVO_0);
	move_servo(7,SLEEP_SERVO_0);
		  
}

void pos_0(void)
{
    
    move_servo(0,POS0);          //pulse_widths[2]=2400;
    move_servo(1,POS0);          //pulse_widths[1]=1400;
    move_servo(2,POS0);          //pulse_widths[0]=1400;
	move_servo(3,POS0);
	move_servo(4,POS0);
	move_servo(5,POS0);
	move_servo(6,POS0);
	move_servo(7,POS0);
		  
}


void pos_1(void)
{
    
    move_servo(0,POS1);          //pulse_widths[2]=2400;
    move_servo(1,POS1);          //pulse_widths[1]=1400;
    move_servo(2,POS1);          //pulse_widths[0]=1400;
	move_servo(3,POS1);
	move_servo(4,POS1);
	move_servo(5,POS1);
	move_servo(6,POS1);
	move_servo(7,POS1);
		  
}

void pos_2(void)
{
    
    move_servo(0,POS1);          //pulse_widths[2]=2400;
    move_servo(1,POS0);          //pulse_widths[1]=1400;
    move_servo(2,POS2);          //pulse_widths[0]=1400;
	move_servo(3,POS2);
	move_servo(4,POS0);
	move_servo(5,POS2);
	move_servo(6,POS0);
	move_servo(7,POS1);
		  
}


int main(void)
    {
   
	int pos,servo_n;



     DDRC|=(1<<PC2);
	
     USARTInit(25);  //boud rate to 2400
     position_sleep();
     config_interface();            //configuration des entrée et des sortie de ATMEGA16
     config_timer();
	 sei();


	 USARTWrite_S_Char("   hello world   ");
	 USART_newline();
     
	 USARTWrite_S_Char("  This programme is for control of the quadreped  ");
      USART_newline(); 
     while(1)
	    {
	
	    
		    _delay_ms(100);
	 	 
	      USARTWrite_S_Char("  donner posirion entre 600 - 2400  ");
	      USART_newline();
         pos=USARTReadChar()-0x30;
	    
		if(pos==0)
		pos_0();
		else if(pos==1)
         pos_1();
		else if(pos==2)
         pos_2();
		 else if(pos==3)
         position_sleep();
        
	    
          _delay_ms(100);
		  USART_newline();

            }
        
    }
