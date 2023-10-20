/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mostafa Edrees
 * @brief          : application file of Seven Segment.
 * @date           : 10/20/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/
#define F_CPU 1000000UL

#include "stdTypes.h"
#include "Error_States.h"

#include "DIO_int.h"
#include "Seven_Segment_int.h"

#include <util/delay.h>


int main(void)
{
	ES_t error;
	
	error = Seven_Segment_enuInit();
	
    /* Replace with your application code */
    while (1) 
    {
		if(error == ES_OK)
		{
			for(u8 i = 0; i < 10; i++)
			{
				Seven_Segment_enuDisplayNumber(i);
				_delay_ms(500);
			}	
		}
    }
}

