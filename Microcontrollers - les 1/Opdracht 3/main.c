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
	DDRD = 0b11111110;
	PORTC = 0x01;
    /* Replace with your application code */
    while (1) 
    {
		while(PINC & 0x01)
		{
			PORTD = 0x80;
			wait(500);
			PORTD = 0x00;
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