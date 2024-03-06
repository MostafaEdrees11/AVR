/*
 * Timer0.c
 *
 * Created: 1/29/2024 8:07:53 PM
 * Author : Mostafa Edrees
 */

#include "LIB/Error_States.h"
#include "LIB/stdTypes.h"

#include "HAL/LCD/LCD_config.h"
#include "HAL/LCD/LCD_int.h"

#include "MCAL/DIO/DIO_config.h"
#include "MCAL/DIO/DIO_int.h"

#include "MCAL/ADC/ADC_config.h"
#include "MCAL/ADC/ADC_int.h"

#include "MCAL/TIMER0/TIMER0_config.h"
#include "MCAL/TIMER0/TIMER0_int.h"

#include "MCAL/EXTI/EXTI_config.h"
#include "MCAL/EXTI/EXTI_int.h"

#include "MCAL/GIE/GIE_int.h"

#include "MCAL/interrupt.h"

#define F_CPU 1000000UL
#include <util/delay.h>

void Tog(void *p)
{
	DIO_enuTogPinVal(DIO_u8PORTA, DIO_u8PIN2);
}

int main(void)
{
	DIO_enuSetPinDirection(DIO_u8PORTA, DIO_u8PIN2, DIO_u8OUTPUT);
	DIO_enuSetPinVal(DIO_u8PORTA, DIO_u8PIN2, DIO_u8LOW);
	
	TIMER0_enuInit();
	
	/*TIMER0_enuDelayMilliSecondASyn(1000, Tog, NULL);*/
	/*TIMER0_enuEnableOVFInterrupt();*/
	/*TIMER0_enuSetOutputCompareRegister(0xAA);
	TIMER0_enuEnableCTCInterrupt();
	TIMER0_enuSetCALLBACK_CTC(Tog,NULL);*/
	
	/*GIE_enuGloable_Interrupt_Enable();*/
	
	/*TIMER0_enuGeneratePWM(70);*/
	
	
	while(1)
	{
		/*DIO_enuSetPinVal(DIO_u8PORTA, DIO_u8PIN2, DIO_u8HIGH);
		TIMER0_enuDelayMilliSecondSyn(1000);
		DIO_enuSetPinVal(DIO_u8PORTA, DIO_u8PIN2, DIO_u8LOW);
		TIMER0_enuDelayMilliSecondSyn(1000);*/
	}
	
	return 0;
}

