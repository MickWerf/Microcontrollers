/*
 * Opdracht 3.c
 *
 * Created: 10-2-2021 10:43:28
 * Author : Thaomas
 */ 

#define F_CPU 8e6
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void display(int digit);
int count;
int bool;
int main(void)
{
	DDRD = 0xFF; // sets all PORTD Leds to output.
	DDRE = 0x00; // sets all PORTE Leds as input.
	EICRB |= 0x0F; // Configures the INT4 and INT5 buttons as rising edge. (EICRB applies to INT 4 through 7).
	EIMSK |= 0x30; // Enables the INT4 and INT5 interrupts.
	sei(); // Turns all interrupts on.
	
	count = 0;
	bool = 1;
	display(count);
	
	while (1)
	{
		wait(100);
		bool = 1; // prevents double triggers in a single interrupt cycle.
	}
}

// Interrupt using the PE4 button.
ISR(INT4_vect ) {
	if (bool) // prevents double triggers in a single interrupt cycle.
	{
		bool = 0;
		if (PINE & 0x20) // checks if the other button is pressed as well.
		{
			count = 0;
		}	
		else
		{
			count++;	
		}
		display(count);
	}
}

// Interrupt using the PE5 button.
ISR (INT5_vect) {
	if (bool) // prevents double triggers in a single interrupt cycle.
	{
		bool = 0;
		if (PINE & 0x10) // checks if the other button is pressed as well.
		{
			count = 0;
		} 
		else 
		{
			count--;	
		}
		display(count);
	}
}


void display(int digit){
	switch(digit){
		case 0:
			PORTD = 0x3F; // Hexadecimal value for "0".
			break;
		case 1:
			PORTD = 0x06; // Hexadecimal value for "1".
			break;
		case 2:
			PORTD = 0x5B; // Hexadecimal value for "2".
			break;
		case 3:
			PORTD = 0x4F; // Hexadecimal value for "3".
			break;
		case 4:
			PORTD = 0x66; // Hexadecimal value for "4".
			break;
		case 5:
			PORTD = 0x6D; // Hexadecimal value for "5".
			break;
		case 6:
			PORTD = 0x7D; // Hexadecimal value for "6".
			break;
		case 7:
			PORTD = 0x07; // Hexadecimal value for "7".
			break;
		case 8:
			PORTD = 0x7f; // Hexadecimal value for "8".
			break;
		case 9:
			PORTD = 0x6F; // Hexadecimal value for "9".
			break;
		case 10:
			PORTD = 0x77; // Hexadecimal value for "A".
			break;
		case 11:
			PORTD = 0x7C; // Hexadecimal value for "B".
			break;
		case 12:
			PORTD = 0x39; // Hexadecimal value for "C".
			break;
		case 13:
			PORTD = 0x5E; // Hexadecimal value for "D".
			break;
		case 14:
			PORTD = 0x79; // Hexadecimal value for "E".
			break;
		case 15:
			PORTD = 0x71; // Hexadecimal value for "F".
			break;
		default:
			PORTD = 0x79; // Hexadecimal value for "E".
			break;
	}
}

void wait( int ms ) {
	for (int i=0; i<ms; i++) {
		_delay_ms( 1 );
	}
}
