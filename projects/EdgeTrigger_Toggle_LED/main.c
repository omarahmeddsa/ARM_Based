

/**
 * main.c
 */


#include "GPIO_Macros.h"
#include "GPIO_MemoryMap.h"
#include "STD_TYPES.h"

#define SW1       PF0
#define RED_LED   PF1
#define BULE_LED  PF2
#define GREEN_LED 

/***************Function prototype*********************/
void SW1_Init (void );
void GPIO_Interrput_Init (void );
void LED_Init(void );
void GPIOF_Handler (void);
/*****************************************************/
void GPIOF_Handler (void) {

	RED_LED ^= 0xFF;
	GPIO_PORTF_ICR_REG |= (1<<0);
}


void SW1_Init (void ){

    /*******************************************************/
    // Configure it as input pin
            /*First Unlock Register GPIOLOCK*/
            GPIO_PORTF_LOCK_REG = LOCK_REG_MASK;
            /*GPIOCR - allow writing commits */
            GPIO_PORTF_CR_REG |= (1<<0);
            //GPIO Port Ctrl To choose the Port mode GPIOPCTL
            GPIO_PORTF_PCTL_REG  &= 0xFFFFFFF0;                   /*For PF0*/
            // GPIO Alternate Function GPIOAFSEL for PIN
            GPIO_PORTF_AFSEL_REG &= ~(1<<0);                      /*For PF0*/
            // GPIOAMSEL Analog disable
            GPIO_PORTF_AMSEL_REG &= ~(1<<0);
            //GPIODEN Digital Enable
            GPIO_PORTF_DEN_REG   |= (1<<0);
            //pull-up Enable
            GPIO_PORTF_PUR_REG   |= (1<<0);
            //Choose the direction
            GPIO_PORTF_DIR_REG   &= ~(1<<0);
    /***************************************************************/

}


void GPIO_Interrput_Init (void ){

   //Clear GPIOIS sense mode
    GPIO_PORTF_IS_REG &= ~(1<<0);
    //Clear GPIOIBE
    GPIO_PORTF_IBE_REG &= ~(1<<0);
    //clear GPIOIEV GPIO Interrupt event
    GPIO_PORTF_IEV_REG &= ~(1<<0);
    //W 1 to GPIOICR To clear the corresponding
    GPIO_PORTF_ICR_REG |= (1<<0);
    //Set priority Interrupt Register (PRIN)
    NVIC_PRI7_REG = (NVIC_PRI7_REG & GPIO_PORTF_PRIORITY_MASK) | (GPIO_PORTF_INTERRUPT_PRIORITY << 21);
    //GPIO Interrupt Mask GPIOIM
    GPIO_PORTF_IM_REG |= (1<<0);
    // Interrupt port Enable
    NVIC_EN0_REG = 0x40000000;

}

void LED_Init(void ) {

    //GPIO Port Ctrl To choose the Port mode GPIOPCTL
    GPIO_PORTF_PCTL_REG  &= 0xFFFF000F;
    GPIO_PORTF_PCTL_REG  &= 0xFFFFFFF0;                   /*For PF0*/
    // GPIO Alternate Function GPIOAFSEL for PIN
    GPIO_PORTF_AFSEL_REG &= ~(1<<1);                      /*For PF0*/
    GPIO_PORTF_AFSEL_REG &= ~(1<<2);
    GPIO_PORTF_AFSEL_REG &= ~(1<<3);
    // GPIOAMSEL Analog disable
    GPIO_PORTF_AMSEL_REG &= ~(1<<1);
    GPIO_PORTF_AMSEL_REG &= ~(1<<2);
    GPIO_PORTF_AMSEL_REG &= ~(1<<3);
    //GPIODEN Digital Enable
    GPIO_PORTF_DEN_REG   |= (1<<1);
    GPIO_PORTF_DEN_REG   |= (1<<2);
    GPIO_PORTF_DEN_REG   |= (1<<3);
    //pull-up Enable
    GPIO_PORTF_PUR_REG   |= (1<<1);
    GPIO_PORTF_PUR_REG   |= (1<<2);
    GPIO_PORTF_PUR_REG   |= (1<<3);
    //Choose the direction
    GPIO_PORTF_DIR_REG   |= (1<<1);
    GPIO_PORTF_DIR_REG   |= (1<<2);
    GPIO_PORTF_DIR_REG   |= (1<<3);

}

int main(void)
{

    // Send CLK to GPIO
    SYSCTL_RCGCGPIO_REG |= 0x20;
    // wait until the the system is ready
    while (!(SYSCTL_PRGPIO_REG & (1<<5)));

    SW1_Init();
	GPIO_Interrput_Init();
    LED_Init();
	Enable_Exceptions() ;
		
	
	
    
	
	


    while (1){
	
			
			
				
		}		
	return 0;

}