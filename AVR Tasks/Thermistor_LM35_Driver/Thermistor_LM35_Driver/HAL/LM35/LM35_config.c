/*
 * LM35_config.c
 *
 * Created: 1/28/2024 2:25:59 PM
 *  Author: Mostafa Edrees
 */ 

#include "LM35_config.h"
#include "LM35_priv.h"

LM35_Configuration_t LM35_AstrLM35Config[LM35_NUM] = 
{
	{ADC_CHANNEL_0, NOT_CONNECTED}
};