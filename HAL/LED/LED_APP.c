/*********************************************************************************************************************************
* AUTHOR           	  				VERSION									DATE 						DESCRIPTION 	   	 	 *
* Adel Salah El-Din	  				1.0.0 								13 June,2023					- Initial Creation		 *
**********************************************************************************************************************************/
/**********************************************************************************************************************************
* ! Title      	: LED Driver                                                        						                      *
* ! File Name	: LED_APP.c                                                       							                	  *
* ! Description : This file has the implementation of LED functions        							                  		  	  *
* ! Compiler  	: GNU ARM cross Compiler                                            							                  *
* ! Target 	  	: STM32F401 (M-4) Micro-Controller                                         							              *
* ! Layer 	  	: HAL -HardWare Layer-                  						                            			  		  *
**********************************************************************************************************************************/

/************************************************includes*************************************************************************/
#include "LED_Driver.h"
#include "../MCAL/GPIO/GPIO_Driver.h"
/************************************************Global Variables*****************************************************************/
extern const LedCFG_t ledcfg_arr[__led_length__];
/***********************************************************************************************************************************/
/***********************************************interface functions implementation**************************************************/
/***********************************************************************************************************************************/
void LED_Init(void)
{	/*Create an object from GPIO_INFO(GPIO_PinCFG_t) for the LED*/
	GPIO_PinCFG_t Led;
	/*common setting for all LEDs  -MODE & PUPD-*/
	Led._Mode = GPIO_MODE_OUTPUT;
	Led._PUPD = GPIO_TYPE_PUSH_PULL;
	/*NON-common setting for LEDs  -PIN & PORT-*/
	u8 Local_index;
	for(Local_index=0;Local_index<__led_length__;Local_index++)
	{
		Led._Port=ledcfg_arr[Local_index]._Led_GPIO_Port;
		Led._Pin =ledcfg_arr[Local_index]._Led_GPIO_Pin;

	/*passing the final GPIO-CONFG object(Led) to the GPIO_Inint Function*/
		MGPIO_Init(&Led);
	}

}

extern void LED_SetLedState(u16 Led,u8 STATE_LED)
{
	GPIO_SetPinValue(ledcfg_arr[Led]._Led_GPIO_Port,ledcfg_arr[Led]._Led_GPIO_Pin,ledcfg_arr[Led]._LedActiveState ^ STATE_LED);
}

//LED ON  & Active High ---desired-> 1	     STATE_ON =1 ^ Active_High_MACRO=0 ----actual-> 1
//LED OFF & Active High ---desired-> 0       STATE_OFF=0 ^ Active_High_MACRO=0 ----actual-> 0
//LED ON  & Active LOW  ---desired-> 0       STATE_ON =1 ^ Active_LOW_MACRO =1 ----actual-> 0
//LED OFF & Active LOW  ---desired-> 1       STATE_OFF=0 ^ Active High_MACRO=1 ----actual-> 1


