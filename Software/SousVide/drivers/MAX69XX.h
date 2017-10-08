/*
 * _6955.h
 *
 * Created: 29/09/2017 16:33:04
 *  Author: Richard
 */ 

#include "usi_twi_master.h"

#ifndef MAX69XX_H_
#define MAX69XX_H_

/* Configuration Register Addresses */

#if defined(MAX6958) || defined (MAX6959)

	#define MAX69XX_NOOP					0x00
	#define MAX69XX_DECODE_MODE				0x01
	#define MAX69XX_GLOBAL_INTENSITY		0x02
	#define MAX69XX_SCAN_LIMIT				0x03
	#define MAX69XX_CONFIGURATION			0x04
	#define MAX69XX_DISPLAY_TEST			0x07

	#define MAX69XX_DIGIT_0					0x20
	#define MAX69XX_DIGIT_1					0x21
	#define MAX69XX_DIGIT_2					0x22
	#define MAX69XX_DIGIT_3					0x23
	#define MAX69XX_SEGMENTS				0x24

	/* Bit positions of the digits in the decode mode register */

	#define MAX69XX_DECODE_MODE_DIGIT_1		0x01 
	#define MAX69XX_DECODE_MODE_DIGIT_2		0x02
	#define MAX69XX_DECODE_MODE_DIGIT_3		0x04
	#define MAX69XX_DECODE_MODE_DIGIT_4		0x08

	/* TWI Constants */

	#define MAX69XX_MESSAGE_SIZE			3
	#define MAX69XX_SLAVE_ADDRESS_BYTE		0
	#define MAX69XX_REGISTER_ADDRESS_BYTE	1
	#define MAX69XX_VALUE_BYTE				2

	#define MAX69XX_READ_MODE				0x80

	#define MAX69XX_CONFIG_RESET			0x20
	#define MAX69XX_CONFIG_DEVICE			0x02
	#define MAX69XX_CONFIG_STARTUP			0x01

	#define MAX69XX_SCAN_LIMIT_1			0x00
	#define MAX69XX_SCAN_LIMIT_2			0x01
	#define MAX69XX_SCAN_LIMIT_3			0x02
	#define MAX69XX_SCAN_LIMIT_4			0x03

#endif /* 6958 or 6959 */

#if defined(MAX6959)

	/* keyboard scanning registers */
	#define MAX69XX_GPIO					0x06
	#define MAX69XX_KEY_DEBOUNCED			0x08
	#define MAX69XX_KEY_PRESSED				0x0C

	/* GPIO Constants */
	#define MAX69XX_LOGIC_0_OUT				0x00
	#define MAX69XX_LOGIC_1_OUT				0x20
	#define MAX69XX_IRQ_ACTIVE_LOW			0x40
	#define MAX69XX_IRQ_ACTIVE_HIGH			0x60
	#define MAX69XX_SEGMENT					0x70

	/* Key bit locations */

	#define MAX69XX_KEY_0					0x01
	#define MAX69XX_KEY_1					0x02
	#define MAX69XX_KEY_2					0x04
	#define MAX69XX_KEY_3					0x08
	#define MAX69XX_KEY_4					0x10
	#define MAX69XX_KEY_5					0x20
	#define MAX69XX_KEY_6					0x40
	#define MAX69XX_KEY_7					0x80

#endif /* MAX6959

/* prototypes */

void MAX69XX_init(void);
void MAX69XX_tx( char address, char value );
unsigned char MAX69XX_rx( char address );

#endif /* MAX69XX_H_ */
