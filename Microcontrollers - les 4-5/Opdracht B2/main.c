#define F_CPU 8e6

#include <avr/io.h>
#include <util/delay.h>
void wait ( int ms );
void adcInit();
int main(void)
{
	DDRF = 0x00; // Set PORTD to input.
	DDRA = 0xFF; // Set PORTA to output.
	DDRB = 0xFF; // Set PORTB to output.
	adcInit();
	while (1)
	{
		ADCSRA |= 0x40; // Start Conversion.
		while( ADCSRA & 0x40); // While Converting.
		PORTB = ADCL; // Low value of the ADC.
		PORTA = ADCH; // High value of the ADC.
		wait(500);
	}
}

void adcInit(){
	ADMUX = 0xE3; // ADC Multiplexing Selection Register. Internal voltage, ADLAR (left adjusted) Enabled. ADC3 pin.
	ADCSRA = 0x86; // ADC Status Register A. Prescaler 64.
}

//Waits for the given amount of time in milliseconds
void wait( int ms )
{
	for (int i=0; i<ms; i++) {
		_delay_ms( 1 );
	}
}