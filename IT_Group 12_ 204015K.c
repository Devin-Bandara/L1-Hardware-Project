
/*-------------------------------------------------------------------Full code for the DC Motors and the blades-------------------------*/

#include <avr/io.h>             // This header file includes the appropriate Input/output definitions for the device
#define F_CPU 8000000L
#include <util/delay.h>         // to use delay function we need to include this library
#include <stdlib.h>             // we'll be using itoa() function to convert integer to character array that resides in this library
#include <avr/interrupt.h>

#define DRIVE_MOTOR PC4     // MAIN WHEEL MOTOR OF THE CART connected to the Port C pin 4

#define BLADE_MOTOR_1 PC6     // Blade motor 1 is connected to port C pin 6
#define BLADE_MOTOR_2 PC7     // Blade motor 2 is connected to port C pin 7
#define BLADE_MOTOR_3 PD0     // Blade motor 3 is connected to port D pin 0
#define BLADE_MOTOR_4 PD1     // Blade motor 4 is connected to port D pin 1

int main()
{

	DDRC |= (1<< BLADE_MOTOR_1);  // blade motor pins set as outputs
	DDRC |= (1<< BLADE_MOTOR_2);
	DDRD |= (1<< BLADE_MOTOR_3);
	DDRD |= (1<< BLADE_MOTOR_4);

	DDRC |= (1<< DRIVE_MOTOR);  // MAIN WHEEL MOTOR PIN SET AS OUTPUT

PORTC |= (1<< DRIVE_MOTOR); // CART DRIVES FROWARD
{

	while(1)

	{
		 // if detects any object by any ultrasonic sensor
		//if((distance_1 < 50)||(distance_2 <50))


		PORTC &= ~(1<< DRIVE_MOTOR);   // turn off the main wheel motor
		//DDRC |= (1<< BUZZER);          // buzzer pin set as output
		_delay_ms(60000);              // Wait 1 minute
		PORTC |= (1<< DRIVE_MOTOR);    // Start to go forward again

		// WE USE THIS BEACUSE THERE CAN BE ANIMALS BETWEEN THE RAILWAY TRACKS 

	}

//*************** Function of Upper side proximity sensors **********************************************************************



	{	
		//if any fixed object hits the wheel, turn off the system
		subloop1:
		PORTC &= ~(1<< DRIVE_MOTOR);

		PORTC &= ~(1<< BLADE_MOTOR_1);
		PORTC &= ~(1<< BLADE_MOTOR_2);
		PORTD &= ~(1<< BLADE_MOTOR_3);
		PORTD &= ~(1<< BLADE_MOTOR_4);

		goto subloop1;           // stuck the whole system in subloop1

	}




            // WHEN A PATICULAR LEANER ACTUATOR LIFTS UP 
///////////// ******************* Sensor A ******************


	{  
		// move up the actuator A

		PORTC &= ~(1<< BLADE_MOTOR_1);    // stop blade motor 1

   		_delay_ms(2000);
 
	
		// if the detected object released, then move down the actuator A again

		PORTC |= (1<< BLADE_MOTOR_1);  // start blade motor 1
	}


///////////// ******************* Sensor B ******************


	{  
		// move up the actuator B


		PORTC &= ~(1<< BLADE_MOTOR_2);    // stop blade motor 2
		_delay_ms(2000);
 

		// move down the actuator B

		PORTC |= (1<< BLADE_MOTOR_2);  // start blade motor 2
	}


///////////// ******************* Sensor C ******************


	
	{  
		// move up the actuator C

		PORTD &= ~(1<< BLADE_MOTOR_3);    // stop blade motor 3
		_delay_ms(2000);


		// move down the actuator C


		PORTD |= (1<< BLADE_MOTOR_3);  // start blade motor 3
	}



///////////// ******************* Sensor D ******************


	{  
		// move up the actuator D


		PORTD &= ~(1<< BLADE_MOTOR_4);    // stop blade motor 4
		_delay_ms(2000);

	
	 
		// move down the actuator D

		PORTD |= (1<< BLADE_MOTOR_4);  // start blade motor 4
	}



	}
	
}
