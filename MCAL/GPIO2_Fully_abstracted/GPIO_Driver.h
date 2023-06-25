/*********************************************************************************************************************************
* AUTHOR           	  				VERSION									DATE 						DESCRIPTION 	   	 	 *
* Adel Salah El-Din	  				1.0.0 								13 June,2023					- Initial Creation		 *
**********************************************************************************************************************************/
/**********************************************************************************************************************************
* ! Title      	: GPIO Driver                                                        						                      *
* ! File Name	: GPIO_Driver.h                                                       							              	  *
* ! Description : This file has the GPIO functions prototypes and Options Macros for function Arguments                   		  *
* ! Compiler  	: GNU ARM cross Compiler                                            							                  *
* ! Target 	  	: STM32F401 (M-4) Micro-Controller                                         							              *
* ! Layer 	  	: MCAL -Driver Layer-                  						                            			  		      *
**********************************************************************************************************************************/

#ifndef GPIO_GPIO_DRIVER_H_
#define GPIO_GPIO_DRIVER_H_
/************************************************includes**************************************************************************/
#include "../../common/STD_TYPE.h"
#include "../../common/Util.h"
/************************************************GPIOx_PORTS***********************************************************************/
#define 		GPIO_PORTA 					 0
#define 		GPIO_PORTB 					 1
#define 		GPIO_PORTC 					 2
/************************************************GPIOx_PINS************************************************************************/
#define 		GPIO_PIN0 					 0
#define 		GPIO_PIN1 					 1
#define 		GPIO_PIN2 					 2
#define 		GPIO_PIN3 					 3
#define 		GPIO_PIN4 					 4
#define 		GPIO_PIN5 					 5
#define 		GPIO_PIN6 					 6
#define 		GPIO_PIN7 					 7
#define 		GPIO_PIN8 					 8
#define 		GPIO_PIN9 					 9
#define 		GPIO_PIN10 					 10
#define 		GPIO_PIN11 					 11
#define 		GPIO_PIN12 					 12
#define 		GPIO_PIN13 					 13
#define 		GPIO_PIN14 					 14
#define 		GPIO_PIN15 					 15
/************************************************GPIOx_MODES************************************************************************/
#define 		GPIO_MODE_INPUT				 0
#define 		GPIO_MODE_OUTPUT			 1
#define 		GPIO_MODE_ALF			 	 2
#define 		GPIO_MODE_ANALOG			 3
/************************************************GPIOx_TYPE************************************************************************/
#define 		GPIO_TYPE_PUSH_PULL		  	 0
#define 		GPIO_TYPE_OPEN_DRAIN		 1
/************************************************GPIOx_SPEED************************************************************************/
#define 		GPIO_SPEED_LOW		  	 	 0
#define 		GPIO_SPEED_MEDIUM		   	 1
#define 		GPIO_SPEED_HIGH		  	 	 2
#define 		GPIO_SPEED_VERYHIGH		   	 3
/************************************************GPIOx_VALUE************************************************************************/
#define 		GPIO_VALUE_LOW		  	 	 0
#define 		GPIO_VALUE_HIGH		   		 1
/************************************************GPIOx_PULL UP/DOWN******************************************************************/
#define 		GPIO_PUPD_NO_PUPD		  	 0
#define 		GPIO_PUPD_UP		  	 	 1
#define 		GPIO_PUPD_DOWN		   		 2
/************************************************Alternative Function******************************************************************/
#define 	    GPIO_AF0					 0
#define 	    GPIO_AF1					 1
#define 	    GPIO_AF2					 2
#define 	    GPIO_AF3					 3
#define 	    GPIO_AF4					 4
#define 	    GPIO_AF5					 5
#define 	    GPIO_AF6					 6
#define 	    GPIO_AF7					 7
#define 	    GPIO_AF8					 8
#define 	    GPIO_AF9					 9
#define 	    GPIO_AF10					 10
#define 	    GPIO_AF11					 11
#define 	    GPIO_AF12					 12
#define 	    GPIO_AF13					 13
#define 	    GPIO_AF14					 14
#define 	    GPIO_AF15					 15

/***********************************************************************************************************************************/
/************************************************INFO Variables*********************************************************************/
/***********************************************************************************************************************************/
typedef struct{
	u8 _Port;
	u8 _Pin;
	u8 _Mode;
	u8 _Type;
	u8 _PUPD;
	u8 _Speed;
	u8 _AF;
}GPIO_PinCFG_t;

/***********************************************************************************************************************************/
/************************************************Functions Prototypes***************************************************************/
/***********************************************************************************************************************************/

/***************************************************************************
* Function Name		: MGPIO_Init
* Parameters (in)	: address of struct GPIO_PinCFG_t
* Parameters (out)	: NONE																						                      *
* Return value		: void
* Description		: Function used to Init GPIO Pin
* Constrains		: NONE
* *************************************************************************/
void MGPIO_Init(GPIO_PinCFG_t * PinCFG);

/***************************************************************************
* Function Name		: GPIO_SetPinValue
* Parameters (in)	: options from struct GPIO_PinCFG_t element [x._port - x._port] and value [ GPIO_Value_X]
* Parameters (out)	: NONE																						                      *
* Return value		: enum ret_t
* Description		: Function used to Set GPIO pin Type [Low/High]
* Constrains		: NONE
* *************************************************************************/
ret_t GPIO_SetPinValue(u8 GPIO_PORT,u8 GPIO_PIN, u8 GPIO_VALUE);

/***************************************************************************
* Function Name		: GPIO_GetPinValue
* Parameters (in)	: options from struct GPIO_PinCFG_t element [x._port - x._port] and value [ GPIO_Value_X]
* Parameters (out)	: result value of GPIO PIN state																						                      *
* Return value		: enum ret_t
* Description		: Function used to Get GPIO pin Value [Low/High]
* Constrains		: NONE
* *************************************************************************/
ret_t GPIO_GetPinValue(u8 GPIO_PORT,u8 GPIO_PIN, u8* GPIO_GetVALUE);

/***************************************************************************
* Function Name		: GPIO_SetPinAtomicValue
* Parameters (in)	: options from struct GPIO_PinCFG_t element [x._port - x._port] and value [ GPIO_Value_X]
* Parameters (out)	: NONE																						                      *
* Return value		: enum ret_t
* Description		: Function used to Set GPIO pin Type [Low/High] in one instruction
* Constrains		: NONE
* *************************************************************************/
ret_t GPIO_SetPinAtomicValue(u8 GPIO_PORT,u8 GPIO_PIN, u8 GPIO_VALUE);


#endif /* GPIO_GPIO_DRIVER_H_ */
