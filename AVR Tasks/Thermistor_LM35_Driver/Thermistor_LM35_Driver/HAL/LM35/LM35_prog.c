/*
 * LM35_prog.c
 *
 * Created: 1/28/2024 2:25:42 PM
 *  Author: Mostafa Edrees
 */

#include "../../LIB/Error_States.h"
#include "../../LIB/stdTypes.h"

#include "../../MCAL/ADC/ADC_config.h"
#include "../../MCAL/ADC/ADC_int.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "../../MCAL/GIE/GIE_int.h"

#include "LM35_config.h"
#include "LM35_priv.h"

static volatile u16 LM35_u16ADCValue = 0;
static volatile f32 LM35_f32Tempeture = 0;

void LM35_inlvidReadADCValue(void *Copy_PvidLM35VoltValue)
{
	ADC_enuReadADCValue(Copy_PvidLM35VoltValue);
	
	LM35_f32Tempeture = ((LM35_u16ADCValue * ADC_VOLT_REF / ADC_RESOLUTION) / LM35_DEG_STEP);
}

ES_t Thermistor_LM35_enuInit(LM35_Configuration_t *Copy_PstrLM35Config)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	ADC_enuInit();
	
	ADC_enuEnableInterrupt();
	ADC_enuCallBack(&LM35_inlvidReadADCValue, &LM35_u16ADCValue);
	
	GIE_enuGloable_Interrupt_Enable();
	
	u8 Local_u8Iterrator = 0;
	for(Local_u8Iterrator = 0; Local_u8Iterrator < LM35_NUM; Local_u8Iterrator++)
	{		
		if(Copy_PstrLM35Config[Local_u8Iterrator].LM35_POS_CHANNEL != NOT_CONNECTED)
		{
			DIO_enuSetPinDirection(DIO_u8PORTA, Copy_PstrLM35Config[Local_u8Iterrator].LM35_POS_CHANNEL, DIO_u8INPUT);
			ADC_enuSelectChannel(Copy_PstrLM35Config[Local_u8Iterrator].LM35_POS_CHANNEL);
		}
			
		if(Copy_PstrLM35Config[Local_u8Iterrator].LM35_NEG_CHANNEL != NOT_CONNECTED)
		{
			DIO_enuSetPinDirection(DIO_u8PORTA, Copy_PstrLM35Config[Local_u8Iterrator].LM35_NEG_CHANNEL, DIO_u8INPUT);
			ADC_enuSelectChannel(Copy_PstrLM35Config[Local_u8Iterrator].LM35_NEG_CHANNEL);
		}
	}
	
	ADC_enuEnable();
	return Local_enuErrorState;
}

ES_t Thermistor_LM35_enuGetTempVal(u8 Copy_u8Thermistor_LM35_ID, u16 *Copy_Pf32TempValue)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	if(Copy_Pf32TempValue != NULL)
	{
		Local_enuErrorState = ADC_enuStartConversion();
		*Copy_Pf32TempValue = LM35_f32Tempeture;	
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	
	return Local_enuErrorState;
}