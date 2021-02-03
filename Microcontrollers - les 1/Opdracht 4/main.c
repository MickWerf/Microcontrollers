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
	DDRD = 0b11111111;
	PORTD = 0x01;
	wait(50);
	
    while (1) 
    {
		PORTD = PORTD << 1;
		if (PORTD == 0x00)
		{
			PORTD = 0x01;
		}
		wait(50);
    }
}

void wait( int ms ){
	for (int i=0; i<ms; i++) {
		_delay_ms( 1 );
	}
}

