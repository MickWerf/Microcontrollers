/*
 * LCD.h
 *
 * Created: 10/02/2021 13:10:03
 *  Author: Mick
 */ 


#ifndef LCD_H_
#define LCD_H_

void init(); // Initializes the LCD Screen.
void display_text(char *str); // Displays a text on the LCD Screen.
void set_cursor(int position); // Sets the cursor on the LCD Screen.

#endif /* LCD_H_ */