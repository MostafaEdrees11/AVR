/*
 * Thermistor_LM35_Driver.c
 *
 * Created: 1/28/2024 2:22:34 PM
 * Author : Mostafa Edrees
 */ 

#include "LIB/Error_States.h"
#include "LIB/stdTypes.h"

#include "HAL/LCD/LCD_config.h"
#include "HAL/LCD/LCD_int.h"

#include "HAL/LM35/LM35_config.h"
#include "HAL/LM35/LM35_int.h"

#define F_CPU	1000000UL

#include <util/delay.h>

extern LM35_Configuration_t LM35_AstrLM35Config[LM35_NUM];

int main(void)
{
	LCD_enuInit();
	
	u16 x = 0;
	Thermistor_LM35_enuInit(LM35_AstrLM35Config);
	
    /* Replace with your application code */
    while (1) 
    {
		Thermistor_LM35_enuGetTempVal(0,&x);
		LCD_enuWriteNumber(x);
		_delay_ms(1000);
    }
}

