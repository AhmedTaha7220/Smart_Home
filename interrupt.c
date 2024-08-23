/*
 * interrupt.c
 *
 *  Created on: Jul 20, 2023
 *      Author: Mega Store
 */
#include "interrupt.h"
void INT0_Init(void)
{
	SREG  &= ~(1<<7);                   // Disable interrupts by clearing I-bit
	DDRD  &= (~(1<<2));               // Configure INT0/PD2 as input pin
	EIMSK  |= (1<<INT0);                 // Enable external interrupt pin INT0
	EICRA |= (1<<ISC00) | (1<<ISC01);   // Trigger INT0 with the raising edge
	SREG  |= (1<<7);                    // Enable interrupts by setting I-bit
}

