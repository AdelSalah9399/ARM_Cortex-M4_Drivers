/*********************************************************************************************************************************
* AUTHOR           	  				VERSION									DATE 						DESCRIPTION 	   	 	 *
* Adel Salah El-Din	  				1.0.0 								3 June,2023					- Initial Creation			 *
**********************************************************************************************************************************/
/**********************************************************************************************************************************
* ! Title      	: EXTIx Driver                                                        						                      *
* ! File Name	: EXTIx_APP.c                                                       							              	  *
* ! Description : This file has the EXTIx functions Implementations 										     	          	  *
* ! Compiler  	: GNU ARM cross Compiler                                            							                  *
* ! Target 	  	: STM32F401 (M-4) Micro-Controller                                         							              *
* ! Layer 	  	: MCAL -Driver Layer-                  						                            			  		      *
**********************************************************************************************************************************/

/**************************************************** Library Inclusions *********************************************************/

/************************************************** Lower Layer Inclusions *******************************************************/

/************************************************** Self Layer Inclusions ********************************************************/

/************************************************** Self Files Inclusions ********************************************************/
#include "../../MCAL/EXTIx/EXTIx_Driver.h"
/************************************************** Global Variables **************************************************************/

static void (*EXTIx_CallBack[16])(void);
/************************************************** Base Addresses **************************************************************/
#define EXTI_BASE_ADDRESS		(0x40013C00)
#define SYSCFG_BASE_ADDRESS		(0x40013800)
/************************************************** SYSCFG MASK *****************************************************************/
#define SYSCFG_MASK				0x1111
/************************************************** Registers *******************************************************************/
#define  EXTI  	 ((volatile EXTI_t*)EXTI_BASE_ADDRESS)
#define  SYSCFG  ((volatile SYSCFG_t*)SYSCFG_BASE_ADDRESS)
/*******************************************************************************************************************************/
/************************************************Data Types*********************************************************************/
/*******************************************************************************************************************************/
typedef struct {
	u32 IMR;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;
}EXTI_t;

typedef struct{
	u32 MEMRMP;
	u32 PMC;
	u32 EXTICR[4];
	u32 CMPCR;
}SYSCFG_t;


/***********************************************************************************************************************************/
/************************************************static functions prototypes********************************************************/
/***********************************************************************************************************************************/







/***********************************************************************************************************************************/
/***********************************************interface functions implementation**************************************************/
/***********************************************************************************************************************************/
ret_t EXTI_ret_tPortSelectionConfig(u32 EXTI_Line,u32 EXTI_Port)
{
	if(EXTI_Line==19 || EXTI_Line==20 || EXTI_Port==5 || EXTI_Port==6)
	{
		return ret_Error;
	}
	else if(EXTI_Line>=0 && EXTI_Line<=22 && EXTI_Port>=0 && EXTI_Port<=7 )
	{
		u32 temp=SYSCFG->EXTICR[EXTI_Line/4];
		temp &= ~(SYSCFG_MASK<<(EXTI_Line % 4)*4);
		temp |=  (EXTI_Port  <<(EXTI_Line % 4)*4);
		SYSCFG->EXTICR[EXTI_Line/4]=temp;
		return ret_OK;
	}
	else
		return ret_Error;
}

ret_t EXTI_ret_tInterruptLineModeEN_DIS(u32 EXTI_Line, u32 EXTI_M)
{
	if(EXTI_Line==19 || EXTI_Line==20)
	{
		return ret_Error;
	}
	else if(EXTI_Line>=0 && EXTI_Line<=22 )
	{
		switch(EXTI_M)
		{
		case EXTI_M_Disable	: EXTI->IMR &= ~(1<<EXTI_Line); break;
		case EXTI_M_Enable	: EXTI->IMR |=  (1<<EXTI_Line); break;
		default				: return ret_Error; break;
		}
		return ret_OK;
	}
	else
		return ret_Error;
}

ret_t EXTI_ret_tEventLineModeEN_DIS(u32 EXTI_Line, u32 EXTI_M)
{
	if(EXTI_Line==19 || EXTI_Line==20)
	{
		return ret_Error;
	}
	else if(EXTI_Line>=0 && EXTI_Line<=22 )
	{
		switch(EXTI_M)
		{
		case EXTI_M_Disable	: EXTI->EMR &= ~(1<<EXTI_Line); break;
		case EXTI_M_Enable	: EXTI->EMR |=  (1<<EXTI_Line); break;
		default				: return ret_Error; break;
		}
		return ret_OK;
	}
	else
		return ret_Error;
}

ret_t EXTI_ret_tTrigerMode(u32 EXTI_Line, u32 EXTI_Mode)
{
	if(EXTI_Line==19 || EXTI_Line==20)
	{
		return ret_Error;
	}
	else if(EXTI_Line>=0 && EXTI_Line<=22 )
	{
		switch(EXTI_Mode)
		{
		case EXTI_Mode_RiaingEdge 	: EXTI->RTSR |=  (1<<EXTI_Line); EXTI->FTSR &= ~(1<<EXTI_Line); break;
		case EXTI_Mode_FallingEdge	: EXTI->RTSR &= ~(1<<EXTI_Line); EXTI->FTSR |=  (1<<EXTI_Line); break;
		case EXTI_Mode_OnChangeEdge : EXTI->RTSR |=  (1<<EXTI_Line); EXTI->FTSR |=  (1<<EXTI_Line); break;
		default						: return ret_Error;
		}
		return ret_OK;
	}
	else
		return ret_Error;
}

ret_t EXTI_ret_tSW_InterruptEvent(u32 EXTI_Line)
{
	if(EXTI_Line==19 || EXTI_Line==20)
	{
		return ret_Error;
	}
	else if(EXTI_Line>=0 && EXTI_Line<=22 )
	{
		EXTI->SWIER |=  (1<<EXTI_Line);
		return ret_OK;
	}
	else
		return ret_Error;
}

ret_t EXTI_ret_tClearPending(u32 EXTI_Line)
{
	if(EXTI_Line==19 || EXTI_Line==20)
	{
		return ret_Error;
	}
	else if(EXTI_Line>=0 && EXTI_Line<=22 )
	{
		EXTI->PR |=  (1<<EXTI_Line);
		return ret_OK;
	}
	else
		return ret_Error;
}
/**********************************************************************************************************************************/
/**************************************************CALL BACK FUNCTIONS*************************************************************/
/**********************************************************************************************************************************/

void EXTIx_voidSetCallBack(u32 EXTI_Line,void(*ptr)(void))
{
	if(ptr!=NULL)
	{
		switch(EXTI_Line)
		{
		case EXTI_Line_0           : EXTIx_CallBack[0]=ptr; break;
		case EXTI_Line_1           : EXTIx_CallBack[1]=ptr; break;
		case EXTI_Line_2           : EXTIx_CallBack[2]=ptr; break;
		case EXTI_Line_3           : EXTIx_CallBack[3]=ptr; break;
		case EXTI_Line_4           : EXTIx_CallBack[4]=ptr; break;
		case EXTI_Line_5           : EXTIx_CallBack[5]=ptr; break;
		case EXTI_Line_6           : EXTIx_CallBack[6]=ptr; break;
		case EXTI_Line_7           : EXTIx_CallBack[7]=ptr; break;
		case EXTI_Line_8           : EXTIx_CallBack[8]=ptr; break;
		case EXTI_Line_9           : EXTIx_CallBack[9]=ptr; break;
		case EXTI_Line_10          : EXTIx_CallBack[10]=ptr; break;
		case EXTI_Line_11          : EXTIx_CallBack[11]=ptr; break;
		case EXTI_Line_12          : EXTIx_CallBack[12]=ptr; break;
		case EXTI_Line_13          : EXTIx_CallBack[13]=ptr; break;
		case EXTI_Line_14          : EXTIx_CallBack[14]=ptr; break;
		case EXTI_Line_15          : EXTIx_CallBack[15]=ptr; break;
		case EXTI_Line_16_PVD      : EXTIx_CallBack[16]=ptr; break;
		case EXTI_Line_17_RTCalarm : EXTIx_CallBack[17]=ptr; break;
		case EXTI_Line_18_OTG	   : EXTIx_CallBack[18]=ptr; break;
		case EXTI_Line_21_RTCtamper: EXTIx_CallBack[21]=ptr; break;
		case EXTI_Line_22_wakeup   : EXTIx_CallBack[22]=ptr; break;
		default					   :/*ERROR*/				break;
		}
	}
	else
	{
		/*do nothing*/
	}
}
/**********************************************************************************************************************************/
/**************************************************IRQs Handlers*******************************************************************/
/**********************************************************************************************************************************/

void EXTI0_IRQHandler(void)
{
	if(EXTIx_CallBack[0]!=NULL)
	{
		EXTIx_CallBack[0]();
		EXTI_ret_tClearPending(EXTI_Line_0);
	}
	else
	{
		/*Do Nothing*/
	}
}

void EXTI1_IRQHandler(void)
{
	if(EXTIx_CallBack[1]!=NULL)
	{
		EXTIx_CallBack[1]();
		EXTI_ret_tClearPending(EXTI_Line_1);
	}
	else
	{
		/*Do Nothing*/
	}
}

void EXTI2_IRQHandler(void)
{
	if(EXTIx_CallBack[2]!=NULL)
	{
		EXTIx_CallBack[2]();
		EXTI_ret_tClearPending(EXTI_Line_2);
	}
	else
	{
		/*Do Nothing*/
	}
}

void EXTI3_IRQHandler(void)
{
	if(EXTIx_CallBack[3]!=NULL)
	{
		EXTIx_CallBack[3]();
		EXTI_ret_tClearPending(EXTI_Line_3);
	}
	else
	{
		/*Do Nothing*/
	}
}

void EXTI4_IRQHandler(void)
{
	if(EXTIx_CallBack[4]!=NULL)
	{
		EXTIx_CallBack[4]();
		EXTI_ret_tClearPending(EXTI_Line_4);
	}
	else
	{
		/*Do Nothing*/
	}
}


void EXTI9_5_IRQHandler(void)
{
	if(EXTIx_CallBack[5]!=NULL)
	{
		EXTIx_CallBack[5]();
		EXTI_ret_tClearPending(EXTI_Line_5);
	}
	if(EXTIx_CallBack[6]!=NULL)
	{
		EXTIx_CallBack[6]();
		EXTI_ret_tClearPending(EXTI_Line_6);
	}
	else if(EXTIx_CallBack[7]!=NULL)
	{
		EXTIx_CallBack[7]();
		EXTI_ret_tClearPending(EXTI_Line_7);
	}
	else if(EXTIx_CallBack[8]!=NULL)
	{
		EXTIx_CallBack[8]();
		EXTI_ret_tClearPending(EXTI_Line_7);
	}
	else if(EXTIx_CallBack[9]!=NULL)
	{
		EXTIx_CallBack[9]();
		EXTI_ret_tClearPending(EXTI_Line_7);
	}
	else
	{
		/*do nothing*/
	}

}
void EXTI15_10_IRQHandler(void)
{
	if(EXTIx_CallBack[10]!=NULL)
	{
		EXTIx_CallBack[10]();
		EXTI_ret_tClearPending(EXTI_Line_10);
	}
	else if(EXTIx_CallBack[11]!=NULL)
	{
		EXTIx_CallBack[11]();
		EXTI_ret_tClearPending(EXTI_Line_11);
	}
	else if(EXTIx_CallBack[12]!=NULL)
	{
		EXTIx_CallBack[12]();
		EXTI_ret_tClearPending(EXTI_Line_12);
	}
	else if(EXTIx_CallBack[13]!=NULL)
	{
		EXTIx_CallBack[13]();
		EXTI_ret_tClearPending(EXTI_Line_13);
	}
	else if(EXTIx_CallBack[14]!=NULL)
	{
		EXTIx_CallBack[14]();
		EXTI_ret_tClearPending(EXTI_Line_14);
	}
	else if(EXTIx_CallBack[15]!=NULL)
	{
		EXTIx_CallBack[15]();
		EXTI_ret_tClearPending(EXTI_Line_15);
	}
	else
	{
		/*do nothing*/
	}
}
/***********************************************************************************************************************************/
/*************************************************static functions implementations**************************************************/
/***********************************************************************************************************************************/



