/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mostafa Edrees
 * @brief          : control  2 multiplexed seven segments using two push buttons.
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

/* registers of PORTC */
#define PORTC			*((u8 *)0x35)
#define DDRC			*((u8 *)0x34)
#define PINC			*((volatile u8 *)0x33)

/* SW pins */
#define SW1				0
#define SW2				1

int main(void)
{
	/* values of Seven Segment Common Cathode */
	u8 SegCth[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
		
	/* 7Seg1 --> connected to PA, 7Seg2 --> connected to PB & They are common cathode */
	DDRA = 0xFF;
	DDRB = 0xFF;
	
	/* SW1 & SW2 --> connected to pin 0 & 1 in PORTC (input pins & enable PULL UP) */
	DDRC &= ~(1 << SW1);
	DDRC &= ~(1 << SW2);
	
	PORTC |= (1 << SW1);
	PORTC |= (1 << SW2);
	
	/* when you start your program , number 50 is displayed. */
	u8 num = 50, ones, tens;
	ones = num % 10;
	tens = num / 10;
	PORTA = SegCth[ones];
	PORTB = SegCth[tens];
	
    /* Replace with your application code */
    while (1) 
    {
		if(((PINC >> SW1) & 1) == 0)	/* SW1 is pressed */
		{
			num++;
			ones = num % 10;
			tens = num / 10;
			PORTA = SegCth[ones];
			PORTB = SegCth[tens];
			while(((PINC >> SW1) & 1) == 0);	/* single press */
		}
		else if(((PINC >> SW2) & 1) == 0)	/* SW2 is pressed */
		{
			num--;
			ones = num % 10;
			tens = num / 10;
			PORTA = SegCth[ones];
			PORTB = SegCth[tens];
			while(((PINC >> SW2) & 1) == 0);	/* single press */
		}
    }
}

