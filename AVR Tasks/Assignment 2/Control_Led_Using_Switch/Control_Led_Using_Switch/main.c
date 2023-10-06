/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mostafa Edrees
 * @brief          : Control_Led_Using_Switch
 * @date           : 10/6/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/

#include "stdTypes.h"

/* registers of PORTA */
#define PORTA			*((u8 *)0x3B)
#define DDRA			*((u8 *)0x3A)
#define PINA			*((volatile u8 *)0x39)

/* registers of PORTB */
#define PORTB			*((u8 *)0x38)
#define DDRB			*((u8 *)0x37)
#define PINB			*((volatile u8 *)0x36)

/* Leds Pins */
#define Led1			0
#define Led2			1

/* Switch Pins */
#define SW1				0
#define SW2				1
#define SW3				2

int main(void)
{
	/* Led1 & Led2 --> connected to pin 0 & 1 in PORTA (output pins) */
	DDRA |= (1 << Led1);
	DDRA |= (1 << Led2);
	
	/* SW1 & SW2 & SW3 --> connected to pin 0 & 1 & 2 in PORTB (input pins & enable PULL UP) */
	DDRB &= ~(1 << SW1);
	DDRB &= ~(1 << SW2);
	DDRB &= ~(1 << SW3);
	
	PORTB |= (1 << SW1);
	PORTB |= (1 << SW2);
	PORTB |= (1 << SW3);
	
	/* Turn off the 2 leds */
	PORTA &= ~(1 << Led1);
	PORTA &= ~(1 << Led2);
	
    /* Replace with your application code */
    while (1) 
    {
		/* In case no switches are pressed both leds are off. */
		if(((PINB >> SW1) & 1) && ((PINB >> SW2) & 1) && ((PINB >> SW3) & 1))
		{
			PORTA &= ~(1 << Led1);
			PORTA &= ~(1 << Led2);
		}
		
		/* If switch 1 is pressed just turn on the first led1 only */
		if(((PINB >> SW1) & 1) == 0)
		{
			PORTA |= (1 << Led1);
		}
		
		/* if switch 2 is pressed just turn on led2 only */
		if(((PINB >> SW2) & 1) == 0)
		{
			PORTA |= (1 << Led2);
		}
		
		/* if switch 3 is pressed turn on the 2 leds */
		if(((PINB >> SW3) & 1) == 0)
		{
			PORTA |= (1 << Led1);
			PORTA |= (1 << Led2);
		}
    }
}

