/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mostafa Edrees
 * @brief          : Application file for EXTI
 * @date           : 13/12/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/

#include "LIB/Error_States.h"
#include "LIB/stdTypes.h"

#include "MCAL/DIO/DIO_config.h"
#include "MCAL/DIO/DIO_int.h"

#include "MCAL/EXTI/EXTI_config.h"
#include "MCAL/EXTI/EXTI_int.h"

#include "MCAL/GIE/GIE_int.h"

#include <util/delay.h>

extern EXTI_Configuration_t EXTI_AStrEXTI_Config[MAX_NUM_EXTI];

volatile void Toggle_Led(void *ptr);

int main(void)
{
	/* initialize the pins of led & button */
	DIO_enuSetPinDirection(DIO_u8PORTD, DIO_u8PIN2, DIO_u8INPUT);
	DIO_enuSetPinVal(DIO_u8PORTD, DIO_u8PIN2, DIO_u8PULL_UP);
	DIO_enuSetPinDirection(DIO_u8PORTB, DIO_u8PIN7, DIO_u8OUTPUT);
	
	/* initialize the seven segment */
	Seven_Segment_enuInit();
	
	/* initialize External interrupt */
	EXTI_enuInit(EXTI_AStrEXTI_Config);
	
	u8 x = 0;
	/* CallBack Function for EXTI0 */
	EXTI_enuCallBackFunc(&Toggle_Led, &x, 0);
	
	/* Enable INT0 */
	EXTI_enuEnable(EXTI0);
	
	/* enable global interrupt */
	GIE_enuGloable_Interrupt_Enable();
	
	DIO_enuSetPinVal(DIO_u8PORTB,DIO_u8PIN7, DIO_u8LOW);
	
    /* Replace with your application code */
    while (1) 
    {
    }
}

volatile void Toggle_Led(void *ptr)
{
	Seven_Segment_enuDisplayNumber(*((u8 *)ptr));
	if((*((u8 *)ptr) + 1) > 9)
	{
		*((u8 *)ptr) = 0;
	}
	else
	{
		*((u8 *)ptr) += 1;	
	}
	DIO_enuTogPinVal(DIO_u8PORTB,DIO_u8PIN7);
}

