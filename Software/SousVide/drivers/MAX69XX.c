/*
 * CFile1.c
 *
 * Created: 29/09/2017 16:30:28
 *  Author: Richard
 */ 


#include "../board/board.h"
#include "MAX69XX.h"

inline void MAX69XX_init ( void ) 
{
	/* enable twi driver */
	USI_TWI_Master_Initialise();
	MAX69XX_startup();
	MAX69XX_set_scan_limit(MAX69XX_SCAN_LIMIT_4);
}

inline void MAX69XX_startup( void )
{
	char config;

	/* get exiting value of configuration register */
	config = MAX69XX_rx(MAX69XX_CONFIGURATION);
	/* set the startup bit */
	config |= MAX69XX_CONFIG_RESET;

	MAX69XX_tx(MAX69XX_CONFIGURATION, config);
}

inline void MAX69XX_shutdown( void )
{
	char config;

	/* get exiting value of configuration register */
	config = MAX69XX_rx(MAX69XX_CONFIGURATION);
	/* set the startup bit */
	config &= ~MAX69XX_CONFIG_STARTUP;

	MAX69XX_tx(MAX69XX_CONFIGURATION, config);
}

inline void MAX69XX_set_all_digits_to_decode_mode() 
{
	MAX69XX_tx(MAX69XX_DECODE_MODE,0x00FF);
}

inline void MAX69XX_set_all_digits_to_direct_mode()
{
	MAX69XX_tx(MAX69XX_DECODE_MODE,0x0000);
}

inline void MAX69XX_set_scan_limit(unsigned char limit)
{
	MAX69XX_tx(MAX69XX_SCAN_LIMIT, limit);
}

void MAX69XX_tx( char address, char value  )
{
	unsigned char message_buffer[MAX69XX_MESSAGE_SIZE]; /* message sent to the MAX69XX */

	// set the slave address with the R~W bit set to low (write mode)
	message_buffer[MAX69XX_SLAVE_ADDRESS_BYTE] = MAX69XX_ADDRESS;
	message_buffer[MAX69XX_REGISTER_ADDRESS_BYTE] = address;
	message_buffer[MAX69XX_VALUE_BYTE] = value;

	USI_TWI_Start_Transceiver_With_Data( message_buffer, MAX69XX_MESSAGE_SIZE );
}

unsigned char MAX69XX_rx( char address )
{
	unsigned char message_buffer[MAX69XX_MESSAGE_SIZE]; /* message sent to the MAX69XX */

	// set the slave address with the R~W bit set to high (read mode)
	message_buffer[MAX69XX_SLAVE_ADDRESS_BYTE] = MAX69XX_ADDRESS || 0x80;;
	message_buffer[MAX69XX_REGISTER_ADDRESS_BYTE] = address;

	USI_TWI_Start_Transceiver_With_Data( message_buffer, MAX69XX_MESSAGE_SIZE );

	return message_buffer[MAX69XX_VALUE_BYTE];
}