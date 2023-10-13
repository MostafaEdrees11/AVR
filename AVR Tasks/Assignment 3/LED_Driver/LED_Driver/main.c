/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mostafa Edrees
 * @brief          : application file of LED.
 * @date           : 10/13/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/

#define F_CPU	1000000
#include "stdTypes.h"
#include "Error_States.h"

#include "LED_config.h"
#include "LED_int.h"

#include "Switch_config.h"
#include "Switch_int.h"

#include "DIO_int.h"

#include <util/delay.h>

extern LED_t LED_AstrLedConfig[LED_NUM];
extern SW_t SW_AstrSwitchConfig[SW_NUM];


int main(void)
{
	DIO_enuINIT();
	LED_enuINIT(&LED_AstrLedConfig);
	Switch_enuINIT(&SW_AstrSwitchConfig);
	
	u8 Pin_state;
	
    /* Replace with your application code */
    while (1) 
    {
		Switch_enuGetState(&SW_AstrSwitchConfig[1], &Pin_state);
		if(Pin_state == 0)
		{
			LED_enuTurnON(&LED_AstrLedConfig[2]);
		}
		else if(Pin_state == 1)
		{
			LED_enuTurnOFF(&LED_AstrLedConfig[2]);
		}
    }
}

