


#define STEP_SERVO      10     //step of servo evry TIME_STEP_SRV
#define TIME_STEP_SRV   8     //Time [ms] to move servo 1 STEP_SERVO

// nombre de servos g�r�s
#define SERVO_COUNT 8

// largeurs des pulses des servos, en fonction de la position demand�e
volatile unsigned int pulse_widths[SERVO_COUNT];
volatile unsigned int pulse_widths_old[SERVO_COUNT]; 

// id du servo courant (dont on g�n�re le cr�neau)
volatile unsigned char cur_servo = 0 ;


