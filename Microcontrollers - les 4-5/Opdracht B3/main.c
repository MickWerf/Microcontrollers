#define F_CPU 8e6

#include <avr/io.h>
#include <util/delay.h>
#include "LCD.h"

void wait ( int ms );
void adcInit();
char* itoa(int i);

int main(void)
{
	DDRF = 0x00;
	DDRA = 0xFF;
	DDRB = 0xFF;
	adcInit();
	while (1)
	{
		ADCSRA |= 0x40;
		while( ADCSRA & 0x40);
		PORTB = ADCL;
		PORTA = ADCH;
		clear();
		display_text(itoa(ADCH));
		wait(500);
	}
}

void adcInit(){
	ADMUX = 0xE3;
	ADCSRA = 0x86;
	init();
}

char* itoa(int i){
	char const digit[] = "0123456789";
	char* p;
	if(i<0){
		*p++ = '-';
		i *= -1;
	}
	int shifter = i;
	do{ //Move to where representation ends
		++p;
		shifter = shifter/10;
	}while(shifter);
	*p = '\0';
	do{ //Move back, inserting digits as u go
		*--p = digit[i%10];
		i = i/10;
	}while(i);
	return p;
}