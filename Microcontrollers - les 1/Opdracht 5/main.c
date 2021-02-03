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
	int animation[32] = {
		0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80,
		0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01,
		0x81, 0x42, 0x24, 0x18, 0x18, 0x24, 0x42, 0x81,
		0x81, 0x42, 0x24, 0x18, 0x18, 0x24, 0x42, 0x81
		};
	int dynamicWaits[32] = {
		200, 200, 200, 200, 200, 200, 200, 200,
		200, 200, 200, 200, 200, 200, 200, 200,
		250, 250, 250, 250, 250, 250, 250, 250,
		250, 250, 250, 250, 250, 250, 250, 250
		};
	
    /* Replace with your application code */
    while (1) 
    {
		if (position > length)
		{
			position = 0;
		}
		PORTD = animation[position];
		wait(dynamicWaits[position]);
		position++;
    }
}

void wait( int ms ){
	for (int i=0; i<ms; i++) {
		_delay_ms( 1 );
	}
}

