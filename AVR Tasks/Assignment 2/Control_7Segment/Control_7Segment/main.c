/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mostafa Edrees
 * @brief          : control a 7-segment using two push buttons.
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

/* Switch Pins */
#define SW1				0
#define SW2				1
	
int main(void)
{
	/* values of Seven Segment Common Cathode */
	u8 SegCth[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
		
	/* SW1 & SW2 --> connected to pin 0 & 1 in PORTA (input pins & enable PULL UP) */
	DDRA &= ~(1 << SW1);
	DDRA &= ~(1 << SW2);
	
	PORTA |= (1 << SW1);
	PORTA |= (1 << SW2);
	
	/* 7-Segment connected to PORTB (output) */
	DDRB = 0xFF;
	
	s8 num = 0;
	
    /* Replace with your application code */
    while (1) 
    {
		if(((PINA >> SW1) & 1) == 0)		/* SW1 is pressed */
		{
			num++;
			if(num >= 0 && num <= 9)	/* check if number between 0 & 9 */
			{
				PORTB = SegCth[num];
			}
			else
			{
				/* if number > 9 then we put 9 in the num */
				num = 9;
			}
			while(((PINA >> SW1) & 1) == 0);	/* single press */
		}
		else if(((PINA >> SW2) & 1) == 0)	/* SW2 is pressed */
		{
			num--;
			if(num >= 0 && num <= 9)	/* check if number between 0 & 9 */
			{
				PORTB = SegCth[num];
			}
			else
			{
				/* if number < 0 then we put 0 in the num */
				num = 0;
			}
			while(((PINA >> SW2) & 1) == 0);	/* single press */
		}
    }
}

