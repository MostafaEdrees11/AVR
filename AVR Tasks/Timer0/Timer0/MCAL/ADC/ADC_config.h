 /**
 ******************************************************************************
 * @file           : ADC_config.h
 * @author         : Mostafa Edrees
 * @brief          : Configuration file of ADC.
 * @date           : 26/1/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/* Configuration of Reference Voltage */
#define ADC_VOLT_REF						AVCC_REF

/* Configuration of Adjustment */
#define ADC_ADJUST							RIGHT_ADJUST

/* Configuration of PreScalar */
#define ADC_PRESCALER						DIVISION_FACTOR_8



#endif /* ADC_CONFIG_H_ */