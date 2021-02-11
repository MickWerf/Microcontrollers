/*
 * Opdracht 5.c
 *
 * Created: 10/02/2021 13:09:18
 * Author : Mick
 */ 
#define F_CPU 8e6

#include "LCD.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


int main(void)
{
    while (1) 
    {
		init();
		//display_text("test");
		//set_cursor(1);
    }
}

