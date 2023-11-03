 /**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mostafa Edrees
 * @brief          : application file of KEYPAD.
 * @date           : 3/11/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/

#define F_CPU 1000000UL

#include "Error_States.h"
#include "stdTypes.h"

#include "DIO_int.h"
#include "DIO_config.h"

#include "LCD_int.h"
#include "LCD_config.h"

#include "KEYPAD_int.h"
#include "KEYPAD_config.h"


int main(void)
{
	LCD_enuInit();
	KEYPAD_enuInit();
	
	u8 Local_u8KeyPressed;
	
    /* Replace with your application code */
    while (1) 
    {
		Local_u8KeyPressed = KEYPAD_u8GetPressedKey();
		switch(Local_u8KeyPressed)
		{
			case 'c':
			LCD_vidClearScreen();
			break;
			
			case KEYPAD_No_Key_Pressed:
			break;
			
			default:
			LCD_enuDisplayChar(Local_u8KeyPressed);
		};
    }
}

