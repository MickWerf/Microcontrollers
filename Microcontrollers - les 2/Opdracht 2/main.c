/*
 * Opdracht 2.c
 *
 * Created: 10/02/2021 10:16:37
 * Author : Mick
 */ 

#define F_CPU 8e6
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int bool;

void wait( int ms );

int main(void)
{
    DDRD = 0xFF; // sets all PORTD Leds to output.
	DDRE = 0x00; // sets all PORTE Leds as input.
	PORTD = 0x01; // sets the first PORTD led (PD0) on.
	
	EICRB |= 0x0F; // Configures the INT4 and INT5 buttons as rising edge. (EICRB applies to INT 4 through 7).
	EIMSK |= 0x30; // Enables the INT4 and INT5 interrupts.
	sei(); // Turns all interrupts on.
	bool = 1;
    while (1) 
    {
		wait(100);
		bool = 1; // prevents double triggers during a single interrupt cycle.
    }
}

// Interrupt using the PE4 button.
ISR(INT4_vect ) {
	if (bool)
	{
		bool = 0;
		if (PORTD == 0x80) // checks if led is at an edge.
		{
			PORTD = 0x01; // if the end of the cycle is reached, wrap by resetting the PORTD active pin to the opposite side.
		} else {
			PORTD = PORTD << 1; // otherwise, move the active PORTD pin backwards through bit shifting.
		}
	}
}

// Interrupt using the PE5 button.
ISR (INT5_vect) {
	if (bool)
	{
		bool = 0;
		if (PORTD == 0x01) //Checks if led is at an edge.
		{
			PORTD = 0x80; // if the end of the cycle is reached, wrap by resetting the PORTD active pin to the opposite side.
		} else {
			PORTD = PORTD >> 1; // otherwise, move the active PORTD pin forwards through bit shifting.
		}
	}
}

void wait( int ms ) {
	for (int i=0; i<ms; i++) {
		_delay_ms( 1 );
	}
}
