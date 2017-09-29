/*
 * board.h
 *
 * Created: 29/09/2017 14:37:34
 *  Author: Richard
 */ 


#ifndef BOARD_H_
#define BOARD_H_

/* Define I2C ports */

#define SDA             0           // SDA Port B, Pin 0
#define SCL             2           // SCL Port B, Pin 2
#define SDA_PORT        PORTB       // SDA Port B
#define SCL_PORT        PORTB       // SCL Port B

#define F_CPU 4000000UL

/* TWI constants */
#define DDR_USI DDRB
#define PORT_USI PORTB
#define PIN_USI PINB
#define PORT_USI_SDA PORTB0
#define PORT_USI_SCL PORTB2
#define PIN_USI_SDA PINB0
#define PIN_USI_SCL PINB2

/* I2C addresses */

#define 6955_ADDRESS B11000000

/* prototypes */

void board_init (void);

#endif /* BOARD_H_ */