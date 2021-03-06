/*
 * Opdracht 2.c
 *
 * Created: 03/02/2021 09:22:15
 * Author : Mick
 */ 

#define F_CPU 8e6

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRD = 0b11111111;			// All pins PORTD are set to output 
    
    while (1) 
    {
		PORTD = 0x80;	// turns led 7 on, all others off.
		wait (500);		// waits before moving on to avoid epilepsy vulnerable situations.
		PORTD = 0x40;	// turns led 6 on, all others off.
		wait (500);		// waits before moving on to avoid epilepsy vulnerable situations.
    }
}

//Waits for the given amount of time in milliseconds
void wait( int ms )
{
	for (int i=0; i<ms; i++) {
		_delay_ms( 1 );
	}
}

