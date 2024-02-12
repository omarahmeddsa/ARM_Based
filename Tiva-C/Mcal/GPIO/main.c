
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



    while (1){

            RED_LED = 0x02;
            BULE_LED = 0x00 ;
            GREEN_LED = 0x00;

        Delay_MS(1000);

            RED_LED = 0x00;
            BULE_LED = 0x04 ;
            GREEN_LED = 0x00;

        Delay_MS(1000);

            RED_LED  =    0x00;
            BULE_LED =   0x00 ;
            GREEN_LED =  0x08;

        Delay_MS(1000);

     }

}
