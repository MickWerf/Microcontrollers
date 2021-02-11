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
void clearLeds();
void wait();

int main(void)
{
    while (1) 
    {
		for (int i = 0; i < 6; i++)
		{
			setCharliePlexingLed(i);
			wait(1000);
		}
		clearLeds(); // turns all leds off.
		wait(500); // waits 500 miliseconds between loops to save people eyesight.
    }
}

// CharliePlexing switch case which checks the selected led and configures the pins accordingly.
void setCharliePlexingLed(int lednr) {
	clearLeds(); // turns all leds off.
	switch (lednr) // checks which led needs to be turned on.
	{
	case 0:
		DDRD = 0b00000011; // sets PORTD pins 0 and 1 to output.
		PORTD = 0x01; // to turn on led 0, sets PORTD pin 0 to on. This causes a flow between pins 0(high) and 1(low).
		break;
	case 1 :
		DDRD = 0b00000011; // sets PORTD pins 0 and 1 to output.
		PORTD = 0x02; // to turn on led 1, sets PORTD pin 1 to on. This causes a flow between pins 0(low) and 1(high).
		break;
	case 2 :
		DDRD = 0b00000110; // sets PORTD pins 1 and 2 to output.
		PORTD = 0x02; // to turn on led 2, sets PORTD pin 1 to on. This causes a flow between pins 1(high) and 2(low).
		break;
	case 3 :
		DDRD = 0b00000110; // sets PORTD pins 1 and 2 to output.
		PORTD = 0x04; // to turn on led 3, sets PORTD pin 2 to on. This causes a flow between pins 1(low) and 2(high).
		break;
	case 4 :
		DDRD = 0b00000101; // sets PORTD pins 0 and 2 to output.
		PORTD = 0x04; // to turn on led 4, sets PORTD pin 2 to on. This causes a flow between pins 0(low) and 2(high).
		break;
	case 5 :
		DDRD = 0b00000101; // sets PORTD pins 0 and 2 to output.
		PORTD = 0x01; // to turn on led 5, sets PORTD pin 20to on. This causes a flow between pins 0(high) and 2(low).
		break;
	}
}

// Turns all the leds off.
void clearLeds() {
	DDRD = 0b00000111; // sets all PORTD pins to input except for pins 0 through 2.
	PORTD = 0x00; // turns all PORTD pins off, pins 0 through 2 need to be set to input to be allowed to be turned off.
	DDRD = 0b00000000; // sets all PORTD pins to output.
}

//Waits for the given amount of time in milliseconds
void wait( int ms ){
	for (int i=0; i<ms; i++) {
		_delay_ms( 1 );
	}
}
