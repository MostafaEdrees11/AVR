/*
 * Seven_Segment_Linking_Time.c
 *
 * Created: 10/20/2023 10:26:27 PM
 * Author : Mostafa Edrees
 */ 
#define F_CPU	1000000UL

#include "stdTypes.h"
#include "Error_States.h"

#include "DIO_int.h"
#include "Seven_Segment_config.h"
#include "Seven_Segment_int.h"

#include <util/delay.h>

extern SEG_t SEV_SEG_AstrSEGConfig[SEG_NUM];

int main(void)
{
	ES_t error;
	error = Seven_Segment_enuInit(SEV_SEG_AstrSEGConfig);
	
    /* Replace with your application code */
    while (1) 
    {
		if(error == ES_OK)
		{
			for(u8 i = 0; i < 10; i++)
			{
				Seven_Segment_enuDisplayNumber(0,i);
				Seven_Segment_enuDisplayNumber(1,0);
				for(u8 j = 0; j < 10; j++)
				{
					Seven_Segment_enuDisplayNumber(1,j);
					_delay_ms(300);
				}
			}	
		}
    }
}

