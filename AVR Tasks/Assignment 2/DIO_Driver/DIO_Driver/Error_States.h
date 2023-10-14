/**
 ******************************************************************************
 * @file           : Error_States.h
 * @author         : Mostafa Edrees
 * @brief          : error states for all functions
 * @date           : 10/6/2023
 ******************************************************************************
**/


#ifndef ERROR_STATES_H_
#define ERROR_STATES_H_

/* it is a enum contains the error states that may happen in any function */
typedef enum
{
	ES_OK,
	ES_NOK,
	ES_NULL_POINTER,
	ES_OUT_OF_RANGE	
}ES_t;



#endif /* ERROR_STATES_H_ */