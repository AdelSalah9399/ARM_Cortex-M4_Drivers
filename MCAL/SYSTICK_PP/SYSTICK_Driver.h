/*********************************************************************************************************************************
* AUTHOR           	  				VERSION									DATE 						DESCRIPTION 	   	 	 *
* Adel Salah El-Din	  				1.0.0 								26 May,2023					- Initial Creation			 *
**********************************************************************************************************************************/
/**********************************************************************************************************************************
* ! Title      	: SYSTICK Driver                                                        						                  *
* ! File Name	: SYSTICK_Driver.h                                                       							              *
* ! Description : This file has the SYSTICK functions prototypes and Options Macros for function Arguments                   	  *
* ! Compiler  	: GNU ARM cross Compiler                                            							                  *
* ! Target 	  	: STM32F401 (M-4) Micro-Controller                                         							              *
* ! Layer 	  	: MCAL -Driver Layer-                  						                            			  		      *
**********************************************************************************************************************************/

#ifndef SYSTICK_PP_SYSTICK_DRIVER_H_
#define SYSTICK_PP_SYSTICK_DRIVER_H_
/************************************************includes***************************************************************************/
#include "../../common/STD_TYPE.h"
#include "../../common/Util.h"
/************************************************SYSTICK_CFG_OPTIONS***************************************************************************/
		/*STK_EN & INT_EN options*/
#define ENABLE			1
#define DISABLE			0
		/*CLK_SRC_EN options*/
#define AHB				1
#define AHB_DIV_8		0
/****************************************************************************************************************/
/*********************************************SYSTICK_CFG********************************************************/
/****************************************************************************************************************/
#define STK_EN			ENABLE
#define INT_EN			ENABLE
#define CLK_SRC_EN		AHB_DIV_8


/***********************************************************************************************************************************/
/************************************************Functions Prototypes***************************************************************/
/***********************************************************************************************************************************/


/***************************************************************************
* Function Name		: STK_voidStart
* Parameters (in)	: NONE
* Parameters (out)	: NONE
* Return value		: void
* Description		: Function used to Init and Start STK
* Constrains		: you must set cfg first
* *************************************************************************/
void STK_voidStart(void);

/***************************************************************************
* Function Name		: STK_voidStop
* Parameters (in)	: NONE
* Parameters (out)	: NONE
* Return value		: void
* Description		: Function used to Stop
* Constrains		: NONE
* *************************************************************************/
void STK_voidStop(void);

/***************************************************************************
* Function Name		: STK_voidPeriodMs
* Parameters (in)	: options [PERIOD_Ms] from 0 to 0x00FFFFFF
* Parameters (out)	: NONE
* Return value		: void
* Description		: Function used to generate HW INT
* Constrains		: NONE
* *************************************************************************/
void STK_voidPeriodMs(u32 PERIOD_Ms);


/***************************************************************************
* Function Name		: STK_voidSetCallBack
* Parameters (in)	: pointer to function
* Parameters (out)	: pointer to function																						                      *
* Return value		: void
* Description		: CALL BACK FUNCTION
* Constrains		: NONE
* *************************************************************************/
void STK_voidSetCallBack(void (*ptr)(void));


#endif /* SYSTICK_PP_SYSTICK_DRIVER_H_ */
