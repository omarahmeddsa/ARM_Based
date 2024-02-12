/*
 * GPIO_Macros.h
 *
 *  Created on: Feb 2, 2024
 *      Author: omar
 */
#include "STD_TYPES.h"

#ifndef GPIO_MACROS_H_
#define GPIO_MACROS_H_
/****************************************************************/
// GPIO Macros

#define LOCK_REG_MASK 0x4C4F434B

// Base Address
#define GPIO_PORTA_BASE_Address   0x40004000
#define GPIO_PORTB_BASE_Address   0x40005000
#define GPIO_PORTC_BASE_Address   0x40006000
#define GPIO_PORTD_BASE_Address   0x40007000
#define GPIO_PORTE_BASE_Address   0x40024000
#define GPIO_PORTF_BASE_Address   0x40025000

// GPIO  Offset

#define GPIO_DATA_offset  0x000
#define GPIO_Dirc_offset  0x400
#define GPIO_AFSEL_offset 0x420
#define GPIO_PUR_offset   0x510
#define GPIO_PDR_offset   0x514
#define GPIO_DEN_offset   0x51C
#define GPIO_LOCK_offset  0x520
#define GPIO_CR_offset    0x524

// PINS

#define PIN0  0x0004
#define PIN1  0x0008
#define PIN2  0x0010
#define PIN3  0x0020
#define PIN4  0x0040
#define PIN5  0x0080
#define PIN6  0x0100
#define PIN7  0x0200

// PINS macros

typedef enum {

    GPIO_PIN0,
    GPIO_PIN1,
    GPIO_PIN2,
    GPIO_PIN3,
    GPIO_PIN4,
    GPIO_PIN5,
    GPIO_PIN6,
    GPIO_PIN7,

}PINS;


#endif /* GPIO_MACROS_H_ */
