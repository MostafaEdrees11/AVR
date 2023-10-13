/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mostafa Edrees
 * @brief          : application file of DIO.
 * @date           : 10/6/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/
#define F_CPU	1000000

#include "stdTypes.h"

#include "DIO_int.h"

#include <util/delay.h>

int main(void)
{
	//u8 SegCth[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F}
	s8 i, j;
	s8 Pins[] = {DIO_u8PIN0, DIO_u8PIN1, DIO_u8PIN2, DIO_u8PIN3, DIO_u8PIN4, DIO_u8PIN5, DIO_u8PIN6, DIO_u8PIN7};
		
	DIO_enuINIT();
	
    /* Replace with your application code */
    while (1) 
    {
		for(i = 0; i < 8; i++)
		{
			DIO_enuSetPinVal(DIO_u8PORTC, Pins[i], DIO_u8HIGH);
			_delay_ms(500);
		}
		for(j = 7; j >= 0; j--)
		{
			DIO_enuSetPinVal(DIO_u8PORTC, Pins[j], DIO_u8LOW);
			_delay_ms(500);
		}
    }
}

