/*
 * LM35_config.h
 *
 * Created: 1/28/2024 2:26:45 PM
 *  Author: Mostafa Edrees
 */ 


#ifndef LM35_CONFIG_H_
#define LM35_CONFIG_H_

#include "../../LIB/Error_States.h"
#include "../../LIB/stdTypes.h"

#include "../../MCAL/ADC/ADC_int.h"

#define LM35_NUM		1

typedef struct
{
	u8 LM35_POS_CHANNEL;
	u8 LM35_NEG_CHANNEL;
}LM35_Configuration_t;

#endif /* LM35_CONFIG_H_ */