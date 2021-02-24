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

void lcd_strobe_lcd_e(void) {
	PORTC |= (1<<LCD_E);	// E high
	_delay_ms(1);			// timout for insurance
	PORTC &= ~(1<<LCD_E);  	// E low
	_delay_ms(1);			// timout for insurance
}

void init() // Initializes the LCD Screen.
{
	DDRC = 0xFF;
	PORTC = 0x00;

	// Return Home
	PORTC = 0x02;
	lcd_strobe_lcd_e();

	//set function: 4 bits interface data, 2 lines, 5x8 dots
	PORTC = 0x28;
	lcd_strobe_lcd_e();
	
	// display: on, cursor on, blinking on
	PORTC = 0x0F
	lcd_strobe_lcd_e()
	
	// entry mode: cursor to right, no shift 
	PORTC = 0x06 ;
	lcd_strobe_lcd_e()
	
	// RAM address: 0, first position, line 1 
	PORTC = 0x80;
	lcd_strobe_lcd_e()
	
}
		 
void display_text(char *str) // Displays a text on the LCD Screen.
{
	
}
	 
void set_cursor(int position) // Sets the cursor on the LCD Screen.
{

} 