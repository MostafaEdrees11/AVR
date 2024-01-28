/**
 ******************************************************************************
 * @file           : Seven_Segment_config.h
 * @author         : Mostafa Edrees
 * @brief          : Configuration file of Seven Segment.
 * @date           : 10/20/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/

#ifndef SEVEN_SEGMENT_CONFIG_H_
#define SEVEN_SEGMENT_CONFIG_H_

/* pinA configuration */
#define SEG_APIN				DIO_u8PIN0
#define SEG_APORT				DIO_u8PORTB

/* pinB configuration */
#define SEG_BPIN				DIO_u8PIN1
#define SEG_BPORT				DIO_u8PORTB

/* pinC configuration */
#define SEG_CPIN				DIO_u8PIN2
#define SEG_CPORT				DIO_u8PORTB

/* pinD configuration */
#define SEG_DPIN				DIO_u8PIN3
#define SEG_DPORT				DIO_u8PORTB

/* pinE configuration */
#define SEG_EPIN				DIO_u8PIN4
#define SEG_EPORT				DIO_u8PORTB

/* pinF configuration */
#define SEG_FPIN				DIO_u8PIN5
#define SEG_FPORT				DIO_u8PORTB

/* pinG configuration */
#define SEG_GPIN				DIO_u8PIN6
#define SEG_GPORT				DIO_u8PORTB

/* Common pin configuration */
#define SEG_CMN_PIN				NOT_CONNECTED
#define SEG_CMN_PORT			NOT_CONNECTED

/* Dot pin configuration */
#define SEG_DOT_PIN				NOT_CONNECTED
#define SEG_DOT_PORT			NOT_CONNECTED

/* configuration of seven segment type --> COMMON_CATHODE or COMMON_ANODE */
#define SEG_TYPE				COMMON_CATHODE



#endif /* SEVEN_SEGMENT_CONFIG_H_ */