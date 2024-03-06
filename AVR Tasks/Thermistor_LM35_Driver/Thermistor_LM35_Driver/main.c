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
	LCD_enuSendCommand(LCD_DisplayOn_CursorOff_NoBlinking);
	
	u16 Local_u16CurrentTempVal = 0;
	u16 Local_u16PreviousTempVal = 0;
	
	Thermistor_LM35_enuInit(LM35_AstrLM35Config);
	
	LCD_enuWriteString("Temperature: ");
	
    /* Replace with your application code */
    while (1) 
    {
		if(Local_u16PreviousTempVal == Local_u16CurrentTempVal)
		{
			Thermistor_LM35_enuGetTempVal(0,&Local_u16CurrentTempVal);
		}
		else
		{
			LCD_enuGoToPosition(0,13);
			LCD_enuWriteString("   ");
			LCD_enuGoToPosition(0,13);
			LCD_enuWriteIntNumber(Local_u16CurrentTempVal);
			_delay_ms(500);
			Local_u16PreviousTempVal = Local_u16CurrentTempVal;
		}
    }
}

