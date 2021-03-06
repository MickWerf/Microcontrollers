
#define F_CPU 8e6

#include <avr/io.h>
#include <util/delay.h>
void wait ( int ms );
void adcInit();
int main(void)
{
	DDRF = 0x00;
	DDRA = 0xFF;
	DDRB = 0xFF;
	adcInit();
    while (1) 
    {
	    PORTB = ADCL;
		PORTA = ADCH;
		wait(100);
    }
}

void adcInit(){
	ADMUX = 0xE1;
	ADCSRA = 0xE6;
}

//Waits for the given amount of time in milliseconds
void wait( int ms )
{
	for (int i=0; i<ms; i++) {
		_delay_ms( 1 );
	}
}