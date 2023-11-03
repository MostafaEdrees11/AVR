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
	LCD_enuInit();
	
	//LCD_enuDisplayChar('M');
	//LCD_enuDisplayChar('o');
	//LCD_enuDisplayChar('s');
	//LCD_enuDisplayChar('t');
	//LCD_enuDisplayChar('a');
	//LCD_enuDisplayChar('f');
	//LCD_enuDisplayChar('a');
	//LCD_enuDisplayChar('M');
	//LCD_enuDisplayChar('o');
	//LCD_enuDisplayChar('s');
	//LCD_enuDisplayChar('t');
	//LCD_enuDisplayChar('a');
	//LCD_enuDisplayChar('f');
	//LCD_enuDisplayChar('a');
	//LCD_enuDisplayChar('K');
	//LCD_enuDisplayChar('K');
	
	//LCD_enuWriteString("Hello ");
	//_delay_ms(500);
	//LCD_vidClearScreen();
	LCD_enuWriteString("Mostafa Edrees");
	LCD_enuDisplayChar('T');
	LCD_enuDisplayChar('T');
	LCD_enuDisplayChar('T');
	//_delay_ms(500);
	//LCD_enuDisplayChar('T');
	//_delay_ms(500);
	//LCD_enuDisplayChar('T');
	//_delay_ms(500);
	
    /* Replace with your application code */
    while (1) 
    {
    }
}

