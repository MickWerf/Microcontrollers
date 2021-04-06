/*
 * Eindproject.c
 *
 * Created: 24-3-2021 10:06:46
 * Author : Thaom
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

int turnTo = 0;

int main(void)
{
	EICRB |= 0x0F; // Configures the INT4 and INT5 buttons as rising edge. (EICRB applies to INT 4 through 7).
	EIMSK |= 0x30; // Enables the INT4 and INT5 interrupts.
	sei(); // Turns all interrupts on.
	
    while (1) 
    {
		if (turnTo == 1)
		{
			//turn left
		} else if (turnTo == 2)
		{
			//turn right
		}
		wait(1);
    }
}

// Interrupt using the PE4 button.
ISR(INT4_vect ) {
	turnTo = 1; //turn to left
}

// Interrupt using the PE5 button.
ISR (INT5_vect) {
	turnTo = 2; //turn to right
}

