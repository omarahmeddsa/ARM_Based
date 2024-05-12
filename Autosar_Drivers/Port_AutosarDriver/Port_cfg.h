 /******************************************************************************
 * Module: PORT
 *
 * File Name: Port_Cfg.h
 *
 * Description: Configuration Header file for TM4C123GH6PM Micro-controller
 *
 * Author: Omar Ahmed
 ******************************************************************************/

#ifndef PORT_CFG_H_
#define PORT_CFG_H_
/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION              (1U)
#define PORT_CFG_SW_MINOR_VERSION              (0U)
#define PORT_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION     (3U)

/* Pre-compile option for Development Error Detect */
#define PORT_DEV_ERROR_DETECT               (STD_ON)

/* Pre-compile option for Version Info API */
#define PORT_VERSION_INFO_API               (STD_ON)

/* Pre-compile option for presence of Port_SetPinDirection API */
#define PORT_SET_PIN_DIRECTION_API          (STD_ON)

/* Pre-compile option for presence of Port_SetPinMode API */
#define PORT_SET_PIN_MODE_API               (STD_ON)

/* Number of PINS */
#define PORT_CONFIGURED_PINS                (40U)



/*******************************************Port Type and pin number********************************************/
#define PORT_A_PIN_0    0x00
#define PORT_A_PIN_1    0x01
#define PORT_A_PIN_2    0x02
#define PORT_A_PIN_3    0x03
#define PORT_A_PIN_4    0x04
#define PORT_A_PIN_5    0x05
#define PORT_A_PIN_6    0x06
#define PORT_A_PIN_7    0x07

#define PORT_B_PIN_0    0x10
#define PORT_B_PIN_1    0x11
#define PORT_B_PIN_2    0x12
#define PORT_B_PIN_3    0x13
#define PORT_B_PIN_4    0x14
#define PORT_B_PIN_5    0x15
#define PORT_B_PIN_6    0x16
#define PORT_B_PIN_7    0x17

#define PORT_C_PIN_0    0x20
#define PORT_C_PIN_1    0x21
#define PORT_C_PIN_2    0x22
#define PORT_C_PIN_3    0x23
#define PORT_C_PIN_4    0x24
#define PORT_C_PIN_5    0x25
#define PORT_C_PIN_6    0x26
#define PORT_C_PIN_7    0x27

#define PORT_D_PIN_0    0x30
#define PORT_D_PIN_1    0x31
#define PORT_D_PIN_2    0x32
#define PORT_D_PIN_3    0x33
#define PORT_D_PIN_4    0x34
#define PORT_D_PIN_5    0x35
#define PORT_D_PIN_6    0x36
#define PORT_D_PIN_7    0x37

#define PORT_E_PIN_0    0x40
#define PORT_E_PIN_1    0x41
#define PORT_E_PIN_2    0x42
#define PORT_E_PIN_3    0x43
#define PORT_E_PIN_4    0x44
#define PORT_E_PIN_5    0x45
#define PORT_E_PIN_6    0x46
#define PORT_E_PIN_7    0x47

#define PORT_F_PIN_0    0x50
#define PORT_F_PIN_1    0x51
#define PORT_F_PIN_2    0x52
#define PORT_F_PIN_3    0x53
#define PORT_F_PIN_4    0x54
#define PORT_F_PIN_5    0x45
#define PORT_F_PIN_6    0x56
#define PORT_F_PIN_7    0x57


#endif /* PORT_CFG_H_ */
