/*********************************************************************************************************************************
* AUTHOR           	  				VERSION									DATE 						DESCRIPTION 	   	 	 *
* Adel Salah El-Din	  				1.0.0 								13 June,2023					- Initial Creation		 *
**********************************************************************************************************************************/
/**********************************************************************************************************************************
* ! Title      	: LED Driver                                                        						                      *
* ! File Name	: LED_CFG.c                                                       							                	  *
* ! Description : This file has the CONFIG of LED Variables -fill by user-        							                  	  *
* ! Compiler  	: GNU ARM cross Compiler                                            							                  *
* ! Target 	  	: STM32F401 (M-4) Micro-Controller                                         							              *
* ! Layer 	  	: HAL -HardWare Layer-                  						                            			  		  *
**********************************************************************************************************************************/

/************************************************includes**************************************************************************/
#include "LED_Driver.h"
#include "../MCAL/GPIO/GPIO_Driver.h"
/***********************************************************************************************************************************/
/************************************************CONFIG Variables Definition********************************************************/
/***********************************************************************************************************************************/
const LedCFG_t ledcfg_arr[__led_length__]={

		//Insert Led Configuration below///////////////////////
		[led_alarm]={
			._Led_GPIO_Port=GPIO_PORTA,
			._Led_GPIO_Pin=GPIO_PIN0,
			._LedActiveState=ACTIVE_STATE_LOW,
			._LedName="led_alarm"
		},

		[led_ti_R]={
			._Led_GPIO_Port=GPIO_PORTA,
			._Led_GPIO_Pin=GPIO_PIN0,
			._LedActiveState=ACTIVE_STATE_HIGH,
			._LedName="led_ti_R"
		},

		[led_ti_L]={
			._Led_GPIO_Port=GPIO_PORTA,
			._Led_GPIO_Pin=GPIO_PIN0,
			._LedActiveState=ACTIVE_STATE_HIGH,
			._LedName="led_ti_L"

		},

		//...........


};
