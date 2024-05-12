/******************************************************************************
 *
 * Module: PORT
 *
 * File Name: Port.c
 *
 * Description: Functions implementation - Port Driver
 *
 * Author: Omar Ahmed
 ******************************************************************************/

/*****************************
 * Port.c Includes           *
 ****************************/
#include "Port.h"
#include "Port_MemMap.h"
#include "Det.h"

/*********************************************
 *  Global Variable                          *
 * Holds the status of the Port              *
 * options: PORT_NOT_INITIALIZED             *
 *          PORT_INITIALIZED                 *
 **********************************************/

STATIC uint8 Port_Status = PORT_NOT_INITIALIZED;

/***************************
 * Global index of array   *
 ***************************/
volatile  uint32 i ;
/***************************/

#if (PORT_DEV_ERROR_DETECT == STD_ON)


/* AUTOSAR Version checking between Det and Port Modules */
#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
        || (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
        || (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
#error "The AR version of Det.h does not match the expected version"
#endif

#endif

/************************************************************************************
 * Service Name: Port_Init
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * Parameters (in): ConfigPtr - Pointer to configuration set
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Initialize the Port Driver module.
 ************************************************************************************/

void Port_Init (const Port_ConfigType * ConfigPtr){

    //----------------Init Port global variable
    Port_Status = PORT_INITIALIZED;
#if (PORT_DEV_ERROR_DETECT == STD_ON)
    /* check if the input configuration pointer is not a NULL_PTR */
    if(ConfigPtr == NULL_PTR)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID, PORT_E_PARAM_CONFIG);
    }
    else
    {   /* Do Nothing */    }
#endif
    /*Disable Interrupts*/
    Disable_Exceptions();
    //-----Local Variable
    uint8 Local_Copy_Pin_ID = 0;
    uint8 Local_Copy_Port_ID = 0;
    //Loop on the array of pins depending on the Number of the required pin
    for (i  = 0 ; i <PORT_CONFIGURED_PINS ; i++){
        Local_Copy_Port_ID = ((ConfigPtr[i].PIN_ID)/10);
        Local_Copy_Pin_ID = ((ConfigPtr[i].PIN_ID)%10);

        //------- Send Clock To the port and wait
        if (((ConfigPtr[i].PIN_ID)/10) != ((ConfigPtr[i-1].PIN_ID)/10) ) {
            SET_BIT(RCC_RCGCGPIO_REG,Local_Copy_Port_ID);

        }
        //------- Calling Function to set the direction of the Pin
        Port_SetPinDirection(ConfigPtr[i] . PIN_ID, ConfigPtr[i] . direction);
        //------ Set the Resistor mode
        /*options
         * Pull-Up
         * Pull-Down*/
        if (ConfigPtr[i].resistor==PULL_UP){

            SET_BIT(M_GPIO_PORTA_BASE_ADDRESS->GPIOPUR_REG,Local_Copy_Pin_ID);
        }

        else  if (ConfigPtr[i].resistor==PULL_DOWN) {
            CLEAR_BIT(M_GPIO_PORTA_BASE_ADDRESS->GPIOPDR_REG,Local_Copy_Pin_ID);
        }
        else {
            /*Do Nothing*/
        }
        //Set The initial value of each Pin
        /*Options
         * PORT_PIN_LEVEL_HIGH
         * PORT_PIN_LEVEL_LOW
         */
        if (ConfigPtr[i] . initial_value == PORT_PIN_LEVEL_HIGH){

            SET_BIT(M_GPIO_PORTA_BASE_ADDRESS->GPIODATA_REG,Local_Copy_Pin_ID);

        }
        else if (ConfigPtr[i] . initial_value == PORT_PIN_LEVEL_LOW){

            CLEAR_BIT(M_GPIO_PORTA_BASE_ADDRESS->GPIODATA_REG,Local_Copy_Pin_ID);

        }
        else
        {/*Do Nothing*/ }
    }
    //--------------Calling Function to set Pin Mode
    /*Options
     *Port
     *ADC
     *Analog
     *Digital
     */
    Port_SetPinMode(ConfigPtr[i] .PIN_ID, ConfigPtr[i] .initial_mode);
    /*Enable Interrupts*/
    Enable_Exceptions();

}

/************************************************************************************
 * Service Name: Port_SetPinDirection
 * Service ID[hex]: 0x01
 * Sync/Async: Synchronous
 * Re-entrancy: reentrant
 * Parameters (in): Pin - Port Pin ID number , Direction - Port Pin Direction
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Sets the port pin direction.
 ************************************************************************************/
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)

void Port_SetPinDirection(Port_PinType Pin_ID, Port_PinDirectionType Direction ){
    static  uint32 i;
    //---- Local variables to carry the Pin ID and Number
#if (PORT_DEV_ERROR_DETECT == STD_ON)
    /* Check if the Driver is initialized before using this function */
    if(Port_Status == PORT_NOT_INITIALIZED)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIR_SID, PORT_E_UNINIT);
    }
    else
    {   /* Do Nothing */    }

    /* check if incorrect Port Pin ID passed */
    if(Direction >= PORT_CONFIGURED_PINS)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIR_SID, PORT_E_PARAM_PIN);
    }
    else
    {   /* Do Nothing */    }

#endif
    /* check if Port Pin not configured as changeable */
    if(Port_PinConfig[i] . pin_dir_changeable == STD_OFF)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIR_SID, PORT_E_DIRECTION_UNCHANGEABLE);
    }
    else
    {   /* Do Nothing */    }


    uint8 Local_Copy_Port_ID;
    uint8 Local_Copy_Pin_ID;

    Local_Copy_Port_ID = Pin_ID /10;
    Local_Copy_Pin_ID =Pin_ID %10;

    //---- Switch on Pin ID (PortA, B, C)
    switch (Local_Copy_Port_ID){

    case PORTA_ID:

        if (Direction==PORT_PIN_IN){
            CLEAR_BIT(M_GPIO_PORTA_BASE_ADDRESS->GPIODIR_REG,Local_Copy_Pin_ID);
        }
        else if(Direction==PORT_PIN_OUT){

            SET_BIT(M_GPIO_PORTA_BASE_ADDRESS->GPIODIR_REG,Local_Copy_Pin_ID);

        }
        else {
            /*Do Nothing*/
        }
    case PORTB_ID :

        if (Direction==PORT_PIN_IN){
            CLEAR_BIT(M_GPIO_PORTA_BASE_ADDRESS->GPIODIR_REG,Local_Copy_Pin_ID);
        }
        else if(Direction==PORT_PIN_OUT){

            SET_BIT(M_GPIO_PORTA_BASE_ADDRESS->GPIODIR_REG,Local_Copy_Pin_ID);

        }
        else {
            /*Do Nothing*/
        }

        break;

    case PORTC_ID:

        if (Direction==PORT_PIN_IN){
            CLEAR_BIT(M_GPIO_PORTA_BASE_ADDRESS->GPIODIR_REG,Local_Copy_Pin_ID);
        }
        else if(Direction==PORT_PIN_OUT){

            SET_BIT(M_GPIO_PORTA_BASE_ADDRESS->GPIODIR_REG,Local_Copy_Pin_ID);

        }
        else {
            /*Do Nothing*/
        }

        break;

    case PORTD_ID:

        if (Direction==PORT_PIN_IN){
            CLEAR_BIT(M_GPIO_PORTA_BASE_ADDRESS->GPIODIR_REG,Local_Copy_Pin_ID);
        }
        else if(Direction==PORT_PIN_OUT){

            SET_BIT(M_GPIO_PORTA_BASE_ADDRESS->GPIODIR_REG,Local_Copy_Pin_ID);

        }
        else {
            /*Do Nothing*/
        }

        break;

    case PORTE_ID:

        if (Direction==PORT_PIN_IN){
            CLEAR_BIT(M_GPIO_PORTA_BASE_ADDRESS->GPIODIR_REG,Local_Copy_Pin_ID);
        }
        else if(Direction==PORT_PIN_OUT){

            SET_BIT(M_GPIO_PORTA_BASE_ADDRESS->GPIODIR_REG,Local_Copy_Pin_ID);

        }
        else {
            /*Do Nothing*/
        }


        break;

    case PORTF_ID:

        if (Direction==PORT_PIN_IN){
            CLEAR_BIT(M_GPIO_PORTA_BASE_ADDRESS->GPIODIR_REG,Local_Copy_Pin_ID);
        }
        else if(Direction==PORT_PIN_OUT){

            SET_BIT(M_GPIO_PORTA_BASE_ADDRESS->GPIODIR_REG,Local_Copy_Pin_ID);

        }
        else {
            /*Do Nothing*/
        }

        break;

    }
}
#endif

/************************************************************************************
 * Service Name: Port_SetPinMode
 * Service ID[hex]: 0x04
 * Sync/Async: Synchronous
 * Re-entrancy: reentrant
 * Parameters (in): Pin - Port Pin ID number, Mode - New Port Pin mode to be set on port pin
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Sets the port pin mode.
 ************************************************************************************/

#if (PORT_SET_PIN_MODE_API == STD_ON)
void Port_SetPinMode( Port_PinType Pin,  Port_PinModeType Mode ) {

#if (PORT_DEV_ERROR_DETECT == STD_ON)
    /* Check if the Driver is initialized before using this function */
    if(Port_Status == PORT_NOT_INITIALIZED)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_UNINIT);
    }
    else
    {   /* Do Nothing */    }

    /* check if incorrect Port Pin ID passed */
    if(Pin >= PORT_CONFIGURED_PINS)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_PARAM_PIN);
    }
    else
    {   /* Do Nothing */    }
#endif

    uint8 Local_Copy_Port_ID;
    uint8 Local_Copy_Pin_ID;

    Local_Copy_Port_ID = Pin /10;
    Local_Copy_Pin_ID =Pin %10;

    switch (Local_Copy_Port_ID){
    case PORTA_ID :

        if (Mode==PORT_PinMode){
            /**Disable Analog**/
            CLEAR_BIT(M_GPIO_PORTA_BASE_ADDRESS->GPIOAMSEL_REG, Local_Copy_Pin_ID );
            /**Enable Digital */
            SET_BIT( M_GPIO_PORTA_BASE_ADDRESS->GPIODEN_REG , Local_Copy_Pin_ID);
            /**Disable Alternate Function**/
            CLEAR_BIT(M_GPIO_PORTA_BASE_ADDRESS->GPIOAFSEL_REG, Local_Copy_Pin_ID);

        }

        else if (Mode == Anlog_PinMode){
            /**Enable Analog**/
            SET_BIT(M_GPIO_PORTA_BASE_ADDRESS->GPIOAMSEL_REG, Local_Copy_Pin_ID );
            /**Disable  Digital */
            CLEAR_BIT( M_GPIO_PORTA_BASE_ADDRESS->GPIODEN_REG , Local_Copy_Pin_ID);
            /**Disable Alternate Function**/
            CLEAR_BIT(M_GPIO_PORTA_BASE_ADDRESS->GPIOAFSEL_REG, Local_Copy_Pin_ID);
        }

        else if (Mode == UART_PinMode){
            /**Disable Analog**/
            CLEAR_BIT(M_GPIO_PORTA_BASE_ADDRESS->GPIOAMSEL_REG, Local_Copy_Pin_ID );
            /**Enable Digital */
            SET_BIT( M_GPIO_PORTA_BASE_ADDRESS->GPIODEN_REG , Local_Copy_Pin_ID);
            /**Disable Alternate Function**/
            SET_BIT(M_GPIO_PORTA_BASE_ADDRESS->GPIOAFSEL_REG, Local_Copy_Pin_ID);
            // Set the value for the alternate function
            M_GPIO_PORTA_BASE_ADDRESS->GPIOPCTL_REG |=( UART_PCTL_value_PortA << Local_Copy_Pin_ID);

        }

        else if (Mode == CAN_PinMode){
            /**Disable Analog**/
            CLEAR_BIT(M_GPIO_PORTA_BASE_ADDRESS->GPIOAMSEL_REG, Local_Copy_Pin_ID );
            /**Enable Digital */
            SET_BIT( M_GPIO_PORTA_BASE_ADDRESS->GPIODEN_REG , Local_Copy_Pin_ID);
            /**Disable Alternate Function**/
            SET_BIT(M_GPIO_PORTA_BASE_ADDRESS->GPIOAFSEL_REG, Local_Copy_Pin_ID);
            // Set the value for the alternate function
            M_GPIO_PORTA_BASE_ADDRESS->GPIOPCTL_REG |=(CAN_PCTL_value_PortA << Local_Copy_Pin_ID);
        }


        else {
            /*Do Nothing*/
        }

        break;

    case PORTB_ID :

        if (Mode==PORT_PinMode){
            /**Disable Analog**/
            CLEAR_BIT(M_GPIO_PORTB_BASE_ADDRESS->GPIOAMSEL_REG, Local_Copy_Pin_ID );
            /**Enable Digital */
            SET_BIT( M_GPIO_PORTB_BASE_ADDRESS->GPIODEN_REG , Local_Copy_Pin_ID);
            /**Disable Alternate Function**/
            CLEAR_BIT(M_GPIO_PORTB_BASE_ADDRESS->GPIOAFSEL_REG, Local_Copy_Pin_ID);

        }

        else if (Mode == Anlog_PinMode){
            /**Enable Analog**/
            SET_BIT(M_GPIO_PORTB_BASE_ADDRESS->GPIOAMSEL_REG, Local_Copy_Pin_ID );
            /**Disable  Digital */
            CLEAR_BIT( M_GPIO_PORTB_BASE_ADDRESS->GPIODEN_REG , Local_Copy_Pin_ID);
            /**Disable Alternate Function**/
            CLEAR_BIT(M_GPIO_PORTB_BASE_ADDRESS->GPIOAFSEL_REG, Local_Copy_Pin_ID);
        }

        else if (Mode == UART_PinMode){
            /**Disable Analog**/
            CLEAR_BIT(M_GPIO_PORTB_BASE_ADDRESS->GPIOAMSEL_REG, Local_Copy_Pin_ID );
            /**Enable Digital */
            SET_BIT( M_GPIO_PORTB_BASE_ADDRESS->GPIODEN_REG , Local_Copy_Pin_ID);
            /**Disable Alternate Function**/
            SET_BIT(M_GPIO_PORTB_BASE_ADDRESS->GPIOAFSEL_REG, Local_Copy_Pin_ID);
            // Set the value for the alternate function
            M_GPIO_PORTB_BASE_ADDRESS->GPIOPCTL_REG |=( UART_PCTL_value_PortB << Local_Copy_Pin_ID);

        }

        else if (Mode == CAN_PinMode){
            /**Disable Analog**/
            CLEAR_BIT(M_GPIO_PORTB_BASE_ADDRESS->GPIOAMSEL_REG, Local_Copy_Pin_ID );
            /**Enable Digital */
            SET_BIT( M_GPIO_PORTB_BASE_ADDRESS->GPIODEN_REG , Local_Copy_Pin_ID);
            /**Disable Alternate Function**/
            SET_BIT(M_GPIO_PORTB_BASE_ADDRESS->GPIOAFSEL_REG, Local_Copy_Pin_ID);
            // Set the value for the alternate function
            M_GPIO_PORTB_BASE_ADDRESS->GPIOPCTL_REG |=(CAN_PCTL_value_PortB << Local_Copy_Pin_ID);
        }


        else {
            /*Do Nothing*/
        }
        break;

    case PORTC_ID :

        if (Mode==PORT_PinMode){
            /**Disable Analog**/
            CLEAR_BIT(M_GPIO_PORTC_BASE_ADDRESS->GPIOAMSEL_REG, Local_Copy_Pin_ID );
            /**Enable Digital */
            SET_BIT( M_GPIO_PORTC_BASE_ADDRESS->GPIODEN_REG , Local_Copy_Pin_ID);
            /**Disable Alternate Function**/
            CLEAR_BIT(M_GPIO_PORTC_BASE_ADDRESS->GPIOAFSEL_REG, Local_Copy_Pin_ID);

        }

        else if (Mode == Anlog_PinMode){
            /**Enable Analog**/
            SET_BIT(M_GPIO_PORTC_BASE_ADDRESS->GPIOAMSEL_REG, Local_Copy_Pin_ID );
            /**Disable  Digital */
            CLEAR_BIT( M_GPIO_PORTC_BASE_ADDRESS->GPIODEN_REG , Local_Copy_Pin_ID);
            /**Disable Alternate Function**/
            CLEAR_BIT(M_GPIO_PORTC_BASE_ADDRESS->GPIOAFSEL_REG, Local_Copy_Pin_ID);
        }

        else if (Mode == UART_PinMode){
            /**Disable Analog**/
            CLEAR_BIT(M_GPIO_PORTC_BASE_ADDRESS->GPIOAMSEL_REG, Local_Copy_Pin_ID );
            /**Enable Digital */
            SET_BIT( M_GPIO_PORTC_BASE_ADDRESS->GPIODEN_REG , Local_Copy_Pin_ID);
            /**Disable Alternate Function**/
            SET_BIT(M_GPIO_PORTC_BASE_ADDRESS->GPIOAFSEL_REG, Local_Copy_Pin_ID);
            // Set the value for the alternate function
            M_GPIO_PORTC_BASE_ADDRESS->GPIOPCTL_REG |=( UART_PCTL_value_PortC << Local_Copy_Pin_ID);

        }

        else if (Mode == CAN_PinMode){
            /**Disable Analog**/
            CLEAR_BIT(M_GPIO_PORTC_BASE_ADDRESS->GPIOAMSEL_REG, Local_Copy_Pin_ID );
            /**Enable Digital */
            SET_BIT( M_GPIO_PORTC_BASE_ADDRESS->GPIODEN_REG , Local_Copy_Pin_ID);
            /**Disable Alternate Function**/
            SET_BIT(M_GPIO_PORTC_BASE_ADDRESS->GPIOAFSEL_REG, Local_Copy_Pin_ID);
            // Set the value for the alternate function
            M_GPIO_PORTC_BASE_ADDRESS->GPIOPCTL_REG |=(CAN_PCTL_value_PortC << Local_Copy_Pin_ID);
        }


        else {
            /*Do Nothing*/
        }
        break;

    case PORTE_ID :

        if (Mode==PORT_PinMode){
            /**Disable Analog**/
            CLEAR_BIT(M_GPIO_PORTE_BASE_ADDRESS->GPIOAMSEL_REG, Local_Copy_Pin_ID );
            /**Enable Digital */
            SET_BIT( M_GPIO_PORTE_BASE_ADDRESS->GPIODEN_REG , Local_Copy_Pin_ID);
            /**Disable Alternate Function**/
            CLEAR_BIT(M_GPIO_PORTE_BASE_ADDRESS->GPIOAFSEL_REG, Local_Copy_Pin_ID);

        }

        else if (Mode == Anlog_PinMode){
            /**Enable Analog**/
            SET_BIT(M_GPIO_PORTE_BASE_ADDRESS->GPIOAMSEL_REG, Local_Copy_Pin_ID );
            /**Disable  Digital */
            CLEAR_BIT( M_GPIO_PORTE_BASE_ADDRESS->GPIODEN_REG , Local_Copy_Pin_ID);
            /**Disable Alternate Function**/
            CLEAR_BIT(M_GPIO_PORTE_BASE_ADDRESS->GPIOAFSEL_REG, Local_Copy_Pin_ID);
        }

        else if (Mode == UART_PinMode){
            /**Disable Analog**/
            CLEAR_BIT(M_GPIO_PORTE_BASE_ADDRESS->GPIOAMSEL_REG, Local_Copy_Pin_ID );
            /**Enable Digital */
            SET_BIT( M_GPIO_PORTE_BASE_ADDRESS->GPIODEN_REG , Local_Copy_Pin_ID);
            /**Disable Alternate Function**/
            SET_BIT(M_GPIO_PORTE_BASE_ADDRESS->GPIOAFSEL_REG, Local_Copy_Pin_ID);
            // Set the value for the alternate function
            M_GPIO_PORTE_BASE_ADDRESS->GPIOPCTL_REG |=( UART_PCTL_value_PortE << Local_Copy_Pin_ID);

        }

        else if (Mode == CAN_PinMode){
            /**Disable Analog**/
            CLEAR_BIT(M_GPIO_PORTE_BASE_ADDRESS->GPIOAMSEL_REG, Local_Copy_Pin_ID );
            /**Enable Digital */
            SET_BIT( M_GPIO_PORTE_BASE_ADDRESS->GPIODEN_REG , Local_Copy_Pin_ID);
            /**Disable Alternate Function**/
            SET_BIT(M_GPIO_PORTE_BASE_ADDRESS->GPIOAFSEL_REG, Local_Copy_Pin_ID);
            // Set the value for the alternate function
            M_GPIO_PORTE_BASE_ADDRESS->GPIOPCTL_REG |=(CAN_PCTL_value_PortE << Local_Copy_Pin_ID);
        }

        else {
            /*Do Nothing*/
        }
        break;

    case PORTF_ID :

        if (Mode==PORT_PinMode){
            /**Disable Analog**/
            CLEAR_BIT(M_GPIO_PORTF_BASE_ADDRESS->GPIOAMSEL_REG, Local_Copy_Pin_ID );
            /**Enable Digital */
            SET_BIT( M_GPIO_PORTF_BASE_ADDRESS->GPIODEN_REG , Local_Copy_Pin_ID);
            /**Disable Alternate Function**/
            CLEAR_BIT(M_GPIO_PORTF_BASE_ADDRESS->GPIOAFSEL_REG, Local_Copy_Pin_ID);

        }

        else if (Mode == Anlog_PinMode){
            /**Enable Analog**/
            SET_BIT(M_GPIO_PORTF_BASE_ADDRESS->GPIOAMSEL_REG, Local_Copy_Pin_ID );
            /**Disable  Digital */
            CLEAR_BIT( M_GPIO_PORTF_BASE_ADDRESS->GPIODEN_REG , Local_Copy_Pin_ID);
            /**Disable Alternate Function**/
            CLEAR_BIT(M_GPIO_PORTF_BASE_ADDRESS->GPIOAFSEL_REG, Local_Copy_Pin_ID);
        }

        else if (Mode == UART_PinMode){
            /**Disable Analog**/
            CLEAR_BIT(M_GPIO_PORTF_BASE_ADDRESS->GPIOAMSEL_REG, Local_Copy_Pin_ID );
            /**Enable Digital */
            SET_BIT( M_GPIO_PORTF_BASE_ADDRESS->GPIODEN_REG , Local_Copy_Pin_ID);
            /**Disable Alternate Function**/
            SET_BIT(M_GPIO_PORTF_BASE_ADDRESS->GPIOAFSEL_REG, Local_Copy_Pin_ID);
            // Set the value for the alternate function
            M_GPIO_PORTF_BASE_ADDRESS->GPIOPCTL_REG |=( UART_PCTL_value_PortF << Local_Copy_Pin_ID);

        }

        else if (Mode == CAN_PinMode){
            /**Disable Analog**/
            CLEAR_BIT(M_GPIO_PORTF_BASE_ADDRESS->GPIOAMSEL_REG, Local_Copy_Pin_ID );
            /**Enable Digital */
            SET_BIT( M_GPIO_PORTF_BASE_ADDRESS->GPIODEN_REG , Local_Copy_Pin_ID);
            /**Disable Alternate Function**/
            SET_BIT(M_GPIO_PORTF_BASE_ADDRESS->GPIOAFSEL_REG, Local_Copy_Pin_ID);
            // Set the value for the alternate function
            M_GPIO_PORTF_BASE_ADDRESS->GPIOPCTL_REG |=(CAN_PCTL_value_PortF << Local_Copy_Pin_ID);
        }

        else {
            /*Do Nothing*/
        }
        break;
    }
}
#endif

/************************************************************************************
 * Service Name: Port_RefreshPortDirection
 * Service ID[hex]: 0x02
 * Sync/Async: Synchronous
 * Re-entrancy: Non reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Refreshes port direction.
 ************************************************************************************/

void Port_RefreshPortDirection (void)  {


    //------------- Local Variables to get the port ID and pin Number
    uint8 Local_Copy_Port_ID;
    uint8 Local_Copy_Pin_ID;
    // For loop to loop inside the global array of Structures
    for (i = 0 ; i < PORT_CONFIGURED_PINS ; i ++ ){

        // Accessing the first element of struct (i) on the array
        Local_Copy_Port_ID = ((Port_PinConfig[i] . PIN_ID)/10);
        Local_Copy_Pin_ID =  ((Port_PinConfig[i] . PIN_ID)%10);

        switch (Local_Copy_Port_ID){

        case PORTA_ID:

            if (Port_PinConfig[i] . direction==PORT_PIN_IN){
                CLEAR_BIT(M_GPIO_PORTA_BASE_ADDRESS->GPIODIR_REG,Local_Copy_Pin_ID);
            }
            else if(Port_PinConfig[i] . direction==PORT_PIN_OUT){

                SET_BIT(M_GPIO_PORTA_BASE_ADDRESS->GPIODIR_REG,Local_Copy_Pin_ID);

            }
            else {
                /*Do Nothing*/
            }
        case PORTB_ID :

            if (Port_PinConfig[i] . direction==PORT_PIN_IN){
                CLEAR_BIT(M_GPIO_PORTA_BASE_ADDRESS->GPIODIR_REG,Local_Copy_Pin_ID);
            }
            else if(Port_PinConfig[i] . direction==PORT_PIN_OUT){

                SET_BIT(M_GPIO_PORTA_BASE_ADDRESS->GPIODIR_REG,Local_Copy_Pin_ID);

            }
            else {
                /*Do Nothing*/
            }

            break;

        case PORTC_ID:

            if (Port_PinConfig[i] . direction==PORT_PIN_IN){
                CLEAR_BIT(M_GPIO_PORTA_BASE_ADDRESS->GPIODIR_REG,Local_Copy_Pin_ID);
            }
            else if(Port_PinConfig[i] . direction==PORT_PIN_OUT){

                SET_BIT(M_GPIO_PORTA_BASE_ADDRESS->GPIODIR_REG,Local_Copy_Pin_ID);

            }
            else {
                /*Do Nothing*/
            }

            break;

        case PORTD_ID:

            if (Port_PinConfig[i] . direction==PORT_PIN_IN){
                CLEAR_BIT(M_GPIO_PORTA_BASE_ADDRESS->GPIODIR_REG,Local_Copy_Pin_ID);
            }
            else if(Port_PinConfig[i] . direction==PORT_PIN_OUT){

                SET_BIT(M_GPIO_PORTA_BASE_ADDRESS->GPIODIR_REG,Local_Copy_Pin_ID);

            }
            else {
                /*Do Nothing*/
            }

            break;

        case PORTE_ID:

            if (Port_PinConfig[i] . direction==PORT_PIN_IN){
                CLEAR_BIT(M_GPIO_PORTA_BASE_ADDRESS->GPIODIR_REG,Local_Copy_Pin_ID);
            }
            else if(Port_PinConfig[i] . direction==PORT_PIN_OUT){

                SET_BIT(M_GPIO_PORTA_BASE_ADDRESS->GPIODIR_REG,Local_Copy_Pin_ID);

            }
            else {
                /*Do Nothing*/
            }


            break;

        case PORTF_ID:

            if (Port_PinConfig[i] . direction==PORT_PIN_IN){
                CLEAR_BIT(M_GPIO_PORTA_BASE_ADDRESS->GPIODIR_REG,Local_Copy_Pin_ID);
            }
            else if(Port_PinConfig[i] . direction==PORT_PIN_OUT){

                SET_BIT(M_GPIO_PORTA_BASE_ADDRESS->GPIODIR_REG,Local_Copy_Pin_ID);

            }
            else {
                /*Do Nothing*/
            }

            break;

        }
    }
}

/************************************************************************************
 * Service Name: Port_GetVersionInfo
 * Service ID[hex]: 0x03
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): version-info - Pointer to where to store the version information of this module.
 * Return value: None
 * Description: Returns the version information of this module.
 ************************************************************************************/
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo ){

#if (PORT_DEV_ERROR_DETECT == STD_ON)
    /* check if the input configuration pointer is not a NULL_PTR */
    if(versioninfo == NULL_PTR)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_GET_VERSION_INFO_SID, PORT_E_PARAM_POINTER);
    }
    else
    {   /* Do Nothing */    }

    /* Check if the Driver is initialized before using this function */
    if(Port_Status == PORT_NOT_INITIALIZED)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_GET_VERSION_INFO_SID, PORT_E_UNINIT);
    }
    else
    {   /* Do Nothing */    }
#endif

    versioninfo->moduleID = (uint16)PORT_MODULE_ID;
    /* Copy the vendor Id */
    versioninfo->vendorID = (uint16)PORT_VENDOR_ID;
    /* Copy Software Major Version */
    versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
    /* Copy Software Minor Version */
    versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
    /* Copy Software Patch Version */
    versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
}


