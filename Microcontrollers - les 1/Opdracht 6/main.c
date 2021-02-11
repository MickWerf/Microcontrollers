/*
 * Opdracht 6.c
 *
 * Created: 3-2-2021 11:36:05
 * Author : Thaomas
 */ 

#define F_CPU 8e6
#include <avr/io.h>
#include <util/delay.h>

void wait(int ms);
void toggle();

int dur;
int state;
int visited;

int main(void)
{
    DDRD = 0b11111110; // sets the PORTD pins to input except for PORTD pin 0.
    PORTC = 0x01; // initializes PORTC pin 0.
	dur = 500;
	state = 0; // keeps track of the refresh frequency state.
	visited = 1; // keeps track if a button has already detected an input this wait cycle.
    while (1) 
    {
		PORTD = 0x80; // turns PORTD pin 7 on.
		wait(dur);
		
		PORTD = 0x00; // turns PORTD pin 7 off.
		wait(dur);	
    }
}

//Waits for the given amount of time in milliseconds and checks if the button has been pressed
void wait( int ms ){
	for (int i=0; i<ms; i++) {
		_delay_ms( 1 );
		if (PINC & 0x01 && visited){ // Checks for a first time button press of PORTC pin 0 in the wait cycle.
			toggle(); // toggles the refresh frequency.
			visited = 0;
			return;
		}
	}
	visited = 1;
}

//Toggles between the different durations of Hz.
void toggle(){
	if (state) // checks the current refresh frequency state.
	{
		dur = 500;
		state = 0;
	}else{
		dur = 125;
		state = 1;
	}
}
