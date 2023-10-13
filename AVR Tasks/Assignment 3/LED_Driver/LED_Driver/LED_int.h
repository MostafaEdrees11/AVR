/**
 ******************************************************************************
 * @file           : LED_int.h
 * @author         : Mostafa Edrees
 * @brief          : interface file of LED.
 * @date           : 10/13/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/

#ifndef LED_INT_H_
#define LED_INT_H_

/* configuration of led states */
#define LED_u8ON			10
#define LED_u8OFF			11

/* configuration of led connection states*/
#define LED_u8SINK			12
#define LED_u8SOURCE		13

ES_t LED_enuINIT(LED_t *Copy_pAstrLedConfig);

ES_t LED_enuTurnON(LED_t *Copy_pstrLedID);

ES_t LED_enuTurnOFF(LED_t *Copy_pstrLedID);


#endif /* LED_INT_H_ */