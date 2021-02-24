#define F_CPU 8e6
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define BIT(x)			(1 << (x))


#define LCD_E 3
#define LCD_RS 2

void lcd_clear_screen(){
	lcd_write_charCMD(0x01);
}
void init(){
	
	DDRC = 0xFF;
	PORTC = 0x00;
	
	PORTC = 0x20;	// function set
	lcd_ledge_e();
	
	PORTC = 0x20;   // function set
	lcd_ledge_e();
	
	PORTC = 0x80;	//Sets cursor position.
	lcd_ledge_e();
	
	PORTC = 0x00;   //Display on/off control
	lcd_ledge_e();
	
	PORTC = 0xF0;   //Turn on cursor
	lcd_ledge_e();
	
	PORTC = 0x00;   // Entry mode set
	lcd_ledge_e();
	
	PORTC = 0x60;
	lcd_ledge_e();
}

//START init functions

//used to reset the lcd - 4bit interface, 2 lines, 5*7 pixels (doens't work)
void lcd_reset(){
	for(int i = 0;i < 2; i++){
		lcd_write_charCMD(0x38);
	}
}

//END init functions

void init_hello_world(){
	init();
	lcd_clear_screen();
	set_cursor(0);
	display_text("hello");
	set_cursor(6);
	display_text("world");
}

void lcd_ledge_e(void) {
	PORTC |= (1<<LCD_E);	// E high
	wait(1);			// nodig
	PORTC &= ~(1<<LCD_E);  	// E low
	wait(1);			// nodig?
}

//START methods used to display text.

void display(char byte, int rs){
	// First nibble.
	PORTC = byte;
	PORTC |= (rs<<2);
	lcd_ledge_e();
	
	// Second nibble
	PORTC = (byte << 4);
	PORTC |= (rs<<2);
	lcd_ledge_e();
}

void lcd_write_charCMD(char byte){
	display(byte,0);
}

void lcd_write_char(char byte){
	display(byte,1);
}

//END methods for text.

void display_text(char *str){
	for (; *str; str++)
	{
		lcd_write_char(*str);
	}
}

void set_cursor(int position){
	lcd_return_home();
	for (int i = 0; i < position; i++)
	{
		lcd_set_cursor_position_1_right();
	}
}
// wait(): busy waiting for 'ms' millisecond
// Used library: util/delay.h
void wait( int ms ) {
	for (int tms=0; tms<ms; tms++) {
		_delay_ms( 1 );			// library function (max 30 ms at 8MHz)
	}
}

void lcd_set_cursor_position_1_right(){
	lcd_write_charCMD(0x14);
}

//(doens't work)
void lcd_return_home(){
	lcd_write_charCMD(0x02); //used to return home
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


int main(void) {
	
	DDRD &= ~BIT(7);		// PD7 op input: DDRD=xxxx xxx0
	DDRB = 0xFF;			// PORTB is output
	TCCR2 = 0b00000111;		// counting via PD7, rising edge

init();
int buffer;
int numBuf;
int num = 10;
lcd_clear_screen();
set_cursor(0);
	while (1) {
		if (buffer != TCNT2)
		{
			buffer = TCNT2;
			lcd_clear_screen();
			set_cursor(0);
			num = TCNT2;
			display_text(itoa(num));
			PORTB = TCNT2;	
		}
		wait(10);
	}
}
