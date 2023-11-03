/**
 ******************************************************************************
 * @file           : LCD_prog.c
 * @author         : Mostafa Edrees
 * @brief          : program file of LCD.
 * @date           : 11/1/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/

#include "Error_States.h"
#include "stdTypes.h"

#include "DIO_int.h"

#include "LCD_priv.h"
#include "LCD_config.h"

//#include <util/delay.h>

static u8 LCD_u8PosCounter = 0;

ES_t LCD_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	/* Set Control Pins as output */
	Local_enuErrorState = DIO_enuSetPinDirection(RS_PORT, RS_PIN, DIO_u8OUTPUT);
	Local_enuErrorState = DIO_enuSetPinDirection(RW_PORT, RW_PIN, DIO_u8OUTPUT);
	Local_enuErrorState = DIO_enuSetPinDirection(EN_PORT, EN_PIN, DIO_u8OUTPUT);
	
	/* Set Data Pins as output */
	Local_enuErrorState = DIO_enuSetPinDirection(D7_PORT, D7_PIN, DIO_u8OUTPUT);
	Local_enuErrorState = DIO_enuSetPinDirection(D6_PORT, D6_PIN, DIO_u8OUTPUT);
	Local_enuErrorState = DIO_enuSetPinDirection(D5_PORT, D5_PIN, DIO_u8OUTPUT);
	Local_enuErrorState = DIO_enuSetPinDirection(D4_PORT, D4_PIN, DIO_u8OUTPUT);
	
	_delay_ms(35);
	
	#if LCD_MODE == EIGHT_BIT
	Local_enuErrorState = DIO_enuSetPinDirection(D3_PORT, D3_PIN, DIO_u8OUTPUT);
	Local_enuErrorState = DIO_enuSetPinDirection(D2_PORT, D2_PIN, DIO_u8OUTPUT);
	Local_enuErrorState = DIO_enuSetPinDirection(D1_PORT, D1_PIN, DIO_u8OUTPUT);
	Local_enuErrorState = DIO_enuSetPinDirection(D0_PORT, D0_PIN, DIO_u8OUTPUT);
	/* Function Set */
	Local_enuErrorState = LCD_inlenuSendCommand(LCD_8Bit_TwoLine_5_7CharFont);
	_delay_ms(1);
	
	#elif LCD_MODE == FOUR_BIT
	/* Function Set */
	Local_enuErrorState = LCD_inlenuSendCommand(LCD_4Bit_TwoLine_5_7CharFont);
	_delay_ms(1);
	
	#else
	#error "LCD Mode has a wrong configuration"
	#endif
	
	/* Display ON/OFF Control */
	Local_enuErrorState = LCD_inlenuSendCommand(LCD_DisplayOn_CursorOn_Blinking);
	_delay_ms(1);
	
	/* Display Clear */
	Local_enuErrorState = LCD_inlenuSendCommand(LCD_Clear_Display);
	_delay_ms(2);
	
	/* Entry Mode Set */
	Local_enuErrorState = LCD_inlenuSendCommand(LCD_Increase_NoShift);
	_delay_ms(1);
	
	return Local_enuErrorState;
}

ES_t LCD_enuDisplayChar(u8 Copy_u8Data)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	/* RS --> High to write Data */
	Local_enuErrorState = DIO_enuSetPinVal(RS_PORT, RS_PIN, DIO_u8HIGH);
	
	/* Call Latch Function */
	Local_enuErrorState = LCD_enuLatch(Copy_u8Data);
	
	return Local_enuErrorState;
}

ES_t LCD_enuSendCommand(u8 Copy_u8Command)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	/* RS --> LOW to write Command */
	Local_enuErrorState = DIO_enuSetPinVal(RS_PORT, RS_PIN, DIO_u8LOW);
	
	/* Call Latch Function */
	Local_enuErrorState = LCD_enuLatch(Copy_u8Command);
	
	return Local_enuErrorState;
}

static ES_t LCD_enuLatch(u8 Copy_u8Data)
{	
	ES_t Local_enuErrorState = ES_NOK;
	u8 Local_u8RSValue = 0;
	
	/* RW --> LOW to write */
	Local_enuErrorState = DIO_enuSetPinVal(RW_PORT, RW_PIN, DIO_u8LOW);
	
	/* Enable --> LOW */
	Local_enuErrorState = DIO_enuSetPinVal(EN_PORT, EN_PIN, DIO_u8LOW);
	
	/* Check position in case of we send data */
	DIO_enuGetPinVal(RS_PORT, RS_PIN, &Local_u8RSValue);
	if(Local_u8RSValue == DIO_u8HIGH)
	{
		LCD_vidCheckPosition();
	}
	
	#if LCD_MODE == EIGHT_BIT
	/* Write Command to Data Pins */
	Local_enuErrorState = DIO_enuSetPinVal(D7_PORT, D7_PIN, ((Copy_u8Data >> D7_POS) & MASK_BIT));
	Local_enuErrorState = DIO_enuSetPinVal(D6_PORT, D6_PIN, ((Copy_u8Data >> D6_POS) & MASK_BIT));
	Local_enuErrorState = DIO_enuSetPinVal(D5_PORT, D5_PIN, ((Copy_u8Data >> D5_POS) & MASK_BIT));
	Local_enuErrorState = DIO_enuSetPinVal(D4_PORT, D4_PIN, ((Copy_u8Data >> D4_POS) & MASK_BIT));
	Local_enuErrorState = DIO_enuSetPinVal(D3_PORT, D3_PIN, ((Copy_u8Data >> D3_POS) & MASK_BIT));
	Local_enuErrorState = DIO_enuSetPinVal(D2_PORT, D2_PIN, ((Copy_u8Data >> D2_POS) & MASK_BIT));
	Local_enuErrorState = DIO_enuSetPinVal(D1_PORT, D1_PIN, ((Copy_u8Data >> D1_POS) & MASK_BIT));
	Local_enuErrorState = DIO_enuSetPinVal(D0_PORT, D0_PIN, ((Copy_u8Data >> D0_POS) & MASK_BIT));
	
	#elif LCD_MODE == FOUR_BIT
	u8 Local_u8FourBitData = 0;
	/* Send Data from D7..D4 */
	Local_u8FourBitData = (Copy_u8Data & 0xF0);
	Local_enuErrorState = DIO_enuSetPinVal(D7_PORT, D7_PIN, ((Local_u8FourBitData >> D7_POS) & MASK_BIT));
	Local_enuErrorState = DIO_enuSetPinVal(D6_PORT, D6_PIN, ((Local_u8FourBitData >> D6_POS) & MASK_BIT));
	Local_enuErrorState = DIO_enuSetPinVal(D5_PORT, D5_PIN, ((Local_u8FourBitData >> D5_POS) & MASK_BIT));
	Local_enuErrorState = DIO_enuSetPinVal(D4_PORT, D4_PIN, ((Local_u8FourBitData >> D4_POS) & MASK_BIT));
	
	LCD_vidTrigger_LATCH();
	_delay_ms(1);
	
	/* Send Data from D3..D0 */
	Local_u8FourBitData = (Copy_u8Data << FOUR_BIT);
	Local_enuErrorState = DIO_enuSetPinVal(D7_PORT, D7_PIN, ((Local_u8FourBitData >> D7_POS) & MASK_BIT));
	Local_enuErrorState = DIO_enuSetPinVal(D6_PORT, D6_PIN, ((Local_u8FourBitData >> D6_POS) & MASK_BIT));
	Local_enuErrorState = DIO_enuSetPinVal(D5_PORT, D5_PIN, ((Local_u8FourBitData >> D5_POS) & MASK_BIT));
	Local_enuErrorState = DIO_enuSetPinVal(D4_PORT, D4_PIN, ((Local_u8FourBitData >> D4_POS) & MASK_BIT));
	
	#else
	#error "LCD Mode has a wrong configuration"
	#endif
	
	LCD_vidTrigger_LATCH();
	
	return Local_enuErrorState;
}

static void LCD_vidTrigger_LATCH(void)
{
	/* Enable EN --> it works at Rising Edge */
	DIO_enuSetPinVal(EN_PORT, EN_PIN, DIO_u8HIGH);
	_delay_ms(10);
	DIO_enuSetPinVal(EN_PORT, EN_PIN, DIO_u8LOW);
}

static inline ES_t LCD_inlenuSendCommand(u8 Copy_u8Command)
{
	ES_t Local_enuErrorState = ES_NOK;
		
	/* RS --> LOW to write Command */
	Local_enuErrorState = DIO_enuSetPinVal(RS_PORT, RS_PIN, DIO_u8LOW);

	/* Call Latch Function */
	Local_enuErrorState = LCD_enuLatch(Copy_u8Command);
	
	return Local_enuErrorState;
}

ES_t LCD_enuGoToPosition(u8 Copy_u8Line, u8 Copy_u8Position)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	if(Copy_u8Position >= 0 && Copy_u8Position < 16)
	{
		if(Copy_u8Line == LCD_FIRST_LINE)
		{
			Local_enuErrorState = LCD_inlenuSendCommand(LCD_BEGIN_AT_FIRST_ROW + Copy_u8Position);
		}
		else if(Copy_u8Line == LCD_SECOND_LINE)
		{
			Local_enuErrorState = LCD_inlenuSendCommand(LCD_BEGIN_AT_SECOND_ROW + Copy_u8Position);
		}
	}
	
	return Local_enuErrorState;
}

static void LCD_vidCheckPosition(void)
{
	if(LCD_u8PosCounter == 16)
	{
		LCD_enuGoToPosition(LCD_SECOND_LINE, 0);
		LCD_u8PosCounter++;
	}
	else if(LCD_u8PosCounter == 32)
	{
		LCD_inlenuSendCommand(LCD_Clear_Display);
		LCD_enuGoToPosition(LCD_FIRST_LINE, 0);
		LCD_u8PosCounter = 0;
	}
	else
	{
		LCD_u8PosCounter++;
	}
}

void LCD_vidClearScreen(void)
{
	LCD_inlenuSendCommand(LCD_Clear_Display);
	LCD_u8PosCounter = 0;
}

ES_t LCD_enuWriteString(u8 *Copy_pu8Str)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	if(Copy_pu8Str != NULL)
	{
		while(*Copy_pu8Str != '\0')
		{
			Local_enuErrorState = LCD_enuDisplayChar(*Copy_pu8Str);
			Copy_pu8Str++;
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	
	return Local_enuErrorState;
}