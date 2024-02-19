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

#define LOCK_REG_MASK 0x4C4F434B /*This mask unlock the register so that any commit will be processed */
#define PORT_PINS     0x03FC
#define GPIO_PORTF_PRIORITY_MASK      0xFF1FFFFF
#define GPIO_PORTF_PRIORITY_BITS_POS  21
#define GPIO_PORTF_INTERRUPT_PRIORITY 2
// Base Address
#define GPIO_PORTA_BASE_Address   0x40004000
#define GPIO_PORTB_BASE_Address   0x40005000
#define GPIO_PORTC_BASE_Address   0x40006000
#define GPIO_PORTD_BASE_Address   0x40007000
#define GPIO_PORTE_BASE_Address   0x40024000
#define GPIO_PORTF_BASE_Address   0x40025000
#define GPIO_Turn_ON              0xFFFFFFFF
#define GPIO_Turn_OFF             0x00000000
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

// BusFault Macros
#define BusFault_Mask 0xFFFF1FFF 
#define BusPrioity    6

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

// PLL Macros
#define SYSCTL_RCC2_USERCC2_MASK        0x80000000  /* USERCC2 Bit MASK */
#define SYSCTL_RCC2_BYPASS2_MASK        0x00000800  /* PLL BYPASS2 Bit MASK */
#define SYSCTL_RCC_XTAL_MASK            0x000007C0  /* XTAL Bits MASK */
#define SYSCTL_RCC_XTAL_8MHZ            0x0E        /* 8 MHz Crystal Value */
#define SYSCTL_RCC_XTAL_16MHZ           0x15        /* 16 MHz Crystal Value */
#define SYSCTL_RCC_XTAL_BIT_POS         6           /* XTAL Bits Position start from bit number 6 */
#define SYSCTL_RCC2_OSCSRC2_MASK        0x00000070  /* OSCSRC2 Bits MASK */
#define SYSCTL_RCC2_OSCSRC2_MOSC        0x0         /* MOSC(Main Oscillator) value */
#define SYSCTL_RCC2_OSCSRC2_BIT_POS     4           /* OSCSRC2 Bits Position start from bit number 4 */
#define SYSCTL_RCC2_PWRDN2_MASK         0x00002000  /* PWRDN2 Bit MASK */
#define SYSCTL_RCC2_DIV400_MASK         0x40000000  /* DIV400 Bit MASK to Divide PLL as 400 MHz vs. 200 */
#define SYSCTL_RCC2_SYSDIV2_MASK        0x1FC00000  /* SYSDIV2 Bits MASK */
#define SYSCTL_RIS_PLLLRIS_MASK         0x00000040  /* PLLLRIS Bit MASK */
#define SYSCTL_RCC2_SYSDIV2_BIT_POS     22       /* SYSDIV2 Bits Position start from bit number 22 */
#define SYSDIV2_VALUE_5                 4
#define SYSDIV2_VALUE_40                39


//

// Asm Macros
/* Enable Exceptions ... This Macro enable IRQ interrupts, Programmable Systems Exceptions and Faults by clearing the I-bit in the PRIMASK. */
#define Enable_Exceptions()    __asm(" CPSIE I ")

/* Disable Exceptions ... This Macro disable IRQ interrupts, Programmable Systems Exceptions and Faults by setting the I-bit in the PRIMASK. */
#define Disable_Exceptions()   __asm(" CPSID I ")

/* Enable Faults ... This Macro enable Faults by clearing the F-bit in the FAULTMASK */
#define Enable_Faults()        __asm(" CPSIE F ")

/* Disable Faults ... This Macro disable Faults by setting the F-bit in the FAULTMASK */
#define Disable_Faults()       __asm(" CPSID F ")

/* Go to low power mode while waiting for the next interrupt */
#define Wait_For_Interrupt()   __asm(" WFI ")
/*Active SVC */
#define Trigger_SVC_Exception() __asm("SVC #1")
#endif /* GPIO_MACROS_H_ */
