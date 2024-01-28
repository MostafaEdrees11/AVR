/**
 ******************************************************************************
 * @file           : Seven_Segment_prog.c
 * @author         : Mostafa Edrees
 * @brief          : program file of Seven Segment.
 * @date           : 10/20/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/

#include "../../LIB/stdTypes.h"
#include "../../LIB/Error_States.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "Seven_Segment_config.h"
#include "Seven_Segment_priv.h"

ES_t Seven_Segment_enuInit(void)
{
	ES_t Local_u8ErrorState = ES_NOK;
	
	u32 Local_u32CheckError = 0;
	u8 Local_u8Iterator = 0;
	
	Local_u32CheckError |= (DIO_enuSetPinDirection(SEG_APORT, SEG_APIN, DIO_u8OUTPUT) << Local_u8Iterator);
	Local_u32CheckError |= (DIO_enuSetPinDirection(SEG_BPORT, SEG_BPIN, DIO_u8OUTPUT) << (Local_u8Iterator += ERROR_STATE_SIZE));
	Local_u32CheckError |= (DIO_enuSetPinDirection(SEG_CPORT, SEG_CPIN, DIO_u8OUTPUT) << (Local_u8Iterator += ERROR_STATE_SIZE));
	Local_u32CheckError |= (DIO_enuSetPinDirection(SEG_DPORT, SEG_DPIN, DIO_u8OUTPUT) << (Local_u8Iterator += ERROR_STATE_SIZE));
	Local_u32CheckError |= (DIO_enuSetPinDirection(SEG_EPORT, SEG_EPIN, DIO_u8OUTPUT) << (Local_u8Iterator += ERROR_STATE_SIZE));
	Local_u32CheckError |= (DIO_enuSetPinDirection(SEG_FPORT, SEG_FPIN, DIO_u8OUTPUT) << (Local_u8Iterator += ERROR_STATE_SIZE));
	Local_u32CheckError |= (DIO_enuSetPinDirection(SEG_GPORT, SEG_GPIN, DIO_u8OUTPUT) << (Local_u8Iterator += ERROR_STATE_SIZE));
	
	*((u8 *)0x5c) = 0;
	*((u8 *)0x4b) = 0;
	*((u8 *)0x4a) = 0;
	
	*((u8 *)0x5c) = (u8)Local_u32CheckError;
	*((u8 *)0x4b) = (u8)(Local_u32CheckError >> 8);
	*((u8 *)0x4a) = (u8)(Local_u32CheckError >> 16);
	
	for(Local_u8Iterator = 0; Local_u8Iterator < sizeof(Local_u32CheckError) * 8; Local_u8Iterator += ERROR_STATE_SIZE)
	{
		if(((Local_u32CheckError >> Local_u8Iterator) & ERROR_STATE_MASK) != ES_OK)
		{
			return Local_u8ErrorState;
		}
	}
	Local_u8ErrorState = ES_OK;
	
	/* Configure Common Pin as output if it is connected */
	#if SEG_CMN_PORT <= DIO_u8PORTD && SEG_CMN_PIN <= DIO_u8PIN7
	Local_u8ErrorState = DIO_enuSetPinDirection(SEG_CMN_PORT, SEG_CMN_PIN, DIO_u8OUTPUT);
	#elif SEG_CMN_PORT == NOT_CONNECTED || SEG_CMN_PIN == NOT_CONNECTED
	
	#else
	#error "Common Pin has a wrong configuration"
	#endif
	
	/* Configure Dot Pin as output if it is connected */
	#if SEG_DOT_PORT <= DIO_u8PORTD && SEG_DOT_PIN <= DIO_u8PIN7
	Local_u8ErrorState = DIO_enuSetPinDirection(SEG_DOT_PORT, SEG_DOT_PIN, DIO_u8OUTPUT);
	#elif SEG_DOT_PORT == NOT_CONNECTED || SEG_DOT_PIN == NOT_CONNECTED
	
	#else
	#error "Dot Pin has a wrong configuration"
	#endif
	
	return Local_u8ErrorState;
}

ES_t Seven_Segment_enuDisplayNumber(u8 Copy_u8Number)
{
	ES_t Local_u8ErrorState = ES_NOK;
	
	u32 Local_u32CheckError = 0;
	u8 Local_u8Iterator = 0;
	
	if(Copy_u8Number < 10)
	{
		#if SEG_TYPE == COMMON_ANODE
		Local_u32CheckError |= (DIO_enuSetPinVal(SEG_APORT, SEG_APIN, !((SEGCth_Numbers[Copy_u8Number] >> APIN_POS) & MASK_BIT)) << Local_u8Iterator);
		Local_u32CheckError |= (DIO_enuSetPinVal(SEG_BPORT, SEG_BPIN, !((SEGCth_Numbers[Copy_u8Number] >> BPIN_POS) & MASK_BIT)) << (Local_u8Iterator += ERROR_STATE_SIZE));
		Local_u32CheckError |= (DIO_enuSetPinVal(SEG_CPORT, SEG_CPIN, !((SEGCth_Numbers[Copy_u8Number] >> CPIN_POS) & MASK_BIT)) << (Local_u8Iterator += ERROR_STATE_SIZE));
		Local_u32CheckError |= (DIO_enuSetPinVal(SEG_DPORT, SEG_DPIN, !((SEGCth_Numbers[Copy_u8Number] >> DPIN_POS) & MASK_BIT)) << (Local_u8Iterator += ERROR_STATE_SIZE));
		Local_u32CheckError |= (DIO_enuSetPinVal(SEG_EPORT, SEG_EPIN, !((SEGCth_Numbers[Copy_u8Number] >> EPIN_POS) & MASK_BIT)) << (Local_u8Iterator += ERROR_STATE_SIZE));
		Local_u32CheckError |= (DIO_enuSetPinVal(SEG_FPORT, SEG_FPIN, !((SEGCth_Numbers[Copy_u8Number] >> FPIN_POS) & MASK_BIT)) << (Local_u8Iterator += ERROR_STATE_SIZE));
		Local_u32CheckError |= (DIO_enuSetPinVal(SEG_GPORT, SEG_GPIN, !((SEGCth_Numbers[Copy_u8Number] >> GPIN_POS) & MASK_BIT)) << (Local_u8Iterator += ERROR_STATE_SIZE));
		#elif SEG_TYPE == COMMON_CATHODE
		Local_u32CheckError |= (DIO_enuSetPinVal(SEG_APORT, SEG_APIN, ((SEGCth_Numbers[Copy_u8Number] >> APIN_POS) & MASK_BIT)) << Local_u8Iterator);
		Local_u32CheckError |= (DIO_enuSetPinVal(SEG_BPORT, SEG_BPIN, ((SEGCth_Numbers[Copy_u8Number] >> BPIN_POS) & MASK_BIT)) << (Local_u8Iterator += ERROR_STATE_SIZE));
		Local_u32CheckError |= (DIO_enuSetPinVal(SEG_CPORT, SEG_CPIN, ((SEGCth_Numbers[Copy_u8Number] >> CPIN_POS) & MASK_BIT)) << (Local_u8Iterator += ERROR_STATE_SIZE));
		Local_u32CheckError |= (DIO_enuSetPinVal(SEG_DPORT, SEG_DPIN, ((SEGCth_Numbers[Copy_u8Number] >> DPIN_POS) & MASK_BIT)) << (Local_u8Iterator += ERROR_STATE_SIZE));
		Local_u32CheckError |= (DIO_enuSetPinVal(SEG_EPORT, SEG_EPIN, ((SEGCth_Numbers[Copy_u8Number] >> EPIN_POS) & MASK_BIT)) << (Local_u8Iterator += ERROR_STATE_SIZE));
		Local_u32CheckError |= (DIO_enuSetPinVal(SEG_FPORT, SEG_FPIN, ((SEGCth_Numbers[Copy_u8Number] >> FPIN_POS) & MASK_BIT)) << (Local_u8Iterator += ERROR_STATE_SIZE));
		Local_u32CheckError |= (DIO_enuSetPinVal(SEG_GPORT, SEG_GPIN, ((SEGCth_Numbers[Copy_u8Number] >> GPIN_POS) & MASK_BIT)) << (Local_u8Iterator += ERROR_STATE_SIZE));
		#else
		#error "Seven Segment Type has a wrong configuration"
		#endif
		
		for(Local_u8Iterator = 0; Local_u8Iterator < sizeof(Local_u32CheckError) * 8; Local_u8Iterator += ERROR_STATE_SIZE)
		{
			if(((Local_u32CheckError >> Local_u8Iterator) & ERROR_STATE_MASK) != ES_OK)
			{
				return Local_u8ErrorState;
			}
		}
		Local_u8ErrorState = ES_OK;
	}
	else
	{
		Local_u8ErrorState = ES_OUT_OF_RANGE;
	}
	
	return Local_u8ErrorState;
}

ES_t Seven_Segment_enuEnableCommon(void)
{
	ES_t Local_u8ErrorState = ES_NOK;
	
	#if SEG_CMN_PORT <= DIO_u8PORTD && SEG_CMN_PIN <= DIO_u8PIN7
		#if SEG_TYPE == COMMON_ANODE
		Local_u8ErrorState = DIO_enuSetPinVal(SEG_CMN_PORT, SEG_CMN_PIN, DIO_u8HIGH);
		#elif SEG_TYPE == COMMON_CATHODE
		Local_u8ErrorState = DIO_enuSetPinVal(SEG_CMN_PORT, SEG_CMN_PIN, DIO_u8LOW);
		#else
		#error "Seven Segment Type has a wrong configuration"
		#endif
	#elif SEG_CMN_PORT == NOT_CONNECTED || SEG_CMN_PIN == NOT_CONNECTED
	
	#else
	#error "Common Pin has a wrong configuration"
	#endif
	
	return Local_u8ErrorState;
}

ES_t Seven_Segment_enuDisableCommon(void)
{
	ES_t Local_u8ErrorState = ES_NOK;
	
	#if SEG_CMN_PORT <= DIO_u8PORTD && SEG_CMN_PIN <= DIO_u8PIN7
		#if SEG_TYPE == COMMON_ANODE
		Local_u8ErrorState = DIO_enuSetPinVal(SEG_CMN_PORT, SEG_CMN_PIN, DIO_u8LOW);
		#elif SEG_TYPE == COMMON_CATHODE
		Local_u8ErrorState = DIO_enuSetPinVal(SEG_CMN_PORT, SEG_CMN_PIN, DIO_u8HIGH);
		#else
		#error "Seven Segment Type has a wrong configuration"
		#endif
	#elif SEG_CMN_PORT == NOT_CONNECTED || SEG_CMN_PIN == NOT_CONNECTED
	
	#else
	#error "Common Pin has a wrong configuration"
	#endif
	
	return Local_u8ErrorState;
}

ES_t Seven_Segment_enuEnableDot(void)
{
	ES_t Local_u8ErrorState = ES_NOK;
	
	#if SEG_DOT_PORT <= DIO_u8PORTD && SEG_DOT_PIN <= DIO_u8PIN7
		#if SEG_TYPE == COMMON_ANODE
		Local_u8ErrorState = DIO_enuSetPinVal(SEG_DOT_PORT, SEG_DOT_PIN, DIO_u8LOW);
		#elif SEG_TYPE == COMMON_CATHODE
		Local_u8ErrorState = DIO_enuSetPinVal(SEG_DOT_PORT, SEG_DOT_PIN, DIO_u8HIGH);
		#else
		#error "Seven Segment Type has a wrong configuration"
		#endif
	#elif SEG_DOT_PORT == NOT_CONNECTED || SEG_DOT_PIN == NOT_CONNECTED
	
	#else
	#error "Dot Pin has a wrong configuration"
	#endif
	
	return Local_u8ErrorState;
}

ES_t Seven_Segment_enuDisableDot(void)
{
	ES_t Local_u8ErrorState = ES_NOK;
	
	#if SEG_DOT_PORT <= DIO_u8PORTD && SEG_DOT_PIN <= DIO_u8PIN7
		#if SEG_TYPE == COMMON_ANODE
		Local_u8ErrorState = DIO_enuSetPinVal(SEG_DOT_PORT, SEG_DOT_PIN, DIO_u8HIGH);
		#elif SEG_TYPE == COMMON_CATHODE
		Local_u8ErrorState = DIO_enuSetPinVal(SEG_DOT_PORT, SEG_DOT_PIN, DIO_u8LOW);
		#else
		#error "Seven Segment Type has a wrong configuration"
		#endif
	#elif SEG_DOT_PORT == NOT_CONNECTED || SEG_DOT_PIN == NOT_CONNECTED
	
	#else
	#error "Dot Pin has a wrong configuration"
	#endif
	
	return Local_u8ErrorState;
}

ES_t Seven_Sement_enuTurnOFF(void)
{
	ES_t Local_u8ErrorState = ES_NOK;
	
	u32 Local_u32CheckError = 0;
	u8 Local_u8Iterator = 0;
	
	#if SEG_TYPE == COMMON_ANODE
	Local_u32CheckError |= (DIO_enuSetPinVal(SEG_APORT, SEG_APIN, DIO_u8HIGH) << Local_u8Iterator);
	Local_u32CheckError |= (DIO_enuSetPinVal(SEG_BPORT, SEG_BPIN, DIO_u8HIGH) << (Local_u8Iterator += ERROR_STATE_SIZE));
	Local_u32CheckError |= (DIO_enuSetPinVal(SEG_CPORT, SEG_CPIN, DIO_u8HIGH) << (Local_u8Iterator += ERROR_STATE_SIZE));
	Local_u32CheckError |= (DIO_enuSetPinVal(SEG_DPORT, SEG_DPIN, DIO_u8HIGH) << (Local_u8Iterator += ERROR_STATE_SIZE));
	Local_u32CheckError |= (DIO_enuSetPinVal(SEG_EPORT, SEG_EPIN, DIO_u8HIGH) << (Local_u8Iterator += ERROR_STATE_SIZE));
	Local_u32CheckError |= (DIO_enuSetPinVal(SEG_FPORT, SEG_FPIN, DIO_u8HIGH) << (Local_u8Iterator += ERROR_STATE_SIZE));
	Local_u32CheckError |= (DIO_enuSetPinVal(SEG_GPORT, SEG_GPIN, DIO_u8HIGH) << (Local_u8Iterator += ERROR_STATE_SIZE));
	
		#if SEG_CMN_PORT <= DIO_u8PORTD && SEG_CMN_PIN <= DIO_u8PIN7
		Local_u8ErrorState = DIO_enuSetPinVal(SEG_CMN_PORT, SEG_CMN_PIN, DIO_u8HIGH);
		#elif SEG_CMN_PORT == NOT_CONNECTED || SEG_CMN_PIN == NOT_CONNECTED
	
		#else
		#error "Common Pin has a wrong configuration"
		#endif
	
		#if SEG_DOT_PORT <= DIO_u8PORTD && SEG_DOT_PIN <= DIO_u8PIN7
		Local_u8ErrorState = DIO_enuSetPinVal(SEG_DOT_PORT, SEG_DOT_PIN, DIO_u8HIGH);
		#elif SEG_DOT_PORT == NOT_CONNECTED || SEG_DOT_PIN == NOT_CONNECTED
	
		#else
		#error "Dot Pin has a wrong configuration"
		#endif
	#elif SEG_TYPE == COMMON_CATHODE
	Local_u32CheckError |= (DIO_enuSetPinVal(SEG_APORT, SEG_APIN, DIO_u8LOW) << Local_u8Iterator);
	Local_u32CheckError |= (DIO_enuSetPinVal(SEG_BPORT, SEG_BPIN, DIO_u8LOW) << (Local_u8Iterator += ERROR_STATE_SIZE));
	Local_u32CheckError |= (DIO_enuSetPinVal(SEG_CPORT, SEG_CPIN, DIO_u8LOW) << (Local_u8Iterator += ERROR_STATE_SIZE));
	Local_u32CheckError |= (DIO_enuSetPinVal(SEG_DPORT, SEG_DPIN, DIO_u8LOW) << (Local_u8Iterator += ERROR_STATE_SIZE));
	Local_u32CheckError |= (DIO_enuSetPinVal(SEG_EPORT, SEG_EPIN, DIO_u8LOW) << (Local_u8Iterator += ERROR_STATE_SIZE));
	Local_u32CheckError |= (DIO_enuSetPinVal(SEG_FPORT, SEG_FPIN, DIO_u8LOW) << (Local_u8Iterator += ERROR_STATE_SIZE));
	Local_u32CheckError |= (DIO_enuSetPinVal(SEG_GPORT, SEG_GPIN, DIO_u8LOW) << (Local_u8Iterator += ERROR_STATE_SIZE));
	
		#if SEG_CMN_PORT <= DIO_u8PORTD && SEG_CMN_PIN <= DIO_u8PIN7
		Local_u8ErrorState = DIO_enuSetPinVal(SEG_CMN_PORT, SEG_CMN_PIN, DIO_u8LOW);
		#elif SEG_CMN_PORT == NOT_CONNECTED || SEG_CMN_PIN == NOT_CONNECTED
		
		#else
		#error "Common Pin has a wrong configuration"
		#endif
		
		#if SEG_DOT_PORT <= DIO_u8PORTD && SEG_DOT_PIN <= DIO_u8PIN7
		Local_u8ErrorState = DIO_enuSetPinVal(SEG_DOT_PORT, SEG_DOT_PIN, DIO_u8LOW);
		#elif SEG_DOT_PORT == NOT_CONNECTED || SEG_DOT_PIN == NOT_CONNECTED
		
		#else
		#error "Dot Pin has a wrong configuration"
		#endif
	#else
	#error "Seven Segment Type has a wrong configuration"
	#endif
	
	for(Local_u8Iterator = 0; Local_u8Iterator < sizeof(Local_u32CheckError) * 8; Local_u8Iterator += ERROR_STATE_SIZE)
	{
		if(((Local_u32CheckError >> Local_u8Iterator) & ERROR_STATE_MASK) != ES_OK)
		{
			return Local_u8ErrorState;
		}
	}
	Local_u8ErrorState = ES_OK;
	
	return Local_u8ErrorState;
}