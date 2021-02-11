/*
 * Opdracht 3.c
 *
 * Created: 03/02/2021 10:46:51
 * Author : Mick
 */ 

#define F_CPU 8e6
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD = 0b11111110; // sets all PORTD pins except for PORTD pin 0 as output.
	PORTC = 0x01;
	
    while (1) 
    {
		while(PINC & 0x01) // checks if PORTD pin 1 is detecting a button press.
		{
			PORTD = 0x80; // turns PORTD pin 7 on.
			wait(500);
			PORTD = 0x00; // turns PORTD pin 7 off.
			wait(500);
			
		}
		wait(1);
    }
}

//Waits for the given amount of time in milliseconds
void wait( int ms ){
	for (int i=0; i<ms; i++) {
		_delay_ms( 1 );
	}
}