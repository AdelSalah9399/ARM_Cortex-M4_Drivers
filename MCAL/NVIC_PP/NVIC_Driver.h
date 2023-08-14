/*********************************************************************************************************************************
* AUTHOR           	  				VERSION									DATE 						DESCRIPTION 	   	 	 *
* Adel Salah El-Din	  				1.0.0 								26 May,2023					- Initial Creation			 *
**********************************************************************************************************************************/
/**********************************************************************************************************************************
* ! Title      	: NVIC Driver                                                        						                      *
* ! File Name	: NVIC_Driver.h                                                       							              	  *
* ! Description : This file has the NVIC functions prototypes and Options Macros for function Arguments                   		  *
* ! Compiler  	: GNU ARM cross Compiler                                            							                  *
* ! Target 	  	: STM32F401 (M-4) Micro-Controller                                         							              *
* ! Layer 	  	: MCAL -Driver Layer-                  						                            			  		      *
**********************************************************************************************************************************/

#ifndef NVIC_PP_NVIC_DRIVER_H_
#define NVIC_PP_NVIC_DRIVER_H_

/************************************************includes***************************************************************************/
#include "../../common/STD_TYPE.h"
#include "../../common/Util.h"
/************************************************SW_Priority_Groubs*****************************************************************/
											/*VECT_KRY+GROUB_OPTIN*/
#define Groups16_Sub0  								0X05FA0000
#define Groups8_Sub2   								0X05FA0400
#define Groups4_Sub4   								0X05FA0500
#define Groups2_Sub8  								0X05FA0600
#define Groups0_Sub16   							0X05FA0700		/*Disable Nesting*/
/*********************************************SW_PRIORITY CONFIG - PRE BUILD********************************************************/
#define	SW_PRIORITY    								Groups8_Sub2
/************************************************SW_Priority_SET********************************************************************/
//GROUBS
#define Group_0											0
#define Group_1											1
#define Group_2											2
#define Group_3											3
#define Group_4											4
#define Group_5											5
#define Group_6											6
#define Group_7											7
#define Group_8											8
#define Group_9										    9
#define Group_10									    10
#define Group_11									    11
#define Group_12									    12
#define Group_13									    13
#define Group_14									    14
#define Group_15									    15
#define Group_NONE										20
//SUB_GROUBS
#define SUB_Group_0									    0
#define SUB_Group_1									    1
#define SUB_Group_2									    2
#define SUB_Group_3									    3
#define SUB_Group_4									    4
#define SUB_Group_5									    5
#define SUB_Group_6									    6
#define SUB_Group_7									    7
#define SUB_Group_8									    8
#define SUB_Group_9										9
#define SUB_Group_10									10
#define SUB_Group_11									11
#define SUB_Group_12									12
#define SUB_Group_13									13
#define SUB_Group_14									14
#define SUB_Group_15									15
#define SUB_Group_NONE									20

/************************************************INT_ID*****************************************************************************/
#define NVIC_ID_WWDG									0
#define NVIC_ID_EXTI16_PVD								1
#define NVIC_ID_EXTI21_TAMP_STAMP						2
#define NVIC_ID_EXTI22_RTC_WKUP							3
#define NVIC_ID_FLASH							        4
#define NVIC_ID_RCC								        5
#define NVIC_ID_EXTI0							        6
#define NVIC_ID_EXTI1							        7
#define NVIC_ID_EXTI2							        8
#define NVIC_ID_EXTI3							        9
#define NVIC_ID_EXTI4							        10
#define NVIC_ID_DMA1_Stream0						    11
#define NVIC_ID_DMA1_Stream1						    12
#define NVIC_ID_DMA1_Stream2						    13
#define NVIC_ID_DMA1_Stream3						    14
#define NVIC_ID_DMA1_Stream4						    15
#define NVIC_ID_DMA1_Stream5						    16
#define NVIC_ID_DMA1_Stream6						    17
#define NVIC_ID_ADC								        18
#define NVIC_ID_EXTI9_5							        23
#define NVIC_ID_TIM1_BRK_TIM9					        24
#define NVIC_ID_TIM1_BRK_TIM10					        25
#define NVIC_ID_TIM1_TRG_COM_TIM11				       	26
#define NVIC_ID_TIM1_CC							        27
#define NVIC_ID_TIM2							        28
#define NVIC_ID_TIM3							        29
#define NVIC_ID_TIM4							        30
#define NVIC_ID_I2C1_EV							        31
#define NVIC_ID_I2C1_ER							        32
#define NVIC_ID_I2C2_EV							        33
#define NVIC_ID_I2C2_ER							        34
#define NVIC_ID_SPI1							        35
#define NVIC_ID_SPI2							        36
#define NVIC_ID_USART1							        37
#define NVIC_ID_USART2							        38
#define NVIC_ID_EXTI15_10						        40
#define NVIC_ID_TIM17_RTCAlaram					        41
#define NVIC_ID_TIM18_OTG_FS_WKUP				        42
#define NVIC_ID_DMA1_Stream7					       	47
#define NVIC_ID_SDIO							        49
#define NVIC_ID_TIM5							        50
#define NVIC_ID_SPI3							        51
#define NVIC_ID_DMA2_Stream0						    56
#define NVIC_ID_DMA2_Stream1						    57
#define NVIC_ID_DMA2_Stream2						    58
#define NVIC_ID_DMA2_Stream3						    59
#define NVIC_ID_DMA2_Stream4						    60
#define NVIC_ID_OTG_FS							        67
#define NVIC_ID_DMA2_Stream5						    68
#define NVIC_ID_DMA2_Stream6						    69
#define NVIC_ID_DMA2_Stream7						    70
#define NVIC_ID_USART6							        71
#define NVIC_ID_I2C3_EV							        72
#define NVIC_ID_I2C3_ER							        73
#define NVIC_ID_FPU								        81
#define NVIC_ID_SPI4							        84

/***********************************************************************************************************************************/
/************************************************Functions Prototypes***************************************************************/
/***********************************************************************************************************************************/


/***************************************************************************
* Function Name		: DriverNVIC_GroupsPriorityConfig
* Parameters (in)	: NONE
* Parameters (out)	: NONE																						                      *
* Return value		: void
* Description		: Function used to config the priority groubs
* Constrains		: --
* *************************************************************************/
void DriverNVIC_GroupsPriorityConfig(void);

/***************************************************************************
* Function Name		: DriverNVIC_EnableINT
* Parameters (in)	: options from [INT_ID_x]
* Parameters (out)	: NONE																						                      *
* Return value		: void
* Description		: Function used to Enable INT
* Constrains		: NONE
* *************************************************************************/
void DriverNVIC_EnableINT(u32 NVIC_ID);

/***************************************************************************
* Function Name		: DriverNVIC_DisableINT
* Parameters (in)	: options from [INT_ID_x]
* Parameters (out)	: NONE																						                      *
* Return value		: void
* Description		: Function used to Disable INT
* Constrains		: NONE
* *************************************************************************/
void DriverNVIC_DisableINT(u32 NVIC_ID);

/***************************************************************************
* Function Name		: DriverNVIC_SetPendingINT
* Parameters (in)	: options from [INT_ID_x]
* Parameters (out)	: NONE																						                      *
* Return value		: void
* Description		: Function used to set Pending INT flag
* Constrains		: NONE
* *************************************************************************/
void DriverNVIC_SetPendingINT(u32 NVIC_ID);

/***************************************************************************
* Function Name		: DriverNVIC_ClrPendingINT
* Parameters (in)	: options from [INT_ID_x]
* Parameters (out)	: NONE																						                      *
* Return value		: void
* Description		: Function used to Clear Pending INT flag
* Constrains		: NONE
* *************************************************************************/
void DriverNVIC_ClrPendingINT(u32 NVIC_ID);

/***************************************************************************
* Function Name		: DriverNVIC_GetActiveINT
* Parameters (in)	: options from [INT_ID_x]
* Parameters (out)	: NONE																						                      *
* Return value		: u32 [Active state]
* Description		: Function used to get the INT active state
* Constrains		: NONE
* *************************************************************************/
u32 DriverNVIC_GetActiveINT(u32 NVIC_ID);

/***************************************************************************
* Function Name		: DriverNVIC_SetINT_Proirity
* Parameters (in)	: options from [INT_ID_x  -  Group_x, Sub_Group_x]
* Parameters (out)	: NONE																						                      *
* Return value		: enum ret_t
* Description		: Function used to set the INT Priority
* Constrains		: You must check the SW_PRIORITY CONFIGRATION to chose
* 					  the correct valid values of groups & sub groups
* *************************************************************************/
ret_t DriverNVIC_SetINT_Proirity(u32 NVIC_ID, u32 Group,u32 Sub_Group);

/***************************************************************************
* Function Name		: DriverNVIC_GetINT_Proirity
* Parameters (in)	: options from [INT_ID_x]
* Parameters (out)	: NONE																						                      *
* Return value		: u8 [INT SW_priority]
* Description		: Function used to get INT priority 4 bits
* Constrains		: you must check the SCB_AIRCR Register configuration to
* 					  know the groups and sub groups selection .
* *************************************************************************/
u8 DriverNVIC_GetINT_Proirity(u32 NVIC_ID);

/***************************************************************************
* Function Name		: DriverNVIC_Generat_SW_INT
* Parameters (in)	: options from [INT_ID_x]
* Parameters (out)	: NONE																						                      *
* Return value		: void
* Description		: Function used to generate HW INT
* Constrains		: NONE
* *************************************************************************/
ret_t DriverNVIC_Generat_SW_INT(u32 NVIC_ID);




#endif /* NVIC_PP_NVIC_DRIVER_H_ */
