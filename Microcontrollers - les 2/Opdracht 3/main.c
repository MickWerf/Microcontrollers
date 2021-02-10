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

int main(void)
{
	DDRD = 0xFF; // sets all PORTD Leds to output.
	DDRE = 0x00; // sets all PORTE Leds as input.
	EICRB |= 0x0F; // Configures the INT4 and INT5 buttons as rising edge. (EICRB applies to INT 4 through 7).
	EIMSK |= 0x30; // Enables the INT4 and INT5 interrupts.
	sei(); // Turns all interrupts on.
	
	count = 0;
	display(count);
	
	while (1)
	{
	}
}

// Interrupt using the PE4 button.
ISR(INT4_vect ) {
	if (PINE & 0x20)
	{
		count = 0;
	}else{
		count++;	
	}
	display(count);
}

// Interrupt using the PE5 button.
ISR (INT5_vect) {
	if (PINE & 0x10)
	{
		count = 0;
	}else{
	count--;	
	}
	display(count);
}


void display(int digit){
	switch(digit){
		case 0:
			PORTD = 0x3F;
			break;
		case 1:
			PORTD = 0x06;
			break;
		case 2:
			PORTD = 0x5B;
			break;
		case 3:
			PORTD = 0x4F;
			break;
		case 4:
			PORTD = 0x66;
			break;
		case 5:
			PORTD = 0x6D;
			break;
		case 6:
			PORTD = 0x7D;
			break;
		case 7:
			PORTD = 0x07;
			break;
		case 8:
			PORTD = 0x7f;
			break;
		case 9:
			PORTD = 0x6F;
			break;
			case 10:
			PORTD = 0x77;
			break;
			case 11:
			PORTD = 0x7C;
			break;
			case 12:
			PORTD = 0x39;
			break;
			case 13:
			PORTD = 0x5E;
			break;
			case 14:
			PORTD = 0x79;
			break;
			case 15:
			PORTD = 0x71;
			break;
		default:
			PORTD = 0x79;
			break;
	}
}

void wait( int ms ) {
	for (int i=0; i<ms; i++) {
		_delay_ms( 1 );
	}
}
