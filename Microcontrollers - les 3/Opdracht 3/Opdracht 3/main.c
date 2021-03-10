#define F_CPU 8e6
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int bool;

void wait(int);
void timerInit();

int main(void)
{
    DDRD = 0x80;
	timerInit();
	while(1){
		wait(10);
	}
}

void wait( int ms ) {
	for (int i=0; i<ms; i++) {
		_delay_ms( 1 );
	}
}

void timerInit( void ) {
	bool = 1;
	OCR2 = 117;
	TIMSK = 0x80;
	sei();
	TCCR2 = 0x2d;
}

ISR(TIMER2_COMP_vect){
	if(bool){
		OCR2 = 195;
		PORTD = 0x80;
		bool = 0;
	}else{
		OCR2 = 117;
		PORTD = 0x00;
		bool = 1;
	}
}

