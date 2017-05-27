#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>

#include "servo.h"





ISR(TIMER1_COMPA_vect) {
    // On monte donc la sortie du servo en cours de traitement
    // (en gérant la distribution des sorties sur les ports C et D)
    if (cur_servo < 2) {
        PORTC |= (1 << cur_servo) ;
    } else {
        PORTD |= (1 << cur_servo) ;
    }

    // On définit le comparateur B en fonction de la durée de l'impulsion à générer
    OCR1B = pulse_widths[cur_servo] ;
   TCNT1=0;    
}


/*
    Interrupt handler pour l'Ouput Compare B du timer 1

    Le passage à cette valeur correspond à la fin du créneau pour
    le servo en cours.
*/
ISR(TIMER1_COMPB_vect) {
    // on descend la sortie du servo en cours de traitement
    if (cur_servo < 2) {
        PORTC &= ~(1 << cur_servo) ;
    } else {
        PORTD &= ~(1 << cur_servo) ;
    }

    // on passe au servo suivant, en rebouclant en fin de série
    if (++cur_servo == SERVO_COUNT) cur_servo = 0 ;
}


void move_servo(int servo_i,unsigned int pos)
{

	 pulse_widths_old[servo_i]=pulse_widths[servo_i];  // store old position of servo i

	 if (pos == pulse_widths_old[servo_i]);// do nothing;
	 else if ( pos > pulse_widths_old[servo_i])
	 {
	     while ( pos > pulse_widths[servo_i])
		     {
	         pulse_widths[servo_i] = pulse_widths[servo_i] + STEP_SERVO;
	         _delay_ms(TIME_STEP_SRV);
	         }
	 }else
	 {
        while ( pos < pulse_widths[servo_i])
		     {
	         pulse_widths[servo_i] = pulse_widths[servo_i] - STEP_SERVO;
	         _delay_ms(TIME_STEP_SRV);
	         }
	 }

}

void stand_up_fast(void)
{
    
        pulse_widths[0]=1500; 
		pulse_widths[1]=1500; 
		pulse_widths[2]=1500; 
		pulse_widths[3]=1500; 
		pulse_widths[4]=1500; 
		pulse_widths[5]=1500; 
		pulse_widths[6]=1500; 
		pulse_widths[7]=1500; 


}


void set_down_fast(void)
{
    
        pulse_widths[0]=2000; 
		pulse_widths[1]=1500; 
		pulse_widths[2]=2000; 
		pulse_widths[3]=1500; 
		pulse_widths[4]=1000; 
		pulse_widths[5]=1500; 
		pulse_widths[6]=1000; 
		pulse_widths[7]=1500; 


}

   

void move_f_fast(void)
{
    
        pulse_widths[0]=1500; 
		pulse_widths[1]=1200; 
		pulse_widths[2]=1500; 
		pulse_widths[3]=1200; 
		pulse_widths[4]=1500; 
		pulse_widths[5]=1800; 
		pulse_widths[6]=1500; 
		pulse_widths[7]=1800; 


}




void move_b_fast(void)
{
    
        pulse_widths[0]=1500; 
		pulse_widths[1]=1800; 
		pulse_widths[2]=1500; 
		pulse_widths[3]=1800; 
		pulse_widths[4]=1500; 
		pulse_widths[5]=1200; 
		pulse_widths[6]=1500; 
		pulse_widths[7]=1200; 


}



void move_l_fast(void)
{
    
        pulse_widths[0]=1500; 
		pulse_widths[1]=1800; 
		pulse_widths[2]=1500; 
		pulse_widths[3]=1200; 
		pulse_widths[4]=1500; 
		pulse_widths[5]=1200; 
		pulse_widths[6]=1500; 
		pulse_widths[7]=1800; 


}


void move_r_fast(void)
{
    
        pulse_widths[0]=1500; 
		pulse_widths[1]=1200; 
		pulse_widths[2]=1500; 
		pulse_widths[3]=1800; 
		pulse_widths[4]=1200; 
		pulse_widths[5]=1200; 
		pulse_widths[6]=1500; 
		pulse_widths[7]=1200; 


}



void hello_f(void)
 {
 		pulse_widths[4]=1200; 
		pulse_widths[5]=1800;
		_delay_ms(1000);
		pulse_widths[4]=1800; 
		pulse_widths[5]=1200;
		_delay_ms(1000);
		pulse_widths[4]=1200;
		_delay_ms(1000);
		pulse_widths[4]=1800;
 }

 void gang_f(void)
 {
 		pulse_widths[2]=1800; 
		pulse_widths[4]=1200;
		pulse_widths[3]=1200; 
		pulse_widths[5]=1800;
		_delay_ms(1000);

    	pulse_widths[2]=1200; 
		pulse_widths[4]=1800;
		pulse_widths[3]=1800; 
		pulse_widths[5]=1200;
		_delay_ms(1000);
 }

void swim_f(void)
{
        pulse_widths[1]=1200; 
		pulse_widths[3]=1200;
		pulse_widths[5]=1800; 
		pulse_widths[7]=1800;
		_delay_ms(1000);

		pulse_widths[1]=1800; 
		pulse_widths[3]=1800;
		pulse_widths[5]=1200; 
		pulse_widths[7]=1200;
		_delay_ms(1000);
}
