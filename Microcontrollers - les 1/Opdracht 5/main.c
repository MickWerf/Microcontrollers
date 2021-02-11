/*
 * Opdracht 5.c
 *
 * Created: 03/02/2021 11:29:08
 * Author : Mick
 */ 

#define F_CPU 8e6

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRD = 0b11111111;
	int length = 32;
	int position = 0;
	int animation[32] = { // saves predefined hexadecimal values for the animation.
		0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80,
		0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01,
		0x81, 0x42, 0x24, 0x18, 0x18, 0x24, 0x42, 0x81,
		0x81, 0x42, 0x24, 0x18, 0x18, 0x24, 0x42, 0x81
		};
	int dynamicWaits[32] = { // saves predefined hexadecimal values for the timeout durations.
		200, 200, 200, 200, 200, 200, 200, 200,
		200, 200, 200, 200, 200, 200, 200, 200,
		250, 250, 250, 250, 250, 250, 250, 250,
		250, 250, 250, 250, 250, 250, 250, 250
		};
	
    while (1) 
    {
		if (position > length) // resets the loop if the end is reached.
		{
			position = 0;
		}
		PORTD = animation[position]; // loads the next animation step.
		wait(dynamicWaits[position]); // loads the next wait duration.
		position++;
    }
}

//Waits for the given amount of time in milliseconds
void wait( int ms ){
	for (int i=0; i<ms; i++) {
		_delay_ms( 1 );
	}
}

