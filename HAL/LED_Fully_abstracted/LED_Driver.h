/*********************************************************************************************************************************
* AUTHOR           	  				VERSION									DATE 						DESCRIPTION 	   	 	 *
* Adel Salah El-Din	  				1.0.0 								13 June,2023					- Initial Creation		 *
**********************************************************************************************************************************/
/**********************************************************************************************************************************
* ! Title      	: LED Driver                                                        						                      *
* ! File Name	: LED_Driver.h                                                       							              	  *
* ! Description : This file has the LED functions prototypes and Options Macros for function Arguments                   		  *
* ! Compiler  	: GNU ARM cross Compiler                                            							                  *
* ! Target 	  	: STM32F401 (M-4) Micro-Controller                                         							              *
* ! Layer 	  	: HAL -HardWare Layer-                  						                            			  		  *
**********************************************************************************************************************************/
#ifndef LED_LED_DRIVER_H_
#define LED_LED_DRIVER_H_
/************************************************includes**************************************************************************/
#include "../../common/STD_TYPE.h"
#include "LED_CFG.h"
/************************************************ARGUMENTS MACROS*******************************************************************/
#define STATE_LED_ON	0
#define STATE_LED_OFF	1
/************************************************CONFIG MACROS*******************************************************************/
#define ACTIVE_STATE_HIGH	1
#define ACTIVE_STATE_LOW	0
/***********************************************************************************************************************************/
/************************************************INFO Variables*********************************************************************/
/***********************************************************************************************************************************/
typedef struct{
	//GPIO_CFG
	u32 	_Led_GPIO_Port;
	u32 	_Led_GPIO_Pin;
	//LED_CFG
	u32 	_LedActiveState;
	char* 	_LedName;

}LedCFG_t;

/***********************************************************************************************************************************/
/************************************************Functions Prototypes***************************************************************/
/***********************************************************************************************************************************/

/***************************************************************************
* Function Name		: LED_Init
* Parameters (in)	: NONE
* Parameters (out)	: NONE
* Return value		: NONE
* Description		: Function used to Init LED
* Constrains		: NONE
* *************************************************************************/
void LED_Init(void);

/***************************************************************************
* Function Name		: LED_SetLedState
* Parameters (in)	: options from [LedName - STATE_LED_X]
* Parameters (out)	: NONE
* Return value		: NONE
* Description		: Function used to Set LED ON/OFF
* Constrains		: NONE
* *************************************************************************/
extern void LED_SetLedState(u16 Led,u8 STATE_LED);

#endif /* LED_LED_DRIVER_H_ */
