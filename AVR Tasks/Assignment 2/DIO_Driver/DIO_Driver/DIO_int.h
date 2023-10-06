/**
 ******************************************************************************
 * @file           : DIO_int.h
 * @author         : Mostafa Edrees
 * @brief          : interface file of DIO.
 * @date           : 10/6/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/


#ifndef DIO_INT_H_
#define DIO_INT_H_

/* initialize function */
ES_t DIO_enuINIT(void);

/* PORT functions */
ES_t DIO_enuSetPortDirection(u8 Copy_u8PortID, u8 Copy_u8Value);
ES_t DIO_enuSetPortVal(u8 Copy_u8PortID, u8 Copy_u8Value);
ES_t DIO_enuGetPortVal(u8 Copy_u8PortID, u8 *Copy_pu8Value);
ES_t DIO_enuTogPortVal(u8 Copy_u8PortID);

/* PIN functions */
ES_t DIO_enuSetPinDirection(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Value);
ES_t DIO_enuSetPinVal(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Value);
ES_t DIO_enuGetPinVal(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 *Copy_pu8Value);
ES_t DIO_enuTogPinVal(u8 Copy_u8PortID, u8 Copy_u8PinID);

#endif /* DIO_INT_H_ */