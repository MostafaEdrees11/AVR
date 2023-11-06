/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mostafa Edrees
 * @brief          : application file of LCD.
 * @date           : 1/11/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/
#define F_CPU	1000000UL

#include "Error_States.h"
#include "stdTypes.h"

#include "DIO_config.h"
#include "DIO_int.h"

#include "LCD_config.h"
#include "LCD_int.h"

#include <util/delay.h>


int main(void)
{
	ES_t error = ES_NOK;
	error = LCD_enuInit();
	
	if(error == ES_OK)
	{
		LCD_enuWriteString("Mostafa Edrees");
		_delay_ms(3000);
		LCD_vidClearScreen();
		LCD_enuWriteString("CAT Reloaded");
		_delay_ms(3000);
		LCD_vidClearScreen();
	}
	
    /* Replace with your application code */
    while (1) 
    {
    }
}

