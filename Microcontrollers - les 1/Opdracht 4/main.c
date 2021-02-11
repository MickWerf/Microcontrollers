/*
 * Opdracht 4.c
 *
 * Created: 03/02/2021 11:09:52
 * Author : Mick
 */ 

#define F_CPU 8e6

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRD = 0b11111111; // sets all PORTD pins as output.
	PORTD = 0x01; // turns the PORTD pin 0 led on.
	wait(50);
	
    while (1) 
    {
		PORTD = PORTD << 1; // through bit shifting, moves the active pin/led to the next pin and turns off the current one.
		if (PORTD == 0x00) // checks if the cycle has reached it's end.
		{
			PORTD = 0x01; // restarts the loop by setting the first pin on.
		}
		wait(50);
    }
}

//Waits for the given amount of time in milliseconds
void wait( int ms ){
	for (int i=0; i<ms; i++) {
		_delay_ms( 1 );
	}
}

