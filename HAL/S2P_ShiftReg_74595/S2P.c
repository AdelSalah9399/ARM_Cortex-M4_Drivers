/*
 * S2P.c
 *
 *  Created on: Aug 22, 2023
 *      Author: Adel
 */

#include "../../MCAL/GPIO/GPIO_Driver.h"
#include "../../MCAL/STK/STK_Driver.h"

#include "S2P.h"



void HS2P_SendByte(S2P_t * S2P_INFO,u8 User_Byte)
{
	u8 MSB;
	s8 i;
	for(i=7;i>=0;i--)
	{
		/*get the MSB*/
		MSB=(User_Byte>>i)&1;
		/*Send MSB*/
		MGPIO_SetPinValue(S2P_INFO->Ds_PORT,S2P_INFO->Data_Pin,MSB);

		/*Send Pulse to the Shift Register clk*/
		MGPIO_SetPinValue(S2P_INFO->SH_PORT,S2P_INFO->ShiftRegClk_Pin,VALUE_HIGH);
		MGPIO_SetPinValue(S2P_INFO->SH_PORT,S2P_INFO->ShiftRegClk_Pin,VALUE_LOW);
	}

	/*Send Pulse to the Shift Register clk*/
	MGPIO_SetPinValue(S2P_INFO->ST_PORT,S2P_INFO->StorageRegClk_Pin,VALUE_HIGH);
	MGPIO_SetPinValue(S2P_INFO->ST_PORT,S2P_INFO->StorageRegClk_Pin,VALUE_LOW);
}

