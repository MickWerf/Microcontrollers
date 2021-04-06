/*
 * LCD.c
 *
 * Created: 10/02/2021 13:09:42
 *  Author: Mick
 */ 

#define F_CPU 8e6

#include "LCD.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define LCD_E 	3
#define LCD_RS	2

void wait( int ms );
void lcd_strobe_lcd_e();
void write_char(char character);
void write_command(char command);

void lcd_strobe_lcd_e(void) {
	PORTC |= (1<<LCD_E);	// E high
	_delay_ms(1);			// timout for insurance
	PORTC &= ~(1<<LCD_E);  	// E low
	_delay_ms(1);			// timout for insurance
}

void lcd_init() // Initializes the LCD Screen.
{
	DDRC = 0xFF;
	PORTC = 0x00;

	write_command(0x00);
	// clear display
	write_command(0x01);
	// Return Home
	write_command(0x02);
	//set function: 4 bits interface data, 2 lines, 5x8 dots
	write_command(0x28);
	// display: on, cursor on, blinking off
	write_command(0x0E);
	// entry mode: cursor to right, no shift 
	write_command(0x06);
	// RAM address: 0, first position, line 1 
	write_command(0x80);
	write_command(0x00);
	
}
		 
void display_text(char *str) // Displays a text on the LCD Screen.
{
	while(*str) { // loops through the string.
		write_char(*str++);
	}
	write_command(0x02);
}
	 
void set_cursor(int position) // Sets the cursor on the LCD Screen.
{
	
}

void write_char(char character) {
	PORTC = character; // hoge nibble (first chunk)
	PORTC |= 0x0C; // start writing character.
	lcd_strobe_lcd_e();
	
	PORTC = character << 4; // lage nibble (last chunk)
	PORTC |= 0x0C; // start writing character.
	lcd_strobe_lcd_e();
}

void write_command(char command) {
	PORTC = command; // hoge nibble (first chunk)
	PORTC |= 0x08; // start writing command.
	lcd_strobe_lcd_e();
	
	PORTC = command << 4; // lage nibble (last chunk)
	PORTC |= 0x08; // start writing command.
	lcd_strobe_lcd_e();
}

void wait( int ms ) {
	for (int i=0; i<ms; i++) {
		_delay_ms( 1 );
	}
}