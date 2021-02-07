/*
 * Opdracht 7.c
 *
 * Created: 07/02/2021 15:37:49
 * Author : Mick
 */ 

#define F_CPU 8e6
#include <avr/io.h>
#include <util/delay.h>

void setCharliePlexingLed();
void clearleds();
void wait();

int main(void)
{
    while (1) 
    {
		for (int i = 0; i < 6; i++)
		{
			setCharliePlexingLed(i);
			wait(250);
		}
		clearLeds(); // turns all leds off.
		wait(500); // waits 500 miliseconds between loops to save people eyesight.
    }
}

// CharliePlexing switch case which checks the selected led and configures the pins accordingly.
void setCharliePlexingLed(int lednr) {
	clearLeds();
	switch (lednr)
	{
	case 1 :
		DDRD = 0b00000011;
		PORTD = 0x01;
		break;
	case 2 :
		DDRD = 0b00000011;
		PORTD = 0x02;
		break;
	case 3 :
		DDRD = 0b00000110;
		PORTD = 0x02;
		break;
	case 4 :
		DDRD = 0b00000110;
		PORTD = 0x04;
		break;
	case 5 :
		DDRD = 0b00000101;
		PORTD = 0x04;
		break;
	case 6 :
		DDRD = 0b00000101;
		PORTD = 0x01;
		break;
	}
}

// Turns all the leds off.
void clearLeds() {
	DDRD = 0b00000111;
	PORTD = 0x00;
	DDRD = 0b00000000;
}

//Waits for the given amount of time in milliseconds
void wait( int ms ){
	for (int i=0; i<ms; i++) {
		_delay_ms( 1 );
	}
}
