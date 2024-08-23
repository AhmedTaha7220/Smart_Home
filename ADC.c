
#include "ADC.h"

//void ADC_init(void)
//{
//	/* ADMUX Register Bits Description:
//	 * REFS1:0 = 00 to choose to connect external reference voltage by input this voltage through AREF pin
//	 * ADLAR   = 0 right adjusted
//	 * MUX4:0  = 00000 to choose channel 0 as initialization
//	 */
//	ADMUX = 0;
//
//	/* ADCSRA Register Bits Description:
//	 * ADEN    = 1 Enable ADC
//	 * ADIE    = 0 Disable ADC Interrupt
//	 * ADPS2:0 = 011 to choose ADC_Clock=F_CPU/8=1Mhz/8=125Khz --> ADC must operate in range 50-200Khz
//	 */
//	ADCSRA = (1<<ADEN) | (1<<ADPS1) | (1<<ADPS0);
//}
void ADC_Init(unsigned char prescaler, unsigned char vref)
{
	/*Vref -> []*/
	switch(vref)
	{
		case AREF:
		CLR_BIT(ADMUX,REFS1);
		CLR_BIT(ADMUX,REFS0);
		break;
		case AVCC:
		CLR_BIT(ADMUX,REFS1);
		SET_BIT(ADMUX,REFS0);
		break;
		case Internal_11V:
		SET_BIT(ADMUX,REFS1);
		SET_BIT(ADMUX,REFS0);
		break;
	}
	/*prescaler*/
	ADCSRA = ADCSRA & 0xf8;
	ADCSRA = ADCSRA | prescaler; // pre-scaler 128

	/*Reading Adjustment [adlar]*/
	CLR_BIT(ADMUX,ADLAR); //it's default with 0

	/*Enable*/
	SET_BIT(ADCSRA,ADEN);
}

unsigned int ADC_Read(unsigned int channel)
{
	//select channel
	ADMUX =  ADMUX &  0xE0;
	ADMUX = ADMUX | channel;
	
	//start conversion
	SET_BIT(ADCSRA,ADSC);

	//wait while converstion ends
	while(BIT_IS_CLEAR(ADCSRA,ADSC));
	SET_BIT(ADCSRA,ADIF);

	u16 adc;
	adc = ((u16)ADCH<<(u16)8) | (u16)ADCL;
	return adc;
	
	//return read
//	unsigned int adc;
//	adc = ((unsigned int)ADCH<<(unsigned int)8) | (unsigned int)ADCL;
//	return adc;
}
