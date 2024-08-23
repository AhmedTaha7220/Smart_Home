/*
 * m_driver.c
 *
 *  Created on: Jul 20, 2023
 *      Author: Ahmed Taha
 */
#include "m_driver.h"

void open(void){
	SET_BIT(DDRC,1);
	CLR_BIT(DDRC,2);
}

void close(void){
	CLR_BIT(DDRC,1);
	SET_BIT(DDRC,2);
}

void stop(void){
	CLR_BIT(DDRC,1);
	CLR_BIT(DDRC,2);
}

