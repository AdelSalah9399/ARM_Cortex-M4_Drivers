/*********************************************************************************************************************************
* AUTHOR           	  				VERSION									DATE 						DESCRIPTION 	   	 	 *
* Adel Salah El-Din	  				1.0.0 								3 June,2023					- Initial Creation			 *
**********************************************************************************************************************************/
/**********************************************************************************************************************************
* ! Title      	: EXTIx Driver                                                        						                      *
* ! File Name	: EXTIx_Driver.h                                                       							              	  *
* ! Description : This file has the RCC functions prototypes and Options Macros for function Arguments      	          		  *
* ! Compiler  	: GNU ARM cross Compiler                                            							                  *
* ! Target 	  	: STM32F401 (M-4) Micro-Controller                                         							              *
* ! Layer 	  	: MCAL -Driver Layer-                  						                            			  		      *
**********************************************************************************************************************************/
#ifndef EXTIX_EXTIX_DRIVER_H_
#define EXTIX_EXTIX_DRIVER_H_
/************************************************includes***************************************************************************/
#include "../../common/STD_TYPE.h"
#include "../../common/Util.h"
/************************************************EXTI-Lines Options*****************************************************************/
#define EXTI_Line_0										    0
#define EXTI_Line_1										    1
#define EXTI_Line_2										    2
#define EXTI_Line_3										    3
#define EXTI_Line_4										    4
#define EXTI_Line_5										    5
#define EXTI_Line_6										    6
#define EXTI_Line_7										    7
#define EXTI_Line_8										    8
#define EXTI_Line_9										    9
#define EXTI_Line_10										10
#define EXTI_Line_11										11
#define EXTI_Line_12										12
#define EXTI_Line_13										13
#define EXTI_Line_14										14
#define EXTI_Line_15										15
#define EXTI_Line_16_PVD									16
#define EXTI_Line_17_RTCalarm								17
#define EXTI_Line_18_OTG									18
#define EXTI_Line_21_RTCtamper								21
#define EXTI_Line_22_wakeup									22
/************************************************EXTI-Masking Options***************************************************************/
#define EXTI_M_Disable									    0
#define EXTI_M_Enable									    1
/************************************************EXTI-Modes Options*****************************************************************/
#define EXTI_Mode_RiaingEdge							    1
#define EXTI_Mode_FallingEdge							    2
#define EXTI_Mode_OnChangeEdge							    3
/************************************************EXTI-Ports Options*****************************************************************/
#define  EXTI_PortA							                0
#define  EXTI_PortB							                1
#define  EXTI_PortC							                2
#define  EXTI_PortD							                3
#define  EXTI_PortE							                3
#define  EXTI_PortH							                7

/***********************************************************************************************************************************/
/************************************************Functions Prototypes***************************************************************/
/***********************************************************************************************************************************/

/***************************************************************************
* Function Name		: EXTI_ret_tPortSelectionConfig
* Parameters (in)	: options from [EXTI_Line_x - EXTI_Portx]
* Parameters (out)	: NONE																						                      *
* Return value		: enum ret_t
* Description		: Function used to select each EXTI line port
* Constrains		: you must first ENABLE SYSCFG CLK by RCC
* *************************************************************************/
ret_t EXTI_ret_tPortSelectionConfig(u32 EXTI_Line,u32 EXTI_Port);

/***************************************************************************
* Function Name		: EXTI_ret_tInterruptLineModeEN_DIS
* Parameters (in)	: options from [EXTI_Line_x - EXTI_M_x]
* Parameters (out)	: NONE																						                      *
* Return value		: enum ret_t
* Description		: Function used to Enable/Disable EXTI INTERRUPT Mask
* Constrains		: NONE
* *************************************************************************/
ret_t EXTI_ret_tInterruptLineModeEN_DIS(u32 EXTI_Line, u32 EXTI_M);

/***************************************************************************
* Function Name		: EXTI_ret_tInterruptLineModeEN_DIS
* Parameters (in)	: options from [EXTI_Line_x - EXTI_M_x]
* Parameters (out)	: NONE																						                      *
* Return value		: enum ret_t
* Description		: Function used to Enable/Disable EXTI EVENT Mask
* Constrains		: NONE
* *************************************************************************/
ret_t EXTI_ret_tEventLineModeEN_DIS(u32 EXTI_Line, u32 EXTI_M);

/***************************************************************************
* Function Name		: EXTI_ret_tTrigerMode
* Parameters (in)	: options from [EXTI_Line_x - EXTI_Mode_x]
* Parameters (out)	: NONE																						                      *
* Return value		: enum ret_t
* Description		: Function used to select Trigger mode
* Constrains		: if you chose OnChange trigger ->[set Rising and Falling together]
* *************************************************************************/
ret_t EXTI_ret_tTrigerMode(u32 EXTI_Line, u32 EXTI_Mode);

/***************************************************************************
* Function Name		: EXTI_ret_tSW_InterruptEvent
* Parameters (in)	: options from [EXTI_Line_x]
* Parameters (out)	: NONE																						                      *
* Return value		: enum ret_t
* Description		: Function used to Generate EXTI SW Interrupt
* Constrains		: you must enable EXTI from NVIC
* *************************************************************************/
ret_t EXTI_ret_tSW_InterruptEvent(u32 EXTI_Line);

/***************************************************************************
* Function Name		: EXTI_ret_tClearPending
* Parameters (in)	: options from [EXTI_Line_x]
* Parameters (out)	: NONE																						                      *
* Return value		: enum ret_t
* Description		: Function used to clear the pending flag
* Constrains		: NONE
* *************************************************************************/
ret_t EXTI_ret_tClearPending(u32 EXTI_Line);

/***************************************************************************
* Function Name		: EXTIx_voidSetCallBack
* Parameters (in)	: options from [EXTI_Line_x - pointer to function]
* Parameters (out)	: pointer to function																						                      *
* Return value		: void
* Description		: CALL BACK FUNCTION
* Constrains		: NONE
* *************************************************************************/
void EXTIx_voidSetCallBack(u32 EXTI_Line,void(*ptr)(void));



#endif /* EXTIX_EXTIX_DRIVER_H_ */
