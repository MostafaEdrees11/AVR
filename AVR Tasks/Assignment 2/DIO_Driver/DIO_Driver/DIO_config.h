/**
 ******************************************************************************
 * @file           : DIO_config.h
 * @author         : Mostafa Edrees
 * @brief          : Configuration file of DIO.
 * @date           : 10/6/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/


#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_

/* configuration of names of 4 ports */
#define DIO_u8PORTA		0
#define DIO_u8PORTB		1
#define DIO_u8PORTC		2
#define DIO_u8PORTD		3

/* configuration of names of pins */
#define DIO_u8PIN0		0
#define DIO_u8PIN1		1
#define DIO_u8PIN2		2
#define DIO_u8PIN3		3
#define DIO_u8PIN4		4
#define DIO_u8PIN5		5
#define DIO_u8PIN6		6
#define DIO_u8PIN7		7


/* 
Data Direction can be:
	-> INPUT
	-> OUTPUT
*/
/* configurations of Data Direction of the pins at PortA */
#define PA_DDR0			INPUT
#define PA_DDR1			OUTPUT
#define PA_DDR2			OUTPUT
#define PA_DDR3			OUTPUT
#define PA_DDR4			INPUT
#define PA_DDR5			INPUT
#define PA_DDR6			OUTPUT
#define PA_DDR7			INPUT

/* configurations of pins of Data Direction at PortB */
#define PB_DDR0			INPUT
#define PB_DDR1			OUTPUT
#define PB_DDR2			OUTPUT
#define PB_DDR3			OUTPUT
#define PB_DDR4			INPUT
#define PB_DDR5			INPUT
#define PB_DDR6			OUTPUT
#define PB_DDR7			INPUT

/* configurations of pins of Data Direction at PortC */
#define PC_DDR0			INPUT
#define PC_DDR1			OUTPUT
#define PC_DDR2			OUTPUT
#define PC_DDR3			OUTPUT
#define PC_DDR4			INPUT
#define PC_DDR5			INPUT
#define PC_DDR6			OUTPUT
#define PC_DDR7			INPUT

/* configurations of pins of Data Direction at PortD */
#define PD_DDR0			INPUT
#define PD_DDR1			OUTPUT
#define PD_DDR2			OUTPUT
#define PD_DDR3			OUTPUT
#define PD_DDR4			INPUT
#define PD_DDR5			INPUT
#define PD_DDR6			OUTPUT
#define PD_DDR7			INPUT


/* 
PORT (OUTPUT) can be:
	-> LOW
	-> HIGH
PORT (INPUT) can be:
	-> FLOAT
	-> PULL_UP
*/
/* configurations of pin of PORT register at PortA */
#define PA_PORT0			FLOAT
#define PA_PORT1			HIGH
#define PA_PORT2			LOW
#define PA_PORT3			LOW
#define PA_PORT4			PULL_UP
#define PA_PORT5			PULL_UP
#define PA_PORT6			HIGH
#define PA_PORT7			FLOAT

/* configurations of pin of PORT register at PortB */
#define PB_PORT0			FLOAT
#define PB_PORT1			HIGH
#define PB_PORT2			LOW
#define PB_PORT3			LOW
#define PB_PORT4			PULL_UP
#define PB_PORT5			PULL_UP
#define PB_PORT6			HIGH
#define PB_PORT7			FLOAT

/* configurations of pin of PORT register at PortC */
#define PC_PORT0			FLOAT
#define PC_PORT1			HIGH
#define PC_PORT2			LOW
#define PC_PORT3			LOW
#define PC_PORT4			PULL_UP
#define PC_PORT5			PULL_UP
#define PC_PORT6			HIGH
#define PC_PORT7			FLOAT

/* configurations of pin of PORT register at PortD */
#define PD_PORT0			FLOAT
#define PD_PORT1			HIGH
#define PD_PORT2			LOW
#define PD_PORT3			LOW
#define PD_PORT4			PULL_UP
#define PD_PORT5			PULL_UP
#define PD_PORT6			HIGH
#define PD_PORT7			FLOAT

#endif /* DIO_CONFIG_H_ */