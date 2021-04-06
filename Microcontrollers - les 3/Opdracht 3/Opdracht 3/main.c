#define F_CPU 8e6
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define LCD_E 3
#define LCD_RS 2
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
	OCR2 = 117; // Output Compare register.  Vergelijkingswaarde voor de timer. Deze waarde triggered na 15ms.
	TIMSK = 0x80; // Timer/Counter Interrupt Maks. Enables vergelijking met de OCR.
	sei(); // Enables all interrupts.
	TCCR2 = 0x2d; // Timer/Counter control register. Override mode (bits 4,5), CTC mode(Bits 6,3), Prescaler of 1024(bits 0,1,2).
}

ISR(TIMER2_COMP_vect){
	if(bool){
		OCR2 = 195; // Output Compare Register wordt veranderd voor een 25ms trigger.
		PORTD = 0x80;
		bool = 0;
	}else{
		OCR2 = 117; // Output Compare Register wordt veranderd voor een 25ms trigger.
		PORTD = 0x00;
		bool = 1;
	}
}

