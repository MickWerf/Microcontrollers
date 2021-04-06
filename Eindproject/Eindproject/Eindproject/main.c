/*
 * Eindproject.c
 *
 * Created: 24-3-2021 10:06:46
 * Author : Thaom
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include "Snake.h"
bool lock;
int main(void){
	lock = false;
	initGame();
	EICRB |= 0x0F; // Configures the INT4 and INT5 buttons as rising edge. (EICRB applies to INT 4 through 7).
	EIMSK |= 0x30; // Enables the INT4 and INT5 interrupts.
	sei(); // Turns all interrupts on.
	
    while (1) 
    {
		lock = true;
		snake_Update();
		wait(1000);
    }
}


// Interrupt using the PE4 button.
ISR(INT4_vect){
	if (lock)
	{
		moveRight();
		lock = false;
	}
}
// Interrupt using the PE5 button.
ISR(INT5_vect){
	if (lock)
	{
		moveLeft();
		lock = false;
	}
}