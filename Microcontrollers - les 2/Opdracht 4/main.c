/*
 * Opdracht 4.c
 *
 * Created: 10/02/2021 12:24:50
 * Author : Mick
 */ 

#define F_CPU 8e6
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void wait( int ms );

int main(void)
{
	DDRD = 0xFF; // sets all PORTD Leds to output.
	int animationSize = 16; // static animation size.
	int delay = 500; // default delay.
	char pattern[] = { // animation array containing all used number's hexadecimal values in ascending order.
		0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71
		}; 
		
    while (1) 
    {
		for (int i = 0; i < animationSize; i++)
		{
			PORTD = pattern[i]; // shows the next decimal in the animation loop.
			wait(delay);
		}
    }
}

void wait( int ms ) {
	for (int i=0; i<ms; i++) {
		_delay_ms( 1 );
	}
}

