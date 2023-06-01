/*
 * Util.h
 *
 *  Created on: May 22, 2023
 *      Author: Adel
 */

#ifndef UTIL_H_
#define UTIL_H_
/************************************************BIT-MASK*************************************************************************/
#define BIT0_MASK                                 0x00000001
#define BIT1_MASK                                 0x00000002
#define BIT2_MASK                                 0x00000004
#define BIT3_MASK                                 0x00000008
#define BIT4_MASK                                 0x00000010
#define BIT5_MASK                                 0x00000020
#define BIT6_MASK                                 0x00000040
#define BIT7_MASK                                 0x00000080
#define BIT8_MASK                                 0x00000100
#define BIT9_MASK                                 0x00000200
#define BIT10_MASK                                0x00000400
#define BIT11_MASK                                0x00000800
#define BIT12_MASK                                0x00001000
#define BIT13_MASK                                0x00002000
#define BIT14_MASK                                0x00004000
#define BIT15_MASK                                0x00008000
#define BIT16_MASK                                0x00010000
#define BIT17_MASK                                0x00020000
#define BIT18_MASK                                0x00040000
#define BIT19_MASK                                0x00080000
#define BIT20_MASK                                0x00100000
#define BIT21_MASK                                0x00200000
#define BIT22_MASK                                0x00400000
#define BIT23_MASK                                0x00800000
#define BIT24_MASK                                0x01000000
#define BIT25_MASK                                0x02000000
#define BIT26_MASK                                0x04000000
#define BIT27_MASK                                0x08000000
#define BIT28_MASK                                0x10000000
#define BIT29_MASK                                0x20000000
#define BIT30_MASK                                0x40000000
#define BIT31_MASK                                0x80000000
/************************************************Return Type*************************************************************************/
typedef enum{
	ret_OK,
	ret_Error
}ret_t;

#endif /* UTIL_H_ */
