/*
 * S2P.h
 *
 *  Created on: Aug 22, 2023
 *      Author: Adel
 */

#ifndef S2P_SHIFTREG_74595_S2P_H_
#define S2P_SHIFTREG_74595_S2P_H_


#include "../../Common/STD_TYPE.h"
#include "../../Common/BIT_MATH.h"


typedef struct{
//PINS-> PORTS SELECTION
	u8 Ds_PORT;
	u8 SH_PORT;
	u8 ST_PORT;
//PINS-> NUMBER SELECTION
	u8 Data_Pin;
	u8 ShiftRegClk_Pin;
	u8 StorageRegClk_Pin;
}S2P_t;



void HS2P_SendByte(S2P_t * S2P_INFO,u8 User_Byte);



#endif /* S2P_SHIFTREG_74595_S2P_H_ */
