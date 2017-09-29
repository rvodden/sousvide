/*
 * board_init.c
 *
 * Created: 29/09/2017 16:24:31
 *  Author: Richard
 */ 

 #include "usi_twi_master.h"

 #include "board.h"

 void board_init(void) 
 {
	USI_TWI_Master_Initialise();
 }