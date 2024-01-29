/**
 ******************************************************************************
 * @file           : ADC_Driver.c
 * @author         : Mostafa Edrees
 * @brief          : Application file of ADC.
 * @date           : 26/1/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/

#include "LIB/Error_States.h"
#include "LIB/stdTypes.h"

#include "HAL/LCD/LCD_config.h"
#include "HAL/LCD/LCD_int.h"

#include "MCAL/ADC/ADC_config.h"
#include "MCAL/ADC/ADC_int.h"

#include "MCAL/DIO/DIO_config.h"
#include "MCAL/DIO/DIO_int.h"

#include "MCAL/EXTI/EXTI_config.h"
#include "MCAL/EXTI/EXTI_int.h"

#include "MCAL/GIE/GIE_int.h"

#define F_CPU	1000000UL
#include <util/delay.h>

extern EXTI_Configuration_t EXTI_AStrEXTI_Config[MAX_NUM_EXTI];

volatile void Read(void *ptr);

int main(void)
{
	u16 ADC_Read = 0;
	
	DIO_enuSetPinDirection(DIO_u8PORTA, DIO_u8PIN0, DIO_u8INPUT);
	
	DIO_enuSetPinDirection(DIO_u8PORTD, DIO_u8PIN2, DIO_u8INPUT);
	DIO_enuSetPinVal(DIO_u8PORTD, DIO_u8PIN2, DIO_u8PULL_UP);
	
	EXTI_enuInit(EXTI_AStrEXTI_Config);
	EXTI_enuEnable(EXTI0);
	EXTI_enuChange_Control_State(EXTI0, FAILLING);
	
	
	ADC_enuInit();
	ADC_enuSelectChannel(ADC_CHANNEL_0);
	ADC_enuEnableTrigger(EXTI0_TRIG);
	ADC_enuEnableInterrupt();
	ADC_enuCallBack(&Read, &ADC_Read);
	ADC_enuEnable();
	ADC_enuStartConversion();
	
	LCD_enuInit();
	
	GIE_enuGloable_Interrupt_Enable();
	
	DIO_enuSetPortDirection(DIO_u8PORTC, 0xFF);
	
    /* Replace with your application code */
    while (1) 
    {
		/*ADC_enuStartConversion();
		ADC_enuReadADCValue(&ADC_Read);*/
		DIO_enuSetPortVal(DIO_u8PORTC, ADC_Read);
		/*LCD_enuWriteNumber((s32)ADC_Read);
		_delay_ms(3000);*/
    }
}

volatile void Read(void *ptr)
{
	ADC_enuReadADCValue(ptr);
	/*ADC_enuReadHighValue(ptr);*/
	LCD_enuWriteNumber(*((s32 *)ptr));
}