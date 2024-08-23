#include "DIO.h"

void DIO_Init_pin(char PORT,char BIN,char MODE)
{
	switch(MODE)
	{
		case INPUT:
			switch(PORT)
			{	
				case DIO_PORTB:
					CLR_BIT(DDRB,BIN);
					break;
				case DIO_PORTC:
					CLR_BIT(DDRC,BIN);
					break;
				case DIO_PORTD:
					CLR_BIT(DDRD,BIN);
					break;	
			}
			break;
		
		case OUTPUT:
			switch(PORT)
			{
				case DIO_PORTB:
					SET_BIT(DDRB,BIN);
					break;
				case DIO_PORTC:
					SET_BIT(DDRC,BIN);
					break;
				case DIO_PORTD:
					SET_BIT(DDRD,BIN);
					break;
			}
			break;
	}
}


void DIO_Digital_write(char PORT,char BIN,char VALUE)
{
	switch(VALUE){
		case HIGH:
			switch(PORT){
				case DIO_PORTB:
					SET_BIT(PORTB,BIN);
					break;
				case DIO_PORTC:
					SET_BIT(PORTC,BIN);
					break;
				case DIO_PORTD:
					SET_BIT(PORTD,BIN);
					break;
			}
			break;
		
		case LOW:
			switch(PORT)
			{
				case DIO_PORTB:
					CLR_BIT(PORTB,BIN);
					break;
				case DIO_PORTC:
					CLR_BIT(PORTC,BIN);
					break;
				case DIO_PORTD:
					CLR_BIT(PORTD,BIN);
					break;
			}
			break;
	}
}


void DIO_InitPort(char port,char direction)
{
	switch(direction)
		{
		case INPUT:
			switch(port)
			{
				case DIO_PORTB:
					DDRB=0x00;
					break;
				case DIO_PORTC:
					DDRC=0x00;
					break;
				case DIO_PORTD:
					DDRD=0x00;
					break;
			}
			break;
		
		case OUTPUT:
			switch(port)
			{
				case DIO_PORTB:
					DDRB=0xFF;
					break;
				case DIO_PORTC:
					DDRC=0xFF;
					break;
				case DIO_PORTD:
					DDRD=0xFF;
					break;
		}
		break;
	}
}


char DIO_Digital_Read(char port,char pin)
{
	switch(port)
	{
		case DIO_PORTB:
			if(GET_BIT(PINB,pin))return HIGH;
			else return LOW;
			break;
		case DIO_PORTC:
			if(GET_BIT(PINC,pin))return HIGH;
			else return LOW;
			break;
		case DIO_PORTD:
			if(GET_BIT(PIND,pin))return HIGH;
			else return LOW;
			break;
	}
	return 0;
}
