#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>

#include "servo.h"





ISR(TIMER1_COMPA_vect) {
    // On monte donc la sortie du servo en cours de traitement
    // (en gérant la distribution des sorties sur les ports C et D)
    if (cur_servo < 4) {
        PORTC |= (1 << cur_servo) ;
    } else {
        PORTD |= (1 << cur_servo) ;
    }

    // On définit le comparateur B en fonction de la durée de l'impulsion à générer
    OCR1B = pulse_widths[cur_servo] ;
}


/*
    Interrupt handler pour l'Ouput Compare B du timer 1

    Le passage à cette valeur correspond à la fin du créneau pour
    le servo en cours.
*/
ISR(TIMER1_COMPB_vect) {
    // on descend la sortie du servo en cours de traitement
    if (cur_servo < 4) {
        PORTC &= ~(1 << cur_servo) ;
    } else {
        PORTD &= ~(1 << cur_servo) ;
    }

    // on passe au servo suivant, en rebouclant en fin de série
    if (++cur_servo == SERVO_COUNT) cur_servo = 0 ;
}


void move_servo(char servo_i,unsigned int pos)
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

