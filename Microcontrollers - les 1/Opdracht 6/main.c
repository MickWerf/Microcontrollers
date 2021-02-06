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
int bool;
int visited;

int main(void)
{
    DDRD = 0b11111110;
    PORTC = 0x01;
	dur = 500;
	bool = 0;
	visited = 1;
    while (1) 
    {
		PORTD = 0x80;
		wait(dur);
		
		PORTD = 0x00;
		wait(dur);	
    }
}

void wait( int ms ){
	for (int i=0; i<ms; i++) {
		_delay_ms( 1 );
		
		if (PINC & 0x01 && visited){
			toggle();
			visited = 0;
			return;
		}
	}
	visited = 1;
}

void toggle(){
	if (bool)
	{
		dur = 500;
		bool = 0;
	}else{
		dur = 125;
		bool = 1;
	}
}
