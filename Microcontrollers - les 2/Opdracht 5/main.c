/*
 * Opdracht 5.c
 *
 * Created: 10/02/2021 13:09:18
 * Author : Mick
 */ 
#define F_CPU 8e6

#include "LCD.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void delay( int ms );

int main(void)
{
	init();
	display_text("Liquid Crystal");
	//set_cursor(1);
	
    while (1)
    {
		delay(200);	
    }
}

void delay( int ms ) {
	for (int i=0; i<ms; i++) {
		_delay_ms( 1 );
	}
}

