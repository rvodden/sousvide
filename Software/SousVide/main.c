/*
 * SousVide.c
 *
 * Created: 29/09/2017 14:37:01
 * Author : Richard
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#include "board/board.h"

int main(void)
{
	board_init();

    /* Replace with your application code */
    while (1) 
    {
		;
    }
}

ISR(KEYPRESS_INTERRUPT) {
	// kbr_keypressed();
}

