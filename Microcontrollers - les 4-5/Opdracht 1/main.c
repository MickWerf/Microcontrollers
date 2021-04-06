
#define F_CPU 8e6

#include <avr/io.h>
#include <util/delay.h>
void wait ( int ms );
void adcInit();
int main(void)
{
	DDRF = 0x00; // Set PORTF to input.
	DDRA = 0xFF; // Set PORTA to output.
	DDRB = 0xFF; // Set PORTB to output.
	adcInit();
	while (1)
	{
		PORTB = ADCL; // Low value of the ADC.
		PORTA = ADCH; // High value of the ADC.
		wait(100);
	}
}

void adcInit(){
	ADMUX = 0xE1; // ADC Multiplexing Selection Register. Internal voltage, ADLAR (left adjusted) Enabled. ADC1 pin.
	ADCSRA = 0xE6; // ADC Status Register A. Enable, Start conversion, Free running mode, Prescaler 64.
}

//Waits for the given amount of time in milliseconds
void wait( int ms )
{
	for (int i=0; i<ms; i++) {
		_delay_ms( 1 );
	}
}