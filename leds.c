/*
 * leds.c
 *
 *  Created on: Jul 20, 2023
 *      Author: Mega Store
 */
#include"leds.h"


void bl(u8 statue){
	SET_BIT(DDRC,blue);
	if(statue==1){
		SET_BIT(PORTC,blue);
	}
	else{
		CLR_BIT(PORTC,blue);
	}
}

void re(u8 statue){
	SET_BIT(DDRC,red);
	if(statue==1){
		SET_BIT(PORTC,red);
	}
	else{
		CLR_BIT(PORTC,red);
	}
}

void gr(u8 statue){
	SET_BIT(DDRC,green);
	if(statue==1){
		SET_BIT(PORTC,green);
	}
	else{
		CLR_BIT(PORTC,green);
	}
}

void ye(u8 statue){
	SET_BIT(DDRD,yellow);
	if(statue==1){
		SET_BIT(PORTD,yellow);
	}
	else{
		CLR_BIT(PORTD,yellow);
	}
}
