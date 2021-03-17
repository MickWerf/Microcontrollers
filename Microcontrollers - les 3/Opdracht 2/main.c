#define F_CPU 8e6
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "LCD.h"

#define BIT(x)			(1 << (x))


#define LCD_E 3
#define LCD_RS 2

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


int main(void) {
	
	DDRD &= ~BIT(7);		// PD7 op input: DDRD=xxxx xxx0
	DDRB = 0xFF;			// PORTB is output
	TCCR2 = 0b00000111;		// counting via PD7, rising edge

	init();
	int buffer;
	int numBuf;
	int num = 10;
	clear();
	set_cursor(0);
	while (1) {
		if (buffer != TCNT2)
		{
			buffer = TCNT2;
			clear();
			set_cursor(0);
			num = TCNT2;
			display_text(itoa(num));
			PORTB = TCNT2;
		}
		wait(10);
	}
}
