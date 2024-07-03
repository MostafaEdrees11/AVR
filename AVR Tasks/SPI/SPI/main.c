/*
 * SPI.c
 *
 * Created: 7/2/2024 6:53:54 PM
 * Author : Mostafa Edrees
 */ 

#include "LIB/Error_States.h"
#include "LIB/stdTypes.h"

#include "MCAL/SPI/SPI_int.h"

#include "MCAL/DIO/DIO_int.h"

#define UDR							*((volatile u8 *)0x2C)

u8 MasterData, SlaveData;


#define master_code
//#define slave_code

#ifdef master_code

int main(void)
{	
	DIO_enuSetPinDirection(DIO_u8PORTB, DIO_u8PIN4, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(DIO_u8PORTB, DIO_u8PIN5, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(DIO_u8PORTB, DIO_u8PIN6, DIO_u8INPUT);
	DIO_enuSetPinDirection(DIO_u8PORTB, DIO_u8PIN7, DIO_u8OUTPUT);
	
	DIO_enuSetPinVal(DIO_u8PORTB, DIO_u8PIN4, DIO_u8HIGH);
	
	MasterData = 'A';
	
	SPI_enuInit();
	
	DIO_enuSetPinVal(DIO_u8PORTB, DIO_u8PIN4, DIO_u8LOW);
	
    /* Replace with your application code */
    while (1) 
    {
		for(u8 i = 'A'; i < 'F'; i++)
		{
			SPI_enuSendData_Master(i, &SlaveData);
			UDR = SlaveData;	
		}
    }
}

#endif

#ifdef slave_code

int main(void)
{
	DIO_enuSetPinDirection(DIO_u8PORTB, DIO_u8PIN4, DIO_u8INPUT);
	DIO_enuSetPinDirection(DIO_u8PORTB, DIO_u8PIN5, DIO_u8INPUT);
	DIO_enuSetPinDirection(DIO_u8PORTB, DIO_u8PIN6, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(DIO_u8PORTB, DIO_u8PIN7, DIO_u8INPUT);
	
	MasterData = 'B';
	
	SPI_enuInit();
	
	/* Replace with your application code */
	while (1)
	{
		for(u8 i = 'F'; i < 'K'; i++)
		{
			SPI_enuReceiveData_Master(&MasterData, i);
			UDR = MasterData;
		}
	}
}

#endif

