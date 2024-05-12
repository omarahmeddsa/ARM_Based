/******************************************************************************
 *
 * Module: PORT
 *
 * File Name: Port_Lcfg.c
 *
 * Description: Link Time config parameters  - Port Driver
 *
 * Author: Omar Ahmed
 ******************************************************************************/



/***********************************************
 * Port_Lcfg.c Includes                        *
 **********************************************/

#include "Port.h"
#include "Port_MemMap.h"
//------ Global Array of Structs
const Port_ConfigType Port_PinConfig[PORT_CONFIGURED_PINS] = {
                                                              //--------- Structure of Configuration of PIN
                                                              {PORT_F_PIN_0,PORT_PIN_IN,PULL_UP,PORT_PIN_LEVEL_LOW,PORT_PinMode,STD_ON,STD_ON},

                                                              {PORT_F_PIN_1,PORT_PIN_OUT,OFF,PORT_PIN_LEVEL_LOW,PORT_PinMode,STD_ON,STD_ON},

                                                              {PORT_F_PIN_2,PORT_PIN_OUT,OFF,PORT_PIN_LEVEL_LOW,PORT_PinMode,STD_ON,STD_ON},

                                                              {PORT_F_PIN_3,PORT_PIN_OUT,OFF,PORT_PIN_LEVEL_LOW,PORT_PinMode,STD_ON,STD_ON},

                                                              {PORT_F_PIN_4,PORT_PIN_IN,OFF,PORT_PIN_LEVEL_LOW,PORT_PinMode,STD_ON,STD_ON},


                                                              {PORT_A_PIN_0,PORT_PIN_IN,PULL_UP,PORT_PIN_LEVEL_LOW,PORT_PinMode,STD_ON,STD_ON},

                                                              {PORT_A_PIN_1,PORT_PIN_OUT,OFF,PORT_PIN_LEVEL_LOW,PORT_PinMode,STD_ON,STD_ON},

                                                              {PORT_A_PIN_2,PORT_PIN_OUT,OFF,PORT_PIN_LEVEL_LOW,PORT_PinMode,STD_ON,STD_ON},

                                                              {PORT_A_PIN_3,PORT_PIN_OUT,OFF,PORT_PIN_LEVEL_LOW,PORT_PinMode,STD_ON,STD_ON},

                                                              {PORT_A_PIN_4,PORT_PIN_IN,OFF,PORT_PIN_LEVEL_LOW,PORT_PinMode,STD_ON,STD_ON},

                                                              {PORT_A_PIN_5,PORT_PIN_IN,OFF,PORT_PIN_LEVEL_LOW,PORT_PinMode,STD_ON,STD_ON},

                                                              {PORT_A_PIN_6,PORT_PIN_IN,OFF,PORT_PIN_LEVEL_LOW,PORT_PinMode,STD_ON,STD_ON},

                                                              {PORT_A_PIN_7,PORT_PIN_IN,OFF,PORT_PIN_LEVEL_LOW,PORT_PinMode,STD_ON,STD_ON},


                                                              {PORT_B_PIN_0,PORT_PIN_IN,PULL_UP,PORT_PIN_LEVEL_LOW,PORT_PinMode,STD_ON,STD_ON},

                                                              {PORT_B_PIN_1,PORT_PIN_OUT,OFF,PORT_PIN_LEVEL_LOW,PORT_PinMode,STD_ON,STD_ON},

                                                              {PORT_B_PIN_2,PORT_PIN_OUT,OFF,PORT_PIN_LEVEL_LOW,PORT_PinMode,STD_ON,STD_ON},

                                                              {PORT_B_PIN_3,PORT_PIN_OUT,OFF,PORT_PIN_LEVEL_LOW,PORT_PinMode,STD_ON,STD_ON},

                                                              {PORT_B_PIN_4,PORT_PIN_IN,OFF,PORT_PIN_LEVEL_LOW,PORT_PinMode,STD_ON,STD_ON},

                                                              {PORT_B_PIN_5,PORT_PIN_IN,OFF,PORT_PIN_LEVEL_LOW,PORT_PinMode,STD_ON,STD_ON},

                                                              {PORT_B_PIN_6,PORT_PIN_IN,OFF,PORT_PIN_LEVEL_LOW,PORT_PinMode,STD_ON,STD_ON},

                                                              {PORT_B_PIN_7,PORT_PIN_IN,OFF,PORT_PIN_LEVEL_LOW,PORT_PinMode,STD_ON,STD_ON},




};
