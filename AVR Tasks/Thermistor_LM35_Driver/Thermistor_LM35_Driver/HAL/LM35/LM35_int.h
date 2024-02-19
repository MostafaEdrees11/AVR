/*
 * LM35_int.h
 *
 * Created: 1/28/2024 2:26:28 PM
 *  Author: Mostafa Edrees
 */ 


#ifndef LM35_INT_H_
#define LM35_INT_H_

ES_t Thermistor_LM35_enuInit(LM35_Configuration_t *Copy_PstrLM35Config);

ES_t Thermistor_LM35_enuGetTempVal(u8 Copy_u8Thermistor_LM35_ID, u16 *Copy_Pf32TempValue);



#endif /* LM35_INT_H_ */