/*********************************************************************************************************************************
* AUTHOR           	  				VERSION									DATE 						DESCRIPTION 	   	 	 *
* Adel Salah El-Din	  				1.0.0 								22 May,2023					- Initial Creation			 *
**********************************************************************************************************************************/
/**********************************************************************************************************************************
* ! Title      	: RCC Driver                                                        						                      *
* ! File Name	: RCC_Driver.h                                                       							              	  *
* ! Description : This file has the RCC functions prototypes and Options Macros for function Arguments      	          		  *
* ! Compiler  	: GNU ARM cross Compiler                                            							                  *
* ! Target 	  	: STM32F401 (M-4) Micro-Controller                                         							              *
* ! Layer 	  	: MCAL -Driver Layer-                  						                            			  		      *
**********************************************************************************************************************************/
#ifndef RCC_RCC_DRIVER_H_
#define RCC_RCC_DRIVER_H_
/************************************************includes***************************************************************************/
#include "../../common/STD_TYPE.h"
#include "../../common/Util.h"
/************************************************Clock Sources**********************************************************************/
#define        clk_HSI 									    BIT0_MASK
#define        clk_HSE 									    BIT16_MASK
#define        clk_PLL 									    BIT24_MASK

#define        PllSrc_HSI 									0
#define        PllSrc_HSE 									1
/************************************************Peripheral Buses*******************************************************************/
#define        peri_busAHB1 								0
#define        peri_busAHB2 								1
#define        peri_busAPB1 								2
#define        peri_busAPB2 								3
/************************************************AHB1-Bus Peripherals***************************************************************/
#define        peri_AHB1_GPIOA 							    BIT0_MASK
#define        peri_AHB1_GPIOB 							    BIT1_MASK
#define        peri_AHB1_GPIOC 							    BIT2_MASK
#define        peri_AHB1_GPIOD 							    BIT3_MASK
#define        peri_AHB1_GPIOE 							    BIT4_MASK
#define        peri_AHB1_GPIOH 							    BIT7_MASK
#define        peri_AHB1_CRC   							    BIT12_MASK
#define        peri_AHB1_DMA1  							    BIT21_MASK
#define        peri_AHB1_DMA2  							    BIT22_MASK
/************************************************AHB2-Bus Peripherals***************************************************************/
#define        peri_AHB2_OTGFS   							BIT7_MASK
/************************************************APB1-Bus Peripherals***************************************************************/
#define        peri_APB1_TIM2    							BIT0_MASK
#define        peri_APB1_TIM3       						BIT1_MASK
#define        peri_APB1_TIM4       						BIT2_MASK
#define        peri_APB1_TIM5       						BIT3_MASK
#define        peri_APB1_WWDG       					 	BIT11_MASK
#define        peri_APB1_SPI2       					 	BIT14_MASK
#define        peri_APB1_SPI3       					 	BIT15_MASK
#define        peri_APB1_USART2     					 	BIT17_MASK
#define        peri_APB1_I2C1       					 	BIT21_MASK
#define        peri_APB1_I2C2       					 	BIT22_MASK
#define        peri_APB1_I2C3       					 	BIT23_MASK
#define        peri_APB1_PWR        					 	BIT28_MASK
/************************************************APB2-Bus Peripherals***************************************************************/
#define        peri_APB2_TIM1    							BIT0_MASK
#define        peri_APB2_USART1      						BIT4_MASK
#define        peri_APB2_USART6      						BIT5_MASK
#define        peri_APB2_ADC1        						BIT8_MASK
#define        peri_APB2_SDIO        						BIT11_MASK
#define        peri_APB2_SPI1        						BIT12_MASK
#define        peri_APB2_SPI4        						BIT13_MASK
#define        peri_APB2_SYSCFG      						BIT8_MASK
#define        peri_APB2_TIM9        						BIT16_MASK
#define        peri_APB2_TIM10       						BIT17_MASK
#define        peri_APB2_TIM11       						BIT18_MASK
/***********************************************************************************************************************************/
/************************************************Data Types*************************************************************************/
/***********************************************************************************************************************************/
enum PllP{
	PllP_2=2,
	PllP_4=4,
	PllP_6=6,
	PllP_8=8
};
/***********************************************************************************************************************************/
/************************************************Functions Prototypes***************************************************************/
/***********************************************************************************************************************************/


/***************************************************************************
* Function Name		: DriverRcc_EnableClk
* Parameters (in)	: options from [clk_x]
* Parameters (out)	: NONE																						                      *
* Return value		: enum ret_t
* Description		: Function used to Enable SysClk[HSI-HSE-PLL]
* Constrains		: NONE
* *************************************************************************/
ret_t DriverRcc_EnableClk(u32 clk);

/***************************************************************************
* Function Name		: DriverRcc_DisableClk
* Parameters (in)	: options from [clk_x]
* Parameters (out)	: NONE																						                      *
* Return value		: enum ret_t
* Description		: Function used to Disable SysClk[HSI-HSE-PLL]
* Constrains		: NONE
* *************************************************************************/
ret_t DriverRcc_DisableClk(u32 clk);

/***************************************************************************
* Function Name		: DriverRCC_ClkReady
* Parameters (in)	: options from [clk_x]
* Parameters (out)	: NONE																						                      *
* Return value		: enum ret_t
* Description		: Function used to check if the clock is ready or not
* Constrains		: NONE
* State 			: NEEDS MAINTENANCE
* 	^^WARRNING^^ this function WILL case a stuck condition due to busy wait
* 	---------------------------------------------------------------------------
* 	THIS FUNCTION CANT BE USE BECAUSE THIS FLAGE IS CLEARED AFTER 6 CLOCK CYCLES
* 	AND INTERING THE FUNCTION TAKE MORE THAN THAT TIME so MOVE ITS IMPLEMENTATION
* 	INSIDE ENABLE FUNCTION
* 	---------------------------------------------------------------------------
* *************************************************************************/
ret_t DriverRCC_ClkReady(u32 clk);

/***************************************************************************
* Function Name		: DriverRcc_SelectClk
* Parameters (in)	: options from [clk_x]
* Parameters (out)	: NONE																						                      *
* Return value		: enum ret_t
* Description		: Function used to Select SysClk[HSI-HSE-PLL]
* Constrains		: -SysClk must be Enable and Ready
* *************************************************************************/
ret_t DriverRcc_SelectClk(u32 clk);

/***************************************************************************
* Function Name		: DriverRCC_EnablePeripheralClk
* Parameters (in)	: options from [peri_x]
* Parameters (out)	: NONE																						                      *
* Return value		: enum ret_t
* Description		: Function used to Enable PeripheralClk
* Constrains		: NONE
* *************************************************************************/
ret_t DriverRCC_EnablePeripheralClk(u32 peri,u32 peri_bus);

/***************************************************************************
* Function Name		: DriverRCC_DisablePeripheralClk
* Parameters (in)	: options from [peri_x]
* Parameters (out)	: NONE																						                      *
* Return value		: enum ret_t
* Description		: Function used to Disable PeripheralClk
* Constrains		: NONE
* *************************************************************************/
ret_t DriverRCC_DisablePeripheralClk(u32 peri,u32 peri_bus);

/***************************************************************************
* Function Name		: DriverRCC_ConfigPLL
* Parameters (in)	:  options from [PllSrc_x, PllM_x, PllN_x, PllP_x, PllQ_x]
*		    		   PLLM Range -> PLLM_2 to PLLM_63
* 				 	   PLLN Range -> PLLN_192 to PLLN_432
* 					   PLLP Range -> PLLP_2,4,6,8
* Parameters (out)	: NONE																						                      *
* Return value		: enum ret_t
* Description		: Function used to Config the PLLClk
* Constrains		: -you must Switch to another SysClk(if PLL is the current SysClk)
* 			  		  -Disable the PLL
* 	^^WARRNING^^ USE suitable PRESCALLER to avoid >>> sleep mode <<< [2 & 4]
 * *************************************************************************/
ret_t DriverRCC_ConfigPLL(u32 PllSrc, u32 PllM, u32 PllN, u32 PllP );

#endif /* RCC_RCC_DRIVER_H_ */
