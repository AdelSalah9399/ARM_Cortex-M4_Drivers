/*********************************************************************************************************************************
* AUTHOR           	  				VERSION									DATE 						DESCRIPTION 	   	 	 *
* Adel Salah El-Din	  				1.0.0 								22 May,2023					- Initial Creation			 *
**********************************************************************************************************************************/
/**********************************************************************************************************************************
* ! Title      	: NVIC Driver                                                        						                      *
* ! File Name	: NVIC_APP.c                                                       							              	  	  *
* ! Description : This file has the NVIC functions Implementations 										     	          		  *
* ! Compiler  	: GNU ARM cross Compiler                                            							                  *
* ! Target 	  	: STM32F401 (M-4) Micro-Controller                                         							              *
* ! Layer 	  	: MCAL -Driver Layer-                  						                            			  		      *
**********************************************************************************************************************************/

/************************************************includes***************************************************************************/
#include "../../common/STD_TYPE.h"
#include "../NVIC_PP/NVIC_Driver.h"
/********************************************SW_Priority_BaseAddress****************************************************************/
#define NVIC_SCB_AIRCR_BaseAddress					  0xE000ED0C
/************************************************NVIC_Base_Address******************************************************************/
#define NVIC_BaseAddress   							  0xE000E100
/*****************************************************VECT_KEY**********************************************************************/
#define VECT_KEY 			 						  0X05FA0000

#define SCB_AIRCR  (*(volatile u32*) NVIC_SCB_AIRCR_BaseAddress)  //Groups and Sub groups Init
#define NVIC_AIRCR (*(volatile u32*) NVIC_BaseAddress)

/*******************************************************************************************************************************/
/************************************************Data Types*********************************************************************/
/*******************************************************************************************************************************/

typedef struct{
	u32 ISER[8];				           	/*   	ENABLE INT_ID               */
	u32 Reserved0[24];			           	/*		24x32bit-RESERVED			*/
	u32 ICER[8];				           	/*  	DISABLE INT_ID		        */
	u32 Reserved1[24];			           	/*		24x32bit-RESERVED			*/
	u32 ISPR[8];				           	/*		ENABLE PENDING INT_ID       */
	u32 Reserved2[24];			           	/*		24x32bit-RESERVED			*/
	u32 ICPR[8];				           	/*		DISABLE PENDING INT_ID      */
	u32 Reserved3[24];			           	/*		24x32bit-RESERVED			*/
	u32 IAPR[8];				           	/*		READ INT_ID ACTIVE STATE    */
	u32 Reserved4[56];			           	/*		56x32bit-RESERVED			*/
	u8  IPR[240];         		           	/*		SET INT_ID PRIORITY -Access 4 Bytes-*/
	u32 Reserved5[580];			           	/*		56x32bit-RESERVED			*/
	u8  STIR;								/*		GENERATE SW INT             */
}NVIC_t;

/***********************************************************************************************************************************/
/************************************************variables**************************************************************************/
/***********************************************************************************************************************************/

static volatile  NVIC_t * const NVIC_ptr = ((volatile NVIC_t * const) NVIC_BaseAddress);


/***********************************************************************************************************************************/
/************************************************static functions prototypes********************************************************/
/***********************************************************************************************************************************/







/***********************************************************************************************************************************/
/***********************************************interface functions implementation**************************************************/
/***********************************************************************************************************************************/

void DriverNVIC_GroupsPriorityConfig(void)
{
	/*config the grouping priority directly*/
	SCB_AIRCR=SW_PRIORITY;
}


void DriverNVIC_EnableINT(u32 INT_ID)
{
	/*  		get_array_index		get required bit	*/
	NVIC_ptr->ISER[INT_ID/32] = (1<< (INT_ID%32) );
}

void DriverNVIC_DisableINT(u32 INT_ID)
{
	/*  		get_array_index		get required bit	*/
	NVIC_ptr->ICER[INT_ID/32] = (1<< (INT_ID%32) );
}

void DriverNVIC_SetPendingINT(u32 INT_ID)
{
	/*  		get_array_index		get required bit	*/
	NVIC_ptr->ISPR[INT_ID/32] = (1<< (INT_ID%32) );
}

void DriverNVIC_ClrPendingINT(u32 INT_ID)
{
	/*  		get_array_index		get required bit	*/
	NVIC_ptr->ICPR[INT_ID/32] = (1<< (INT_ID%32) );
}

u32 DriverNVIC_GetActiveINT(u32 INT_ID)
{
	u32 Active_INT_ID;
	Active_INT_ID = ( NVIC_ptr->IAPR[INT_ID/32] >> (INT_ID%32) ) & 0x01;
	return Active_INT_ID;
}

ret_t DriverNVIC_SetINT_Proirity(u32 NVIC_ID, u32 Group,u32 Sub_Group)
{
#if SW_PRIORITY == Groups16_Sub0
	if(Group>=Group_0 && Group<=Group_15 && Sub_Group==SUB_Group_NONE)
	{
		u8 temp;
		temp = 0x00;
		temp = (Group<<4);
		NVIC_ptr->IPR[NVIC_ID/8] = temp;
		return ret_OK;
	}
	else
		return ret_Error;

#elif SW_PRIORITY == Groups8_Sub2
	if(Group>=Group_0 && Group<=Group_7 && Sub_Group>=SUB_Group_0 && Sub_Group<=SUB_Group_1)
	{
		u8 temp;
		temp = 0x00;
		temp = (Group<<5 | Sub_Group<<4);
		NVIC_ptr->IPR[NVIC_ID/8] = temp;
		return ret_OK;
	}
	else
		return ret_Error;

#elif SW_PRIORITY == Groups4_Sub4
	if(Group>=Group_0 && Group<=Group_3 && Sub_Group>=SUB_Group_0 && Sub_Group<=SUB_Group_3)
	{
		u8 temp;
		temp = 0x00;
		temp = (Group<<6 | Sub_Group<<4);
		NVIC_ptr->IPR[NVIC_ID/8] = temp;
		return ret_OK;
	}
	else
		return ret_Error;

#elif SW_PRIORITY == Groups2_Sub8
	if(Group>=Group_0 && Group<=Group_1 && Sub_Group>=SUB_Group_0 && Sub_Group<=SUB_Group_7)
	{
		u8 temp;
		temp = 0x00;
		temp = (Group<<7 | Sub_Group<<4);
		NVIC_ptr->IPR[NVIC_ID/8] = temp;
		return ret_OK;
	}
	else
		return ret_Error;

#elif SW_PRIORITY == Groups0_Sub16
	if( Sub_Group>=SUB_Group_0 && Sub_Group<=SUB_Group_15 && Group==Group_NONE)
	{
		NVIC_ptr->IPR[NVIC_ID/8] = Sub_Group<<4;
		return ret_OK;
	}
	else
		return ret_Error;


#endif
}

u8 DriverNVIC_GetINT_Proirity(u32 NVIC_ID)
{
	u8 Prio_res;
	Prio_res = (NVIC_ptr->IPR[NVIC_ID/8] >> 4) & 0x0F ;
	return Prio_res;
}

ret_t DriverNVIC_Generat_SW_INT(u32 NVIC_ID)
{
	if(NVIC_ID>=0 && NVIC_ID<=239)
	{
		u32 temp;
		temp=0x0;
		temp |= NVIC_ID;
		NVIC_ptr->STIR = temp;

		return ret_OK;
	}
	else
		return ret_Error;
}

