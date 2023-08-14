/*********************************************************************************************************************************
* AUTHOR           	  				VERSION									DATE 						DESCRIPTION 	   	 	 *
* Adel Salah El-Din	  				1.0.0 								14 Jun,2023					- Initial Creation			 *
**********************************************************************************************************************************/
/**********************************************************************************************************************************
* ! Title      	: SYSTICK Driver                                                        						                  *
* ! File Name	: SYSTICK_APP.c                                                       							           	  	  *
* ! Description : This file has the SYSTICK functions Implementations 										     	          	  *
* ! Compiler  	: GNU ARM cross Compiler                                            							                  *
* ! Target 	  	: STM32F401 (M-4) Micro-Controller                                         							              *
* ! Layer 	  	: MCAL -Driver Layer-                  						                            			  		      *
**********************************************************************************************************************************/

#include "SYSTICK_Driver.h"

#define STK_BASE_ADDRESS   0xE000E010

#define EN_BIT				0
#define INT_EN_BIT			1
#define CLK_SRC_BIT			2

#define AHB_8_16mHZ_FACTOR	2000

#define STK 	((volatile STK_t*)STK_BASE_ADDRESS)

static void (*STK_CallBackptr)(void);

typedef struct {
	u32 CTRL;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;
}STK_t;



void STK_voidStart(void)
{
	STK->CTRL = ( STK_EN<<EN_BIT | INT_EN<<INT_EN_BIT | CLK_SRC_EN <<CLK_SRC_BIT );
}

void STK_voidStop(void)
{
	STK->CTRL &= ~( BIT0_MASK << EN_BIT );

}

void STK_voidPeriodMs(u32 PERIOD_Ms)
{
	if( PERIOD_Ms>0 && PERIOD_Ms<=0x00FFFFFF)
	{
		if(CLK_SRC_EN==AHB_DIV_8)
		{
		PERIOD_Ms*=AHB_8_16mHZ_FACTOR;
		}
		else{
			/*other calculation*/
		}
		STK->LOAD =PERIOD_Ms;
	}
}

//CALL BACK FUNC
void STK_voidSetCallBack(void (*ptr)(void))
{
	if(ptr!=NULL)
		STK_CallBackptr=ptr;
}

//ISR
void SysTick_Handler(void)
{
	if(STK_CallBackptr!=NULL)
	{
		STK_CallBackptr();
	}

}
