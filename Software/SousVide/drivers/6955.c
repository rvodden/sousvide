/*
 * CFile1.c
 *
 * Created: 29/09/2017 16:30:28
 *  Author: Richard
 */ 

#include "board.h"
#include "usi_twi_master.h"

#include "6955.h"

void 6995_init ( void ) 
{
	/* enable twi driver */
	USI_TWI_Master_Initialise(void);

	/* enable decode mode */

}