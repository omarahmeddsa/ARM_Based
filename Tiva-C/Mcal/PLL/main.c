
/*
 * GPIO_Macros.h
 *
 *  Created on: Feb 2, 2024
 *      Author: Omar
 * main.c
 */

#include "STD_TYPES.h"
#include "Bit_calc.h"
#include "GPIO_MemoryMap.h"
#include "GPIO_Macros.h"


#define  RED_LED   PF1
#define  BULE_LED   PF2
#define  GREEN_LED   PF3


#define NUMBER_OF_ITERATIONS_PER_ONE_MILI_SECOND 364

void Delay_MS(unsigned long long n);
void LED_Init (void);
void Delay_MS(unsigned long long n)

{
    volatile unsigned long long count = 0;
    while(count++ < (NUMBER_OF_ITERATIONS_PER_ONE_MILI_SECOND * n) );
}
/* configure the system to get its clock from the PLL with Frequency 80Mhz */
void PLL_Init(void)
{
    /* 1) Configure the system to use RCC2 for advanced features
          such as 400 MHz PLL and non-integer System Clock Divisor */
    SYSCTL_RCC2_REG |= SYSCTL_RCC2_USERCC2_MASK;

    /* 2) Bypass PLL while initializing, Don’t use PLL while initialization */
    SYSCTL_RCC2_REG |= SYSCTL_RCC2_BYPASS2_MASK;

    /* 3) Select the crystal value and oscillator source */
    SYSCTL_RCC_REG  &= ~SYSCTL_RCC_XTAL_MASK;     /* clear XTAL field */
    SYSCTL_RCC_REG  |= (SYSCTL_RCC_XTAL_16MHZ << SYSCTL_RCC_XTAL_BIT_POS);  /* Set the XTAL bits for 16 MHz crystal */

    SYSCTL_RCC2_REG &= ~SYSCTL_RCC2_OSCSRC2_MASK; /* clear oscillator source field (OSCSRC2 bits) */
    SYSCTL_RCC2_REG |= (SYSCTL_RCC2_OSCSRC2_MOSC << SYSCTL_RCC2_OSCSRC2_BIT_POS);  /* configure for main oscillator source */

    /* 4) Activate PLL by clearing PWRDN2 */
    SYSCTL_RCC2_REG &= ~ SYSCTL_RCC2_PWRDN2_MASK;

    /* 5) Set the desired system divider and the system divider least significant bit */
    SYSCTL_RCC2_REG |= SYSCTL_RCC2_DIV400_MASK;  /* use 400 MHz PLL */

    SYSCTL_RCC2_REG  = (SYSCTL_RCC2_REG & ~SYSCTL_RCC2_SYSDIV2_MASK)        /* clear system clock divider field */
                       | (SYSDIV2_VALUE_40 << SYSCTL_RCC2_SYSDIV2_BIT_POS);      /* configure for 80MHz clock */

    /* 6) Wait for the PLL to lock by polling PLLLRIS bit */
    while(!(SYSCTL_RIS_REG & SYSCTL_RIS_PLLLRIS_MASK));

    /* 7) Enable use of PLL by clearing BYPASS2 */
    SYSCTL_RCC2_REG &= ~SYSCTL_RCC2_BYPASS2_MASK;
}
void Systick_Init (void){

    // Disable Control
    SYSTICK_CTRL_REG = 0 ;
    // Set the value of the Re Load

    SYSTICK_RELOAD_REG = 15999999;
    // Put Current reg = 0
    SYSTICK_CURRENT_REG = 0;

    //
    SYSTICK_CTRL_REG   |= 0x05;
}
void LED_Init (void){

    // GPIO UNLOCK GPIOLOCK
    GPIO_PORTF_CR_REG &= 0xF1;
  /*  Set_Bit(GPIO_PORTF_CR_REG,RED_LED);
    Set_Bit(GPIO_PORTF_CR_REG,BULE_LED);
    Set_Bit(GPIO_PORTF_CR_REG,GREEN_LED);*/
    // Configure Port Control PCTL as GPIO PIN GPIOPCTL
    GPIO_PORTF_PCTL_REG &= 0xFFFF000F;
    //ENB OR DIS Analog GPIOAMSEL
    Clear_Bit(GPIO_PORTF_AMSEL_REG,GPIO_PIN1);
    Clear_Bit(GPIO_PORTF_AMSEL_REG,GPIO_PIN2);
    Clear_Bit(GPIO_PORTF_AMSEL_REG,GPIO_PIN3);
    //GPIO Direction
    Set_Bit(GPIO_PORTF_DIR_REG, GPIO_PIN1);
    Set_Bit(GPIO_PORTF_DIR_REG, GPIO_PIN2);
    Set_Bit(GPIO_PORTF_DIR_REG, GPIO_PIN3);
    // Enable Or Disable alternate Function GPIOAFSEL

    Clear_Bit(GPIO_PORTF_AFSEL_REG,GPIO_PIN1);
    Clear_Bit(GPIO_PORTF_AFSEL_REG,GPIO_PIN2);
    Clear_Bit(GPIO_PORTF_AFSEL_REG,GPIO_PIN3);

    //GPIO Digital enable or disable  GPIO DEN
    Set_Bit(GPIO_PORTF_DEN_REG,GPIO_PIN1);
    Set_Bit(GPIO_PORTF_DEN_REG,GPIO_PIN2);
    Set_Bit(GPIO_PORTF_DEN_REG,GPIO_PIN3);
    //Turn off Led

    Clear_Bit(GPIO_PORTF_DATA_REG,GPIO_PIN1  );
    Clear_Bit(GPIO_PORTF_DATA_REG,GPIO_PIN2  );
    Clear_Bit(GPIO_PORTF_DATA_REG,GPIO_PIN3  );
}


void main(void){
   // Set_Bit(GPIO_RC_Reg,GPIO_PIN5);
    GPIO_RC_Reg |= 0x20;
    while (!(Get_Bit(GPIO_PR_Reg,GPIO_PIN5)));
   // Delay_MS(1000);
    GPIO_PORTF_LOCK_REG = LOCK_REG_MASK;

    // Enable Clock For PORTF RCGCGPIO


    // busy flag


    LED_Init();


    Systick_Init();

    while (1){

            RED_LED = 0x02;
            BULE_LED = 0x00 ;
            GREEN_LED = 0x00;

            while (!(SYSTICK_CTRL_REG &( 1<< 16)));

            RED_LED = 0x00;
            BULE_LED = 0x04 ;
            GREEN_LED = 0x00;

            while (!(SYSTICK_CTRL_REG &( 1<< 16)));

            RED_LED  =    0x00;
            BULE_LED =   0x00 ;
            GREEN_LED =  0x08;

            while (!(SYSTICK_CTRL_REG &( 1<< 16)));

     }

}
