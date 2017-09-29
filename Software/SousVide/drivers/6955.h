/*
 * _6955.h
 *
 * Created: 29/09/2017 16:33:04
 *  Author: Richard
 */ 

#include "board.h"
#include "usi_twi_master.h"

#ifndef 6955_H_
#define 6955_H_

/* Configuration Register Addresses */

#define 6955_NOOP					0x00
#define 6955_DECODE_MODE			0x01
#define 6955_GLOBAL_INTENSITY		0x02
#define 6955_SCAN_LIMIT				0x03
#define 6955_CONFIGURATION			0x04
#define 6955_GPIO_DATA				0x05
#define 6955_PORT_CONFIGURATION		0x06
#define 6955_DISPLAY_TEST			0x07

/* The following registers have different read/write uses. Write is first */

#define 6955_KEY_A_MASK				0x08  /* write */
#define 6955_KEY_A_DEBOUNCE			0x08  /* read */

#define 6955_KEY_B_MASK				0x09  /* write */
#define 6955_KEY_B_DEBOUNCE			0x09  /* read */

#define 6955_KEY_C_MASK				0x0A  /* write */
#define 6955_KEY_C_DEBOUNCE			0x0A  /* read */

#define 6955_KEY_D_MASK				0x0B  /* write */
#define 6955_KEY_D_DEBOUNCE			0x0B  /* read */

#define 6955_DIGIT_TYPE				0x0C  /* write */
#define 6955_KEY_A_PRESSED			0x0C  /* read */

#define 6955_KEY_B_PRESSED			0x0D
#define 6955_KEY_C_PRESSED			0x0E
#define 6955_KEY_D_PRESSED			0x0F

/* intesity definitions */

#define 6955_INTENSITY_10			0x10
#define 6955_INTENSITY_32			0x11
#define 6955_INTENSITY_54			0x12
#define 6955_INTENSITY_76			0x13

#define 6955_INTENSITY_10A			0x14
#define 6955_INTENSITY_32A			0x15
#define 6955_INTENSITY_54A			0x16
#define 6955_INTENSITY_76A			0x17


/* digit definitions */

#define 6955_DIGIT_0_PLANE_P0		0x20
#define 6955_DIGIT_1_PLANE_P0		0x21
#define 6955_DIGIT_2_PLANE_P0		0x22
#define 6955_DIGIT_3_PLANE_P0		0x23
#define 6955_DIGIT_4_PLANE_P0		0x24
#define 6955_DIGIT_5_PLANE_P0		0x25
#define 6955_DIGIT_6_PLANE_P0		0x26
#define 6955_DIGIT_7_PLANE_P0		0x27

#define 6955_DIGIT_0A_PLANE_P0		0x28
#define 6955_DIGIT_1A_PLANE_P0		0x29
#define 6955_DIGIT_2A_PLANE_P0		0x2A
#define 6955_DIGIT_3A_PLANE_P0		0x2B
#define 6955_DIGIT_4A_PLANE_P0		0x2C
#define 6955_DIGIT_5A_PLANE_P0		0x2D
#define 6955_DIGIT_6A_PLANE_P0		0x2E
#define 6955_DIGIT_7A_PLANE_P0		0x2F

#define 6955_DIGIT_0_PLANE_P1		0x40
#define 6955_DIGIT_1_PLANE_P1		0x41
#define 6955_DIGIT_2_PLANE_P1		0x42
#define 6955_DIGIT_3_PLANE_P1		0x43
#define 6955_DIGIT_4_PLANE_P1		0x44
#define 6955_DIGIT_5_PLANE_P1		0x45
#define 6955_DIGIT_6_PLANE_P1		0x46
#define 6955_DIGIT_7_PLANE_P1		0x47

#define 6955_DIGIT_0A_PLANE_P1		0x48
#define 6955_DIGIT_1A_PLANE_P1		0x49
#define 6955_DIGIT_2A_PLANE_P1		0x4A
#define 6955_DIGIT_3A_PLANE_P1		0x4B
#define 6955_DIGIT_4A_PLANE_P1		0x4C
#define 6955_DIGIT_5A_PLANE_P1		0x4D
#define 6955_DIGIT_6A_PLANE_P1		0x4E
#define 6955_DIGIT_7A_PLANE_P1		0x4F

/* write only registers */

#define 6955_DIGIT_0_BOTH			0x60
#define 6955_DIGIT_1_BOTH			0x61
#define 6955_DIGIT_2_BOTH			0x62
#define 6955_DIGIT_3_BOTH			0x63
#define 6955_DIGIT_4_BOTH			0x64
#define 6955_DIGIT_5_BOTH			0x65
#define 6955_DIGIT_6_BOTH			0x66
#define 6955_DIGIT_7_BOTH			0x67

#define 6955_DIGIT_0A_BOTH			0x68
#define 6955_DIGIT_1A_BOTH			0x69
#define 6955_DIGIT_2A_BOTH			0x6A
#define 6955_DIGIT_3A_BOTH			0x6B
#define 6955_DIGIT_4A_BOTH			0x6C
#define 6955_DIGIT_5A_BOTH			0x6D
#define 6955_DIGIT_6A_BOTH			0x6E
#define 6955_DIGIT_7A_BOTH			0x6F

/* prototypes */

void init_6995 (void);

#endif /* 6955_H_ */