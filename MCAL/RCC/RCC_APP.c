/*********************************************************************************************************************************
* AUTHOR           	  				VERSION									DATE 						DESCRIPTION 	   	 	 *
* Adel Salah El-Din	  				1.0.0 								22 May,2023					- Initial Creation			 *
**********************************************************************************************************************************/
/**********************************************************************************************************************************
* ! Title      	: RCC Driver                                                        						                      *
* ! File Name	: RCC_APP.c                                                       							              	  	  *
* ! Description : This file has the RCC functions Implementations 										     	          		  *
* ! Compiler  	: GNU ARM cross Compiler                                            							                  *
* ! Target 	  	: STM32F401 (M-4) Micro-Controller                                         							              *
* ! Layer 	  	: MCAL -Driver Layer-                  						                            			  		      *
**********************************************************************************************************************************/

/************************************************includes************************************************************************/
#include "../../common/STD_TYPE.h"
#include "../../MCAL/RCC/RCC_Driver.h"
/************************************************Base Address********************************************************************/
#define RCC_BaseAddress								  0x40023800
/************************************************PLL-MASKING*********************************************************************/
#define PLLM_MASK									  0xFFFFFFC0
#define PLLN_MASK									  0xFFFF803F
#define PLLQ_MASK									  0xF0FFFFFF
#define PLLP_MASK									  0xFFFCFFFF
/************************************************ReadyFunc-Bits******************************************************************/
#define HSI_ReadyBit								  1
#define HSE_ReadyBit								  17
#define PLL_ReadyBit								  25
#define CLK_REDY									  1
#define CLK_NOT_REDY 								  0
/************************************************TimeOut_Macros******************************************************************/
#define REDY_TIMEOUT								  5000
/*******************************************************************************************************************************/
/************************************************Data Types*********************************************************************/
/*******************************************************************************************************************************/
typedef struct{
	 u32 CR;
	 u32 PLLCFGR;
	 u32 CFGR;
	 u32 CIR;
	 u32 AHB1RSTR;
	 u32 AHB2RSTR;
	 u32 Reserved_1;
	 u32 Reserved_2;
	 u32 APB1RSTR;
	 u32 APB2RSTR;
	 u32 Reserved_3;
	 u32 Reserved_4;
	 u32 AHB1ENR;
	 u32 AHB2ENR;
	 u32 Reserved_5;
	 u32 Reserved_6;
	 u32 APB1ENR;
	 u32 APB2ENR;
	 u32 Reserved_7;
	 u32 Reserved_8;
	 u32 AHB1LPENR;
	 u32 AHB2LPENR;
	 u32 Reserved_9;
	 u32 Reserved_10;
	 u32 APB1LPENR;
	 u32 APB2LPENR;
	 u32 Reserved_11;
	 u32 Reserved_12;
	 u32 BDCR;
	 u32 CSR;
	 u32 Reserved_13;
	 u32 Reserved_14;
	 u32 SSCGR;
	 u32 PLLI2SCFGR;
	 u32 Reserved_15;
	 u32 DCKCFGR;
}RCC_t;
/***********************************************************************************************************************************/
/************************************************variables**************************************************************************/
/***********************************************************************************************************************************/

static volatile RCC_t* const RCC_ptr = (volatile RCC_t* const ) RCC_BaseAddress;

/***********************************************************************************************************************************/
/************************************************static functions prototypes********************************************************/
/***********************************************************************************************************************************/







/***********************************************************************************************************************************/
/***********************************************interface functions implementation**************************************************/
/***********************************************************************************************************************************/
ret_t MRcc_ret_tEnableClk(u32 clk)
{	u32 res;
	if(clk==BIT0_MASK||clk==BIT16_MASK||clk==BIT24_MASK)
	{
		RCC_ptr->CR |= clk;
		u32 Local_TimeOut=0;
		switch (clk)
		{
		case clk_HSI:
			while(   ((res = (RCC_ptr->CR >>HSI_ReadyBit) & 0x1)==CLK_NOT_REDY )   && ( Local_TimeOut<=REDY_TIMEOUT )   )
			{
				Local_TimeOut++;
			}
			break;
		case clk_HSE:
			while(   ((res = (RCC_ptr->CR >>HSE_ReadyBit) & 0x1)==CLK_NOT_REDY )   && ( Local_TimeOut<=REDY_TIMEOUT )   )
			{
				Local_TimeOut++;
			}
			break;
		case clk_PLL:
			while(   ((res = (RCC_ptr->CR >>PLL_ReadyBit) & 0x1)==CLK_NOT_REDY )   && ( Local_TimeOut<=REDY_TIMEOUT )   )
			{
				Local_TimeOut++;
			}
			break;
		default: return ret_Error;
		}
		return ret_OK;
	}
	else
		return ret_Error;
}

ret_t MRcc_ret_tDisableClk(u32 clk)
{
	if(clk==BIT0_MASK||clk==BIT16_MASK||clk==BIT24_MASK)
	{
		RCC_ptr->CR &= ~clk;
		return ret_OK;
	}
	else
		return ret_Error;
}

/*
ret_t MRCC_ret_tClkReady(u32 clk)
{
	u32 res;
	switch (clk)
	{
	case clk_HSI: while((res = (RCC_ptr->CR >>HSI_ReadyBit) & 0x1)==0); break;
	case clk_HSE: while((res = (RCC_ptr->CR >>HSE_ReadyBit) & 0x1)==0); break;
	case clk_PLL: while((res = (RCC_ptr->CR >>PLL_ReadyBit) & 0x1)==0); break;
	default: return ret_Error;
	}
	return ret_OK;
}
*/

ret_t MRcc_ret_tSelectClk(u32 clk)
{
	switch(clk)
	{
		case clk_HSI: RCC_ptr->CFGR &= ~ BIT0_MASK; RCC_ptr->CFGR &= ~ BIT1_MASK; break;
		case clk_HSE: RCC_ptr->CFGR |=   BIT0_MASK; RCC_ptr->CFGR &= ~ BIT1_MASK; break;
		case clk_PLL: RCC_ptr->CFGR &= ~ BIT0_MASK; RCC_ptr->CFGR |=   BIT1_MASK; break;
		default: return ret_Error;
	}
	return ret_OK;
}

ret_t MRCC_ret_tEnablePeripheralClk(u32 peri,u32 peri_bus)
{
	if((peri % 2)==0 || peri==1)
	{
		switch(peri_bus)
		{
		case peri_busAHB1: RCC_ptr->AHB1ENR |=  peri; break;
		case peri_busAHB2: RCC_ptr->AHB2ENR |=  peri; break;
		case peri_busAPB1: RCC_ptr->APB1ENR |=  peri; break;
		case peri_busAPB2: RCC_ptr->APB2ENR |=  peri; break;
		default : return ret_Error;
		}
	}
	else
	{
		return ret_Error;
	}
	return ret_OK;
}

ret_t MRCC_ret_tDisablePeripheralClk(u32 peri,u32 peri_bus)
{
	if((peri % 2)==0 || peri==1)
	{
		switch(peri_bus)
		{
		case peri_busAHB1: RCC_ptr->AHB1LPENR &= ~ peri; break;
		case peri_busAHB2: RCC_ptr->AHB2LPENR &= ~ peri; break;
		case peri_busAPB1: RCC_ptr->APB1LPENR &= ~ peri; break;
		case peri_busAPB2: RCC_ptr->APB2LPENR &= ~ peri; break;
		default : return ret_Error;
		}
	}
	else
	{
		return ret_Error;
	}
	return ret_OK;
}

ret_t MRCC_ret_tConfigPLL(u32 PllSrc, u32 PllM, u32 PllN, u32 PllP )
{
	//mask the config bit
	u32 temp_P = RCC_ptr->PLLCFGR;
	temp_P &= ~BIT22_MASK;
	switch(PllSrc)
	{
	case PllSrc_HSE :temp_P |=  BIT22_MASK; RCC_ptr->PLLCFGR=temp_P; break;
	case PllSrc_HSI :temp_P &= ~BIT22_MASK; RCC_ptr->PLLCFGR=temp_P; break;
	default : return ret_Error;
	}
	if(PllM>=2 && PllM<=63)
	{
		u32 temp_M = RCC_ptr->PLLCFGR;
		temp_M &= PLLM_MASK;
		temp_M |= PllM;
		RCC_ptr->PLLCFGR =temp_M;
	}
	else
	{
		return ret_Error;
	}
	if(PllN>=192 && PllN<=432)
	{
		u32 temp_N = RCC_ptr->PLLCFGR;
		temp_N &= PLLN_MASK;
		temp_N |= (PllN<<6);
		RCC_ptr->PLLCFGR =temp_N;
	}
	else
	{
		return ret_Error;
	}
	if((PllP%2==0) && PllP<=8)
	{
		switch(PllP)
		{
			case 2:RCC_ptr->PLLCFGR &= ~BIT16_MASK; RCC_ptr->PLLCFGR &= ~BIT17_MASK; break;
			case 4:RCC_ptr->PLLCFGR |=  BIT16_MASK; RCC_ptr->PLLCFGR &= ~BIT17_MASK; break;
			case 6:RCC_ptr->PLLCFGR &= ~BIT16_MASK; RCC_ptr->PLLCFGR |=  BIT17_MASK; break;
			case 8:RCC_ptr->PLLCFGR |=  BIT16_MASK; RCC_ptr->PLLCFGR |=  BIT17_MASK; break;
		}
	}
	else
	{
		return ret_Error;
	}
	return ret_OK;
}
/***********************************************************************************************************************************/
/*************************************************static functions implementations**************************************************/
/***********************************************************************************************************************************/










