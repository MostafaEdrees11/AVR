/**
 ******************************************************************************
 * @file           : DIO_prog.c
 * @author         : Mostafa Edrees
 * @brief          : program file of DIO.
 * @date           : 10/6/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/
#include "stdTypes.h"
#include "Error_States.h"

#include "DIO_priv.h"
#include "DIO_config.h"

ES_t DIO_enuINIT(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	/* initialize of DDR register of 4 ports */
	DDRA = CONC(PA_DDR7,PA_DDR6,PA_DDR5,PA_DDR4,PA_DDR3,PA_DDR2,PA_DDR1,PA_DDR0);
	DDRB = CONC(PB_DDR7,PB_DDR6,PB_DDR5,PB_DDR4,PB_DDR3,PB_DDR2,PB_DDR1,PB_DDR0);
	DDRC = CONC(PC_DDR7,PC_DDR6,PC_DDR5,PC_DDR4,PC_DDR3,PC_DDR2,PC_DDR1,PC_DDR0);
	DDRD = CONC(PD_DDR7,PD_DDR6,PD_DDR5,PD_DDR4,PD_DDR3,PD_DDR2,PD_DDR1,PD_DDR0);
	
	/* initialize of PORT register of 4 ports */
	PORTA = CONC(PA_PORT7,PA_PORT6,PA_PORT5,PA_PORT4,PA_PORT3,PA_PORT2,PA_PORT1,PA_PORT0);
	PORTB = CONC(PB_PORT7,PB_PORT6,PB_PORT5,PB_PORT4,PB_PORT3,PB_PORT2,PB_PORT1,PB_DDR0);
	PORTC = CONC(PC_PORT7,PC_PORT6,PC_PORT5,PC_PORT4,PC_PORT3,PC_PORT2,PC_PORT1,PC_PORT0);
	PORTD = CONC(PD_PORT7,PD_PORT6,PD_PORT5,PD_PORT4,PD_PORT3,PD_PORT2,PD_PORT1,PD_PORT0);
	
	Local_enuErrorState = ES_OK;
	
	return Local_enuErrorState;
}

ES_t DIO_enuSetPortDirection(u8 Copy_u8PortID, u8 Copy_u8Value)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	if(Copy_u8PortID <= DIO_PORTD)
	{
		switch(Copy_u8PortID)
		{
			case DIO_PORTA:
			DDRA = Copy_u8Value;
			break;
			
			case DIO_PORTB:
			DDRB = Copy_u8Value;
			break;
			
			case DIO_PORTC:
			DDRC = Copy_u8Value;
			break;
			
			case DIO_PORTD:
			DDRD = Copy_u8Value;
			break;
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}
	
	return Local_enuErrorState;
}

ES_t DIO_enuSetPortVal(u8 Copy_u8PortID, u8 Copy_u8Value)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	if(Copy_u8PortID <= DIO_PORTD)
	{
		switch(Copy_u8PortID)
		{
			case DIO_PORTA:
			PORTA = Copy_u8Value;
			break;
			
			case DIO_PORTB:
			PORTB = Copy_u8Value;
			break;
			
			case DIO_PORTC:
			PORTC = Copy_u8Value;
			break;
			
			case DIO_PORTD:
			PORTD = Copy_u8Value;
			break;
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}
	
	return Local_enuErrorState;
}

ES_t DIO_enuGetPortVal(u8 Copy_u8PortID, u8 *Copy_pu8Value)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	if(Copy_u8PortID <= DIO_PORTD)
	{
		if(Copy_pu8Value != NULL)
		{
			switch(Copy_u8PortID)
			{
				case DIO_PORTA:
				*Copy_pu8Value = PINA;
				break;
				
				case DIO_PORTB:
				*Copy_pu8Value = PINB;
				break;
				
				case DIO_PORTC:
				*Copy_pu8Value = PINC;
				break;
				
				case DIO_PORTD:
				*Copy_pu8Value = PIND;
				break;
			}
			Local_enuErrorState = ES_OK;
		}
		else
		{
			Local_enuErrorState = ES_NULL_POINTER;
		}
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}
	
	return Local_enuErrorState;
}

ES_t DIO_enuTogPortVal(u8 Copy_u8PortID)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	if(Copy_u8PortID <= DIO_PORTD)
	{
		switch(Copy_u8PortID)
		{
			case DIO_PORTA:
			PORTA = ~PORTA;
			break;
			
			case DIO_PORTB:
			PORTB = ~PORTB;
			break;
			
			case DIO_PORTC:
			PORTC = ~PORTC;
			break;
			
			case DIO_PORTD:
			PORTD = ~PORTD;
			break;
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}
	
	return Local_enuErrorState;
}

ES_t DIO_enuSetPinDirection(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Value)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	if(Copy_u8PortID <= DIO_PORTD && Copy_u8PinID <= DIO_u8PIN7 && Copy_u8Value <= OUTPUT)
	{
		switch(Copy_u8PortID)
		{
			case DIO_PORTA:
			DDRA &= (1 << Copy_u8PinID);
			DDRA |= (Copy_u8Value << Copy_u8PinID);
			break;
			
			case DIO_PORTB:
			DDRB &= (1 << Copy_u8PinID);
			DDRB |= (Copy_u8Value << Copy_u8PinID);
			break;
			
			case DIO_PORTC:
			DDRC &= (1 << Copy_u8PinID);
			DDRC |= (Copy_u8Value << Copy_u8PinID);
			break;
			
			case DIO_PORTD:
			DDRD &= (1 << Copy_u8PinID);
			DDRD |= (Copy_u8Value << Copy_u8PinID);
			break;
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}
	
	return Local_enuErrorState;
}

ES_t DIO_enuSetPinVal(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Value)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	if(Copy_u8PortID <= DIO_PORTD && Copy_u8PinID <= DIO_u8PIN7 && Copy_u8Value <= OUTPUT)
	{
		switch(Copy_u8PortID)
		{
			case DIO_PORTA:
			PORTA &= (1 << Copy_u8PinID);
			PORTA |= (Copy_u8Value << Copy_u8PinID);
			break;
			
			case DIO_PORTB:
			PORTB &= (1 << Copy_u8PinID);
			PORTB |= (Copy_u8Value << Copy_u8PinID);
			break;
			
			case DIO_PORTC:
			PORTC &= (1 << Copy_u8PinID);
			PORTC |= (Copy_u8Value << Copy_u8PinID);
			break;
			
			case DIO_PORTD:
			PORTD &= (1 << Copy_u8PinID);
			PORTD |= (Copy_u8Value << Copy_u8PinID);
			break;
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}
	
	return Local_enuErrorState;
}

ES_t DIO_enuGetPinVal(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 *Copy_pu8Value)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	if(Copy_u8PortID <= DIO_PORTD && Copy_u8PinID <= DIO_u8PIN7)
	{
		if(Copy_pu8Value != NULL)
		{
			switch(Copy_u8PortID)
			{
				case DIO_PORTA:
				*Copy_pu8Value = ((PINA >> Copy_u8PinID) & 1);
				break;
				
				case DIO_PORTB:
				*Copy_pu8Value = ((PINB >> Copy_u8PinID) & 1);
				break;
				
				case DIO_PORTC:
				*Copy_pu8Value = ((PINC >> Copy_u8PinID) & 1);
				break;
				
				case DIO_PORTD:
				*Copy_pu8Value = ((PIND >> Copy_u8PinID) & 1);
				break;
			}
		}
		else
		{
			Local_enuErrorState = ES_NULL_POINTER;
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}
	
	return Local_enuErrorState;
}

ES_t DIO_enuTogPinVal(u8 Copy_u8PortID, u8 Copy_u8PinID)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	if(Copy_u8PortID <= DIO_PORTD && Copy_u8PinID <= DIO_u8PIN7)
	{
		switch(Copy_u8PortID)
		{
			case DIO_PORTA:
			PORTA ^= (1 << Copy_u8PinID);
			break;
			
			case DIO_PORTB:
			PORTB ^= (1 << Copy_u8PinID);
			break;
			
			case DIO_PORTC:
			PORTC ^= (1 << Copy_u8PinID);
			break;
			
			case DIO_PORTD:
			PORTD ^= (1 << Copy_u8PinID);
			break;
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}
	
	return Local_enuErrorState;
}