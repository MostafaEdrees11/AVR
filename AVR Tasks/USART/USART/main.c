/*
 * USART.c
 *
 * Created: 6/21/2024 6:33:16 PM
 * Author : Mostafa Edrees
 */ 

#include "LIB/Error_States.h"
#include "LIB/stdTypes.h"

#include "MCAL/DIO/DIO_int.h"
#include "MCAL/USART/USART_int.h"


int main(void)
{
	u8 Local_u8Data;
	char string[40];
	
	DIO_enuSetPinDirection(DIO_u8PORTD, DIO_u8PIN1, DIO_u8OUTPUT);	//Tx
	DIO_enuSetPinDirection(DIO_u8PORTD, DIO_u8PIN0, DIO_u8INPUT);	//Rx
	
	DIO_enuSetPinDirection(DIO_u8PORTA, DIO_u8PIN0, DIO_u8OUTPUT);	//led
	DIO_enuSetPinDirection(DIO_u8PORTA, DIO_u8PIN3, DIO_u8OUTPUT);	//buzzer
	
	DIO_enuSetPinVal(DIO_u8PORTA, DIO_u8PIN0, DIO_u8LOW);
	DIO_enuSetPinVal(DIO_u8PORTA, DIO_u8PIN3, DIO_u8LOW);
	
	USART_enuInit();
	
	USART_enuSendString("   Welcome   \r\n");
	USART_enuSendString("Are you Ready\r\n");
	
    /* Replace with your application code */
    while (1) 
    {
		USART_enuSendString("Enter your choice: ");
		USART_enuReceiveStringWithKey(string);
		USART_enuSendString(string);
		USART_enuSendString("\r\n");
		
		if(strcmp(string, "ledon") == 0)
		{
			USART_enuSendString("Led is ON\r\n");
			DIO_enuSetPinVal(DIO_u8PORTA, DIO_u8PIN0, DIO_u8HIGH);
		}
		else if(strcmp(string, "ledoff") == 0)
		{
			USART_enuSendString("Led is OFF\r\n");
			DIO_enuSetPinVal(DIO_u8PORTA, DIO_u8PIN0, DIO_u8LOW);
		}
		else
		{
			USART_enuSendString("Wrong Choice\r\n");
			DIO_enuSetPinVal(DIO_u8PORTA, DIO_u8PIN3, DIO_u8HIGH);
		}
    }
}

