/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mostafa Edrees
 * @brief          : application file of Switch.
 * @date           : 10/13/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/
#define F_CPU	1000000

#include "stdTypes.h"
#include "Error_States.h"

#include "Switch_config.h"
#include "Switch_int.h"

#include "DIO_int.h"

extern SW_t SW_AstrSwitchConfig[SW_NUM];

int main(void)
{
	DIO_enuINIT();
	Switch_enuINIT(&SW_AstrSwitchConfig);
	
	DIO_enuSetPinDirection(DIO_u8PORTB, DIO_u8PIN0, DIO_u8OUTPUT);
	
	u8 Pin_State;
	
    /* Replace with your application code */
    while (1) 
    {
		Switch_enuGetState(&SW_AstrSwitchConfig[1], &Pin_State);
		if(Pin_State == 0)
		{
			DIO_enuSetPinVal(DIO_u8PORTB, DIO_u8PIN0, DIO_u8HIGH);
		}
		else if(Pin_State == 1)
		{
			DIO_enuSetPinVal(DIO_u8PORTB, DIO_u8PIN0, DIO_u8LOW);
		}
    }
}

