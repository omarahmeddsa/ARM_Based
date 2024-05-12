 /******************************************************************************
 * Module: PORT
 *
 * File Name: Port_Reg.h
 *
 * Description: Addresses of registers in Tiva c Tm4c123GH6PM
 *
 * Author: Omar Ahmed
 ******************************************************************************/
#ifndef PORT_MEMMAP_H_
#define PORT_MEMMAP_H_

#include "Std_Types.h"

/*******************************************************************************
 *                              Module Definitions                             *
 *******************************************************************************/
/*************************Port Memory maps******************/
typedef struct {

        uint32 GPIO_DATA_MAP[255];//GPIO Data Register
        uint32 GPIODATA_REG;// data register
        uint32 GPIODIR_REG; // direction register
        uint32 GPIOIS_REG;//Interrupt Sense
        uint32 GPIOIBE_REG;//Interrupt both edges
        uint32 GPIOIEV_REG;//Interrupt Event
        uint32 GPIOIM_REG;//Interrupt Mask
        uint32 GPIORIS_REG;//GPIO Raw Interrupt Status
        uint32 GPIOMIS_REG;//GPIO Masked Interrupt Status
        uint32 GPIOICR_REG;// GPIO Interrupt Clear
        uint32 GPIOAFSEL_REG; //Alternate Function Select
        uint32 RESERVED1[55]; //Reserved
        uint32 GPIODR2R_REG ;//GPIO 2-mA Drive Select
        uint32 GPIODR4R_REG ;//GPIO 4-mA Drive Select
        uint32 GPIODR8R_REG ;//GPIO 8-mA Drive Select
        uint32 GPIOODR_REG;//GPIO Open Drain Select
        uint32 GPIOPUR_REG;// GPIO Pull-Up Select
        uint32 GPIOPDR_REG;// GPIO Pull-Down Select
        uint32 GPIOSLR_REG;// GPIO Slew Rate Control Select
        uint32 GPIODEN_REG;// GPIO Digital Enable
        uint32 GPIOLOCK_REG;//GPIO Lock
        uint32 GPIOCR_REG;// GPIO Commit
        uint32 GPIOAMSEL_REG;// GPIO Analog Mode Select
        uint32 GPIOPCTL_REG;// GPIO Port Control
        uint32 GPIOADCCTL_REG;// GPIO ADC Control
        uint32 GPIODMACTL_REG;// GPIO DMA Control
        uint32 GPIOPeriphID4_REG;//GPIO Peripheral Identification 4
        uint32 GPIOPeriphID5_REG;//GPIO Peripheral Identification 5
        uint32 GPIOPeriphID6_REG;//GPIO Peripheral Identification 6
        uint32 GPIOPeriphID7_REG;//GPIO Peripheral Identification 7
        uint32 GPIOPeriphID0_REG;//GPIO Peripheral Identification 0
        uint32 GPIOPeriphID1_REG;//GPIO Peripheral Identification 1
        uint32 GPIOPeriphID2_REG;//GPIO Peripheral Identification 2
        uint32 GPIOPeriphID3_REG;//GPIO Peripheral Identification 3
        uint32 GPIOPCellID0_REG;// GPIO PrimeCell Identification 0
        uint32 GPIOPCellID1_REG;// GPIO PrimeCell Identification 1
        uint32 GPIOPCellID2_REG;// GPIO PrimeCell Identification 2
        uint32 GPIOPCellID3_REG;// GPIO PrimeCell Identification 3

}M_GPIO_Type;

//-------------------DIO-------------------
#define M_GPIO_PORTA_BASE_ADDRESS ((M_GPIO_Type *)0x40004000UL)
#define M_GPIO_PORTB_BASE_ADDRESS ((M_GPIO_Type *)0x40005000UL)
#define M_GPIO_PORTC_BASE_ADDRESS ((M_GPIO_Type *)0x40006000UL)
#define M_GPIO_PORTD_BASE_ADDRESS ((M_GPIO_Type *)0x40007000UL)
#define M_GPIO_PORTE_BASE_ADDRESS ((M_GPIO_Type *)0x40024000UL)
#define M_GPIO_PORTF_BASE_ADDRESS ((M_GPIO_Type *)0x40025000UL)
//------------------ END of DIO------------

//-------------------System Control-------------------
#define RCC_RCGCGPIO_REG    *((volatile uint32*)(0x400FE000UL + 0x608))
#define PRGPIO_REG          *(((volatile uint32*)0x400FEA08))



#endif /* PORT_MEMMAP_H_ */
