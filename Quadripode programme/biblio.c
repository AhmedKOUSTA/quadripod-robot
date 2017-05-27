#include<avr/io.h>
#include "main.h"



//************************
//*****   main
//************************
void move_to(void)
{
     PORTA=etat;
	switch(etat)
		{
		  case '1':  
		  		stand_up();
				USARTWrite_S_Char("  stand up ");
                USART_newline();
		  break;
		  case '2':  
		  		set_down();
				USARTWrite_S_Char("  seting down ");
                USART_newline();
		  break;
		  case '3': 
		  	    pos_3();
				USARTWrite_S_Char("  position 3 ");
                USART_newline();
		  break;
		  case '4':  
		  		stand_up_fast();
				USARTWrite_S_Char("  stand fast ");
                USART_newline();
		  break;
		  case '5':  
		  		set_down_fast();
				USARTWrite_S_Char("  set fast ");
                USART_newline();
		  break;
		  case '6':  
		  		move_left();
				USARTWrite_S_Char(" moving left  ");
                USART_newline();
		  break;
		  case '7':  
		  		move_right();
				USARTWrite_S_Char(" moving right  ");
                USART_newline();
		  break;
		  case '8':  
		  		gang_style();
				USARTWrite_S_Char("  gangnam style ");
                USART_newline();
		  break;
		  case '9':  
		  		move_forward();
				USARTWrite_S_Char("  moving forward ");
                USART_newline();
		  break;
		 
		  case 'A':  
		  		move_backward();
				USARTWrite_S_Char("  moving backward ");
                USART_newline();
		   break;

		  case 'B':  
		  		turn(1800);
				USARTWrite_S_Char("  sturn left ");
                USART_newline();
		   break;

		    case 'C':  
		  		turn(1200);
				USARTWrite_S_Char("  turn right ");
                USART_newline();
		   break;

		    case 'D':  
		  		hello();
				USARTWrite_S_Char("  hello ");
                USART_newline();
		   break;

		    case 'E':  
		  		hiphop();
				USARTWrite_S_Char("  hiphop ");
                USART_newline();
		   break;

		    case 'F':  
		  		gang_style_2();
				USARTWrite_S_Char("  gang nam style 2 ");
                USART_newline();
		   break;

		   case 'G':  
		  		swim();
				USARTWrite_S_Char("  swim ");
                USART_newline();
		   break;

		  default: 

		   USARTWrite_S_Char(" erreur: instruction not found ");
           USART_newline();
		}
}





void pos_ip1(int pos)
{
    move_servo(0,pos);          //pulse_widths[1]=1400;
    
	move_servo(2,pos);
	}



void pos_ip2(int pos)
{
   
	
	move_servo(4,pos);
	
	move_servo(6,pos);
		  
}

void pos_ip3(int pos)
{
    move_servo(1,pos);          //pulse_widths[1]=1400;
    
	move_servo(5,pos);
	}



void pos_ip4(int pos)
{
   
	
	move_servo(3,pos);
	
	move_servo(7,pos);
		  
}



//************************
//*****  repo
//************************
void pos_repo(void)
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


//************************
//*****   stand up
//************************
void stand_up(void)
{
    
   	    pos_ip1(1000); 
		pos_ip2(2000);


	    pos_ip3(1500); 
		pos_ip4(1500);
		  
}


//************************
//*****   set down
//************************
void set_down(void)
{
    
        pos_ip1(2000); 
		pos_ip2(1000);


	    pos_ip3(1500); 
		pos_ip4(1500);
		  
}




void pos_3(void)
{
    
        pos_ip1(2000); 
		pos_ip2(1000);


	    pos_ip3(1200); 
		pos_ip4(1800);
		  
}


void pos_4(void)
{
    
        pos_ip1(2000); 
		pos_ip2(2000);


	    pos_ip3(1000); 
		pos_ip4(2000);
		  
}


//************************
//*****   gang name style
//************************
void gang_style(void)
{
    
        pos_ip1(2000); 
		pos_ip2(1000);


	   move_servo(1,2000);
       move_servo(3,2000);
	   move_servo(5,1000);
       move_servo(7,1000);	
	   
	   
	   move_servo(2,1000);
	   move_servo(4,2000);
	   
	    move_servo(2,2000);
		 move_servo(2,1000);  

		 move_servo(4,1000);
		 move_servo(4,2000);

		  move_servo(0,1500);
	   move_servo(6,1500);

	   move_servo(2,1000);
	   move_servo(4,2000);
	   
	    move_servo(2,2000);
		 move_servo(2,1000);  

		 move_servo(4,1000);
		 move_servo(4,2000);

		 move_servo(2,1000);
	   move_servo(4,2000);
	   
	    move_servo(2,2000);
		 move_servo(2,1000);  

		 move_servo(4,1000);
		 move_servo(4,2000);

		 move_servo(0,2000);
	   move_servo(6,1000);

	    stand_up_fast();

}



//************************
//*****   move forward
//************************
void move_forward(void)
{
    move_f_fast();
		 
		 move_p_B(1800);
	     move_p_D(1200);
	     move_p_C(1200);
         move_p_A(1800);

  move_f_fast();
}



//************************
//*****   move back
//************************
void move_backward(void)
{
    move_b_fast();

         move_p_D(1800);
	     move_p_B(1200);
	     move_p_A(1200);
	     move_p_C(1800);


  move_b_fast();
}


//************************
//*****   move left
//************************
void move_left(void)
{
    move_l_fast();

         move_p_C(1200);
	     move_p_A(1200);
	     move_p_B(1800);
	     move_p_D(1200);
 
  move_l_fast();
}



//************************
//*****   move right
//************************
void move_right(void)
{
    move_r_fast();

		 move_p_B(1200);
	     move_p_D(1800);
	     move_p_A(1800);
	     move_p_C(1200);
	     
	  

   move_r_fast();
}



//***********************************************
//*****   turn left (pos=1800) & right(pos=1200)
//***********************************************
void turn(int pos)
{
    stand_up_fast();
	 move_p_A(pos);
	 move_p_B(pos);
	 move_p_C(pos);
	 move_p_D(pos);

  stand_up_fast();
}




//***********************************************
//*****   A (0,1)   B(2,3) C(4,5)  D(6,7)
//***********************************************
void move_p_A(int pos)
{
	    move_servo(0,1800); 
		move_servo(1,pos); 
		move_servo(0,1500);
		
}


void move_p_B(int pos)
{
	    move_servo(2,1800); 
		move_servo(3,pos); 
		move_servo(2,1500);
		
}

void move_p_C(int pos)
{
	    move_servo(4,1200); 
		move_servo(5,pos); 
		move_servo(4,1500);
		
}

void move_p_D(int pos)
{
	    move_servo(6,1200); 
		move_servo(7,pos); 
		move_servo(6,1500);

		
}


//***********************************************
//*****   SWING HELLO HUMAN
//***********************************************
void hello(void)
{
    stand_up_fast();

	   move_servo(0,2000);

      
	 
	    hello_f();
	   hello_f();
	    hello_f();
	   hello_f();

  stand_up_fast();
}


//***********************************************
//*****   SWIMING
//***********************************************
void swim(void)
{
    set_down();

	   move_servo(0,2000);

       swim_f();
	   swim_f();
	    swim_f();

  stand_up_fast();
}



//************************
//*****   gang name style 2
//************************
void gang_style_2(void)
{
    
        pos_ip1(2000); 
		pos_ip2(1000);


	   move_servo(1,2000);
       move_servo(3,2000);
	   move_servo(5,1000);
       move_servo(7,1000);	
	   
	   
	   move_servo(2,1000);
	   move_servo(4,2000);
	   
	    move_servo(2,2000);
		 move_servo(2,1000);  

		 move_servo(4,1000);
		 move_servo(4,2000);

		  move_servo(0,1500);
	   move_servo(6,1500);

	   gang_f();
        gang_f();
		 gang_f();
		  gang_f();
		   gang_f();

	   
		 move_servo(0,2000);
	   move_servo(6,1000);
	   
       stand_up_fast();
}


void hiphop(void)
{
   
   move_servo(0,1800);
   move_servo(2,1800);
   move_servo(0,1500);
   move_servo(4,1200);
   move_servo(2,1500);
   move_servo(6,1200);
   move_servo(4,1500);
   move_servo(0,1800);
   move_servo(6,1500);

}
