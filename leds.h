/*
 * leds.h
 *
 *  Created on: Jul 20, 2023
 *      Author: Mega Store
 */

#ifndef HAL_LEDS_H_
#define HAL_LEDS_H_

#include "../LIB/MEM_MAP.h"
#include"../LIB/StdTypes.h"
#include "../Mcal/DIO.h"

#define blue 3
#define green 4
#define red 5
#define yellow 7

void bl(u8 statue);
void gr(u8 statue);
void re(u8 statue);
void ye(u8 statue);


#endif /* HAL_LEDS_H_ */
