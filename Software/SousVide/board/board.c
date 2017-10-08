/*
 * board_init.c
 *
 * Created: 29/09/2017 16:24:31
 *  Author: Richard
 */ 

#include "../drivers/usi_twi_master.h"

#include "board.h"
#include "../drivers/MAX69XX.h"

void board_init(void) 
{
	MAX69XX_init();
}

ISR(INT0_vect)
{

}