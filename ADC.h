
#ifndef ADC_H_
#define ADC_H_


#include"../LIB/MEM_MAP.h"
#include"../LIB/StdTypes.h"
#include "../Mcal/DIO.h"
#include <avr/io.h>

/*********Defines*********/

/*Registers BITS*/
//ADMUX
#define REFS1 7
#define REFS0 6
#define ADLAR 5

//ADCSRA
#define ADEN 7
#define ADSC 6

/*vref*/
#define AREF 0
#define AVCC 1	
#define Internal_11V 2   /*11 is 1.1v*/

/*prescaler*/
#define ADC_SCALER_2 1
#define ADC_SCALER_4 2
#define ADC_SCALER_8 3
#define ADC_SCALER_16 4
#define ADC_SCALER_32 5
#define ADC_SCALER_64 6
#define ADC_SCALER_128 7

/*Channels*/
#define CH_0 0
#define CH_1 1
#define CH_2 2
#define CH_3 3
#define CH_4 4
#define CH_5 5





void ADC_Init(unsigned char prescaler, unsigned char vref);
unsigned int ADC_Read(unsigned int channel);




#endif /* ADC_H_ */
