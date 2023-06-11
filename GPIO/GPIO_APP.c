/*********************************************************************************************************************************
* AUTHOR           	  				VERSION									DATE 						DESCRIPTION 	   	 	 *
* Adel Salah El-Din	  				1.0.0 								26 May,2023					- Initial Creation			 *
**********************************************************************************************************************************/
/**********************************************************************************************************************************
* ! Title      	: GPIO Driver                                                        						                      *
* ! File Name	: GPIO_APP.c                                                       							                	  *
* ! Description : This file has the implementation of GPIO functions        							                  		  *
* ! Compiler  	: GNU ARM cross Compiler                                            							                  *
* ! Target 	  	: STM32F401 (M-4) Micro-Controller                                         							              *
* ! Layer 	  	: MCAL -Driver Layer-                  						                            			  		      *
**********************************************************************************************************************************/

/************************************************includes*************************************************************************/
#include "../../common/STD_TYPE.h"
#include "../../common/Util.h"
#include "../../MCAL/GPIO/GPIO_Driver.h"
/************************************************Base_Address*********************************************************************/
#define 		GPIOA_BASE_ADDRESS           (0x40020000)
#define 		GPIOB_BASE_ADDRESS           (0x40020400)
#define 		GPIOC_BASE_ADDRESS           (0x40020800)
/************************************************Register Masks*******************************************************************/
#define 		GPIO_MODE_MASK          	 3
#define 		GPIO_SPEED_MASK          	 3
#define 		GPIO_PUPD_MASK          	 3
#define 		GPIO_TYPE_MASK          	 1
#define 		GPIO_VALUE_MASK          	 1
#define 		GPIO_ALF_MASK          	 	 0xF
/************************************************Base Addresses*******************************************************************/
#define  	   	GPIOA      ((volatile GPIO_t*)GPIOA_BASE_ADDRESS)
#define    		GPIOB      ((volatile GPIO_t*)GPIOB_BASE_ADDRESS)
#define    		GPIOC      ((volatile GPIO_t*)GPIOC_BASE_ADDRESS)
/************************************************Base Addresses************************************************************************/
#define 		SET_ATOMIC					 1
#define 		RESET_ATOMIC_BSRR			 16
/*******************************************************************************************************************************/
/************************************************Data Types*********************************************************************/
/*******************************************************************************************************************************/
typedef struct{
	u32 MODER;
	u32 OTYPER;
	u32 OSPEEDER;
	u32 PUPDR;
	u32 IDR;
	u32 ODR;
	u32 BSRR;
	u32 LCKR;
	u32 AFRL;
	u32 AFRH;
}GPIO_t ;


/***********************************************************************************************************************************/
/************************************************static functions prototypes********************************************************/
/***********************************************************************************************************************************/







/***********************************************************************************************************************************/
/***********************************************interface functions implementation**************************************************/
/***********************************************************************************************************************************/

ret_t GPIO_SetPinMode(u8 GPIO_PORT,u8 GPIO_PIN, u8 GPIO_MODE)
{
	if( (GPIO_PIN>=GPIO_PIN0) && (GPIO_PIN<=GPIO_PIN15) && (GPIO_MODE>=GPIO_MODE_INPUT) && (GPIO_MODE<=GPIO_MODE_ANALOG) )
	{
		switch(GPIO_PORT)
		{
			case GPIO_PORTA: GPIOA->MODER &= ~(GPIO_MODE_MASK<<(GPIO_PIN*2));GPIOA->MODER |= (GPIO_MODE<<(GPIO_PIN*2)); break;
			case GPIO_PORTB: GPIOB->MODER &= ~(GPIO_MODE_MASK<<(GPIO_PIN*2));GPIOB->MODER |= (GPIO_MODE<<(GPIO_PIN*2)); break;
			case GPIO_PORTC: GPIOC->MODER &= ~(GPIO_MODE_MASK<<(GPIO_PIN*2));GPIOC->MODER |= (GPIO_MODE<<(GPIO_PIN*2)); break;
			default		   : return ret_Error;
		}
		return ret_OK;
	}
	else
		return ret_Error;
}


ret_t GPIO_SetPinType(u8 GPIO_PORT,u8 GPIO_PIN, u8 GPIO_TYPE)
{
	if( (GPIO_PIN>=GPIO_PIN0) && (GPIO_PIN<=GPIO_PIN15) && (GPIO_TYPE>=GPIO_TYPE_PUSH_PULL) && (GPIO_TYPE<=GPIO_TYPE_OPEN_DRAIN) )
	{
		switch(GPIO_PORT)
		{
			case GPIO_PORTA: GPIOA->OTYPER &= ~(GPIO_TYPE_MASK<<GPIO_PIN); GPIOA->OTYPER |= (GPIO_TYPE<<GPIO_PIN); break;
			case GPIO_PORTB: GPIOB->OTYPER &= ~(GPIO_TYPE_MASK<<GPIO_PIN); GPIOB->OTYPER |= (GPIO_TYPE<<GPIO_PIN); break;
			case GPIO_PORTC: GPIOC->OTYPER &= ~(GPIO_TYPE_MASK<<GPIO_PIN); GPIOC->OTYPER |= (GPIO_TYPE<<GPIO_PIN); break;
			default		   : return ret_Error;
		}
		return ret_OK;
	}
	else
		return ret_Error;
}

ret_t GPIO_SetPinSpeed(u8 GPIO_PORT,u8 GPIO_PIN, u8 GPIO_SPEED)
{
	if( (GPIO_PIN>=GPIO_PIN0) && (GPIO_PIN<=GPIO_PIN15) && (GPIO_SPEED>=GPIO_SPEED_LOW) && (GPIO_SPEED<=GPIO_SPEED_VERYHIGH) )
	{
		switch(GPIO_PORT)
		{
			case GPIO_PORTA: GPIOA->OSPEEDER &= ~(GPIO_SPEED_MASK<<(GPIO_PIN*2));GPIOA->OSPEEDER |= (GPIO_SPEED<<(GPIO_PIN*2)); break;
			case GPIO_PORTB: GPIOB->OSPEEDER &= ~(GPIO_SPEED_MASK<<(GPIO_PIN*2));GPIOB->OSPEEDER |= (GPIO_SPEED<<(GPIO_PIN*2)); break;
			case GPIO_PORTC: GPIOC->OSPEEDER &= ~(GPIO_SPEED_MASK<<(GPIO_PIN*2));GPIOC->OSPEEDER |= (GPIO_SPEED<<(GPIO_PIN*2)); break;
			default		   : return ret_Error;
		}
		return ret_OK;
	}
	else
		return ret_Error;
}

ret_t GPIO_SetPinValue(u8 GPIO_PORT,u8 GPIO_PIN, u8 GPIO_VALUE)
{
	if( (GPIO_PIN>=GPIO_PIN0) && (GPIO_PIN<=GPIO_PIN15) && (GPIO_VALUE>=GPIO_VALUE_LOW) && (GPIO_VALUE<=GPIO_VALUE_HIGH) )
	{
		switch(GPIO_PORT)
		{
			case GPIO_PORTA: GPIOA->ODR &= ~(GPIO_VALUE_MASK<<GPIO_PIN); GPIOA->ODR |= (GPIO_VALUE<<GPIO_PIN); break;
			case GPIO_PORTB: GPIOB->ODR &= ~(GPIO_VALUE_MASK<<GPIO_PIN); GPIOB->ODR |= (GPIO_VALUE<<GPIO_PIN); break;
			case GPIO_PORTC: GPIOC->ODR &= ~(GPIO_VALUE_MASK<<GPIO_PIN); GPIOC->ODR |= (GPIO_VALUE<<GPIO_PIN); break;
			default		   : return ret_Error;
		}
		return ret_OK;
	}
	else
		return ret_Error;
}


ret_t GPIO_GetPinValue(u8 GPIO_PORT,u8 GPIO_PIN, u8* GPIO_GetVALUE)
{
	if( (GPIO_PIN>=GPIO_PIN0) && (GPIO_PIN<=GPIO_PIN15) )
	{
		switch(GPIO_PORT)
		{
			case GPIO_PORTA: *GPIO_GetVALUE = (GPIOA->IDR >>GPIO_PIN) & 0X01; break;
			case GPIO_PORTB: *GPIO_GetVALUE = (GPIOB->IDR >>GPIO_PIN) & 0X01; break;
			case GPIO_PORTC: *GPIO_GetVALUE = (GPIOC->IDR >>GPIO_PIN) & 0X01; break;
			default		   : return ret_Error;
		}
		return ret_OK;
	}
	else
		return ret_Error;
}


ret_t GPIO_SetPinAtomicValue(u8 GPIO_PORT,u8 GPIO_PIN, u8 GPIO_VALUE)
{
	if( (GPIO_PIN>=GPIO_PIN0) && (GPIO_PIN<=GPIO_PIN15) )
	{
		if ((GPIO_VALUE==GPIO_VALUE_HIGH))
		{
			switch(GPIO_PORT)
			{
				case GPIO_PORTA: GPIOA->BSRR = (BIT0_MASK<<GPIO_PIN); break;
				case GPIO_PORTB: GPIOB->BSRR = (BIT0_MASK<<GPIO_PIN); break;
				case GPIO_PORTC: GPIOC->BSRR = (BIT0_MASK<<GPIO_PIN); break;
				default		   : return ret_Error;
			}
			return ret_OK;
		}
		else if ((GPIO_VALUE==GPIO_VALUE_LOW))
		{
			switch(GPIO_PORT)
			{
				case GPIO_PORTA: GPIOA->BSRR = (SET_ATOMIC<<GPIO_PIN<<RESET_ATOMIC_BSRR); break;
				case GPIO_PORTB: GPIOB->BSRR = (SET_ATOMIC<<GPIO_PIN<<RESET_ATOMIC_BSRR); break;
				case GPIO_PORTC: GPIOC->BSRR = (SET_ATOMIC<<GPIO_PIN<<RESET_ATOMIC_BSRR); break;
				default		   : return ret_Error;
			}
			return ret_OK;
		}
		else
			return ret_OK;
	}
	else
		return ret_Error;
}

ret_t GPIO_SetPullUpDownType(u8 GPIO_PORT,u8 GPIO_PIN, u8 GPIO_PUPD)
{
	if( (GPIO_PIN>=GPIO_PIN0) && (GPIO_PIN<=GPIO_PIN15) && (GPIO_PUPD>=GPIO_PUPD_NO_PUPD) && (GPIO_PUPD<=GPIO_PUPD_DOWN) )
	{
		u32 temp;
		switch(GPIO_PORT)
		{
			case GPIO_PORTA:temp= GPIOA->PUPDR; temp &= ~(GPIO_PUPD_MASK<<GPIO_PIN*2); temp |= (GPIO_PUPD<<GPIO_PIN*2); GPIOA->PUPDR =temp ; break;
			case GPIO_PORTB:temp= GPIOB->PUPDR; temp &= ~(GPIO_PUPD_MASK<<GPIO_PIN*2); temp |= (GPIO_PUPD<<GPIO_PIN*2); GPIOB->PUPDR =temp ; break;
			case GPIO_PORTC:temp= GPIOC->PUPDR; temp &= ~(GPIO_PUPD_MASK<<GPIO_PIN*2); temp |= (GPIO_PUPD<<GPIO_PIN*2); GPIOC->PUPDR =temp ; break;
			default		   : return ret_Error;
		}
		return ret_OK;
	}
	else
		return ret_Error;
}


ret_t GPIO_SetAlternativeFunction(u8 GPIO_PORT,u8 GPIO_PIN, u8 GPIO_AF)
{
	if( (GPIO_PIN>=GPIO_PIN0) && (GPIO_PIN<=GPIO_PIN7) && (GPIO_AF>=GPIO_AF0) && (GPIO_AF<=GPIO_AF15) )
	{
		u32 temp;
		switch(GPIO_PORT)
		{
			case GPIO_PORTA:temp= GPIOA->AFRL; temp &= ~(GPIO_ALF_MASK<<GPIO_PIN*4); temp |= (GPIO_AF<<GPIO_PIN*4); GPIOA->AFRL =temp ; break;
			case GPIO_PORTB:temp= GPIOB->AFRL; temp &= ~(GPIO_ALF_MASK<<GPIO_PIN*4); temp |= (GPIO_AF<<GPIO_PIN*4); GPIOB->AFRL =temp ; break;
			case GPIO_PORTC:temp= GPIOC->AFRL; temp &= ~(GPIO_ALF_MASK<<GPIO_PIN*4); temp |= (GPIO_AF<<GPIO_PIN*4); GPIOC->AFRL =temp ; break;
			default		   : return ret_Error;
		}
		return ret_OK;
	}
	else if( (GPIO_PIN>=GPIO_PIN8) && (GPIO_PIN<=GPIO_PIN15) && (GPIO_AF>=GPIO_AF0) && (GPIO_AF<=GPIO_AF15) )
	{
		u32 temp;
		switch(GPIO_PORT)
		{
			case GPIO_PORTA:temp= GPIOA->AFRH; temp &= ~(GPIO_ALF_MASK<<(GPIO_PIN-8)*4); temp |= (GPIO_AF<<(GPIO_PIN-8)*4); GPIOA->AFRH =temp ; break;
			case GPIO_PORTB:temp= GPIOB->AFRH; temp &= ~(GPIO_ALF_MASK<<(GPIO_PIN-8)*4); temp |= (GPIO_AF<<(GPIO_PIN-8)*4); GPIOB->AFRH =temp ; break;
			case GPIO_PORTC:temp= GPIOC->AFRH; temp &= ~(GPIO_ALF_MASK<<(GPIO_PIN-8)*4); temp |= (GPIO_AF<<(GPIO_PIN-8)*4); GPIOC->AFRH =temp ; break;
			default		   : return ret_Error;
		}
		return ret_OK;
	}
	else
		return ret_Error;
}

/***********************************************************************************************************************************/
/*************************************************static functions implementations**************************************************/
/***********************************************************************************************************************************/





