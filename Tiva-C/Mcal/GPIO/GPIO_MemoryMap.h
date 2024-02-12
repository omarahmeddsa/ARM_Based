/*
 * GPIO_MemoryMap.h
 *
 *  Created on: Feb 2, 2024
 *      Author: omar
 */
#include "STD_TYPES.h"

#ifndef GPIO_MEMORYMAP_H_
#define GPIO_MEMORYMAP_H_

/***************************************************************/
//GPIO Map-ing

#define GPIO_RC_Reg    (*((volatile u32 *)0x400FE608))
#define GPIO_PR_Reg    (*((volatile u32 *)0x400FEA08))

// Group A

#define GPIO_PORTA_DATA_REG       (*((volatile u32 *)0x400043FC))
#define GPIO_PORTA_DIR_REG        (*((volatile u32 *)0x40004400))
#define GPIO_PORTA_AFSEL_REG      (*((volatile u32 *)0x40004420))
#define GPIO_PORTA_PUR_REG        (*((volatile u32 *)0x40004510))
#define GPIO_PORTA_PDR_REG        (*((volatile u32 *)0x40004514))
#define GPIO_PORTA_DEN_REG        (*((volatile u32 *)0x4000451C))
#define GPIO_PORTA_LOCK_REG       (*((volatile u32 *)0x40004520))
#define GPIO_PORTA_CR_REG         (*((volatile u32 *)0x40004524))
#define GPIO_PORTA_AMSEL_REG      (*((volatile u32 *)0x40004528))
#define GPIO_PORTA_PCTL_REG       (*((volatile u32 *)0x4000452C))

// Group B

#define GPIO_PORTB_DATA_REG       (*((volatile u32 *)0x400053FC))
#define GPIO_PORTB_DIR_REG        (*((volatile u32 *)0x40005400))
#define GPIO_PORTB_AFSEL_REG      (*((volatile u32 *)0x40005420))
#define GPIO_PORTB_PUR_REG        (*((volatile u32 *)0x40005510))
#define GPIO_PORTB_PDR_REG        (*((volatile u32 *)0x40005514))
#define GPIO_PORTB_DEN_REG        (*((volatile u32 *)0x4000551C))
#define GPIO_PORTB_LOCK_REG       (*((volatile u32 *)0x40005520))
#define GPIO_PORTB_CR_REG         (*((volatile u32 *)0x40005524))
#define GPIO_PORTB_AMSEL_REG      (*((volatile u32 *)0x40005528))
#define GPIO_PORTB_PCTL_REG       (*((volatile u32 *)0x4000552C))

// Group C

#define GPIO_PORTC_DATA_REG       (*((volatile u32 *)0x400063FC))
#define GPIO_PORTC_DIR_REG        (*((volatile u32 *)0x40006400))
#define GPIO_PORTC_AFSEL_REG      (*((volatile u32 *)0x40006420))
#define GPIO_PORTC_PUR_REG        (*((volatile u32 *)0x40006510))
#define GPIO_PORTC_PDR_REG        (*((volatile u32 *)0x40006514))
#define GPIO_PORTC_DEN_REG        (*((volatile u32 *)0x4000651C))
#define GPIO_PORTC_LOCK_REG       (*((volatile u32 *)0x40006520))
#define GPIO_PORTC_CR_REG         (*((volatile u32 *)0x40006524))
#define GPIO_PORTC_AMSEL_REG      (*((volatile u32 *)0x40006528))
#define GPIO_PORTC_PCTL_REG       (*((volatile u32 *)0x4000652C))

// Group D

#define GPIO_PORTD_DATA_REG       (*((volatile u32 *)0x400073FC))
#define GPIO_PORTD_DIR_REG        (*((volatile u32 *)0x40007400))
#define GPIO_PORTD_AFSEL_REG      (*((volatile u32 *)0x40007420))
#define GPIO_PORTD_PUR_REG        (*((volatile u32 *)0x40007510))
#define GPIO_PORTD_PDR_REG        (*((volatile u32 *)0x40007514))
#define GPIO_PORTD_DEN_REG        (*((volatile u32 *)0x4000751C))
#define GPIO_PORTD_LOCK_REG       (*((volatile u32 *)0x40007520))
#define GPIO_PORTD_CR_REG         (*((volatile u32 *)0x40007524))
#define GPIO_PORTD_AMSEL_REG      (*((volatile u32 *)0x40007528))
#define GPIO_PORTD_PCTL_REG       (*((volatile u32 *)0x4000752C))

// Group E

#define GPIO_PORTE_DATA_REG       (*((volatile u32 *)0x400243FC))
#define GPIO_PORTE_DIR_REG        (*((volatile u32 *)0x40024400))
#define GPIO_PORTE_AFSEL_REG      (*((volatile u32 *)0x40024420))
#define GPIO_PORTE_PUR_REG        (*((volatile u32 *)0x40024510))
#define GPIO_PORTE_PDR_REG        (*((volatile u32 *)0x40024514))
#define GPIO_PORTE_DEN_REG        (*((volatile u32 *)0x4002451C))
#define GPIO_PORTE_LOCK_REG       (*((volatile u32 *)0x40024520))
#define GPIO_PORTE_CR_REG         (*((volatile u32 *)0x40024524))
#define GPIO_PORTE_AMSEL_REG      (*((volatile u32 *)0x40024528))
#define GPIO_PORTE_PCTL_REG       (*((volatile u32 *)0x4002452C))

// Group F

#define GPIO_PORTF_DATA_REG       (*((volatile u32 *)0x400253FC))
#define GPIO_PORTF_DIR_REG        (*((volatile u32 *)0x40025400))
#define GPIO_PORTF_AFSEL_REG      (*((volatile u32 *)0x40025420))
#define GPIO_PORTF_PUR_REG        (*((volatile u32 *)0x40025510))
#define GPIO_PORTF_PDR_REG        (*((volatile u32 *)0x40025514))
#define GPIO_PORTF_DEN_REG        (*((volatile u32 *)0x4002551C))
#define GPIO_PORTF_LOCK_REG       (*((volatile u32 *)0x40025520))
#define GPIO_PORTF_CR_REG         (*((volatile u32 *)0x40025524))
#define GPIO_PORTF_AMSEL_REG      (*((volatile u32 *)0x40025528))
#define GPIO_PORTF_PCTL_REG       (*((volatile u32 *)0x4002552C))

// PINS GPIO Specific PINS

// PORTA
#define PA0         (*((volatile u32 *) (GPIO_PORTA_BASE_Address + GPIO_DATA_offset + PIN0)))
#define PA1         (*((volatile u32 *) (GPIO_PORTA_BASE_Address + GPIO_DATA_offset + PIN1)))
#define PA2         (*((volatile u32 *) (GPIO_PORTA_BASE_Address + GPIO_DATA_offset + PIN2)))
#define PA3         (*((volatile u32 *) (GPIO_PORTA_BASE_Address + GPIO_DATA_offset + PIN3)))
#define PA4         (*((volatile u32 *) (GPIO_PORTA_BASE_Address + GPIO_DATA_offset + PIN4)))
#define PA5         (*((volatile u32 *) (GPIO_PORTA_BASE_Address + GPIO_DATA_offset + PIN5)))
#define PA6         (*((volatile u32 *) (GPIO_PORTA_BASE_Address + GPIO_DATA_offset + PIN6)))
#define PA7         (*((volatile u32 *) (GPIO_PORTA_BASE_Address + GPIO_DATA_offset + PIN7)))

//PORTB

#define PB0         (*((volatile u32 *) (GPIO_PORTB_BASE_Address + GPIO_DATA_offset + PIN0)))
#define PB1         (*((volatile u32 *) (GPIO_PORTB_BASE_Address + GPIO_DATA_offset + PIN1)))
#define PB2         (*((volatile u32 *) (GPIO_PORTB_BASE_Address + GPIO_DATA_offset + PIN2)))
#define PB3         (*((volatile u32 *) (GPIO_PORTB_BASE_Address + GPIO_DATA_offset + PIN3)))
#define PB4         (*((volatile u32 *) (GPIO_PORTB_BASE_Address + GPIO_DATA_offset + PIN4)))
#define PB5         (*((volatile u32 *) (GPIO_PORTB_BASE_Address + GPIO_DATA_offset + PIN5)))
#define PB6         (*((volatile u32 *) (GPIO_PORTB_BASE_Address + GPIO_DATA_offset + PIN6)))
#define PB7         (*((volatile u32 *) (GPIO_PORTB_BASE_Address + GPIO_DATA_offset + PIN7)))

// PORTC

#define PC0         (*((volatile u32 *) (GPIO_PORTC_BASE_Address + GPIO_DATA_offset + PIN0)))
#define PC1         (*((volatile u32 *) (GPIO_PORTC_BASE_Address + GPIO_DATA_offset + PIN1)))
#define PC2         (*((volatile u32 *) (GPIO_PORTC_BASE_Address + GPIO_DATA_offset + PIN2)))
#define PC3         (*((volatile u32 *) (GPIO_PORTC_BASE_Address + GPIO_DATA_offset + PIN3)))
#define PC4         (*((volatile u32 *) (GPIO_PORTC_BASE_Address + GPIO_DATA_offset + PIN4)))
#define PC5         (*((volatile u32 *) (GPIO_PORTC_BASE_Address + GPIO_DATA_offset + PIN5)))
#define PC6         (*((volatile u32 *) (GPIO_PORTC_BASE_Address + GPIO_DATA_offset + PIN6)))
#define PC7         (*((volatile u32 *) (GPIO_PORTC_BASE_Address + GPIO_DATA_offset + PIN7)))

// PORTD

#define PD0         (*((volatile u32 *) (GPIO_PORTD_BASE_Address + GPIO_DATA_offset + PIN0)))
#define PD1         (*((volatile u32 *) (GPIO_PORTD_BASE_Address + GPIO_DATA_offset + PIN1)))
#define PD2         (*((volatile u32 *) (GPIO_PORTD_BASE_Address + GPIO_DATA_offset + PIN2)))
#define PD3         (*((volatile u32 *) (GPIO_PORTD_BASE_Address + GPIO_DATA_offset + PIN3)))
#define PD4         (*((volatile u32 *) (GPIO_PORTD_BASE_Address + GPIO_DATA_offset + PIN4)))
#define PD5         (*((volatile u32 *) (GPIO_PORTD_BASE_Address + GPIO_DATA_offset + PIN5)))
#define PD6         (*((volatile u32 *) (GPIO_PORTD_BASE_Address + GPIO_DATA_offset + PIN6)))
#define PD7         (*((volatile u32 *) (GPIO_PORTD_BASE_Address + GPIO_DATA_offset + PIN7)))

// PORTE

#define PE0         (*((volatile u32 *) (GPIO_PORTE_BASE_Address + GPIO_DATA_offset + PIN0)))
#define PE1         (*((volatile u32 *) (GPIO_PORTE_BASE_Address + GPIO_DATA_offset + PIN1)))
#define PE2         (*((volatile u32 *) (GPIO_PORTE_BASE_Address + GPIO_DATA_offset + PIN2)))
#define PE3         (*((volatile u32 *) (GPIO_PORTE_BASE_Address + GPIO_DATA_offset + PIN3)))
#define PE4         (*((volatile u32 *) (GPIO_PORTE_BASE_Address + GPIO_DATA_offset + PIN4)))
#define PE5         (*((volatile u32 *) (GPIO_PORTE_BASE_Address + GPIO_DATA_offset + PIN5)))
#define PE6         (*((volatile u32 *) (GPIO_PORTE_BASE_Address + GPIO_DATA_offset + PIN6)))
#define PE7         (*((volatile u32 *) (GPIO_PORTE_BASE_Address + GPIO_DATA_offset + PIN7)))

//PORTF

#define PF0         (*((volatile u32 *) (GPIO_PORTF_BASE_Address + GPIO_DATA_offset + PIN0)))
#define PF1         (*((volatile u32 *) (GPIO_PORTF_BASE_Address + GPIO_DATA_offset + PIN1)))
#define PF2         (*((volatile u32 *) (GPIO_PORTF_BASE_Address + GPIO_DATA_offset + PIN2)))
#define PF3         (*((volatile u32 *) (GPIO_PORTF_BASE_Address + GPIO_DATA_offset + PIN3)))
#define PF4         (*((volatile u32 *) (GPIO_PORTF_BASE_Address + GPIO_DATA_offset + PIN4)))
#define PF5         (*((volatile u32 *) (GPIO_PORTF_BASE_Address + GPIO_DATA_offset + PIN5)))
#define PF6         (*((volatile u32 *) (GPIO_PORTF_BASE_Address + GPIO_DATA_offset + PIN6)))
#define PF7         (*((volatile u32 *) (GPIO_PORTF_BASE_Address + GPIO_DATA_offset + PIN7)))





#endif /* GPIO_MEMORYMAP_H_ */
