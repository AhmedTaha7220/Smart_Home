/*
 * m_driver.h
 *
 *  Created on: Jul 20, 2023
 *      Author: Mega Store
 */

#ifndef HAL_M_DRIVER_H_
#define HAL_M_DRIVER_H_

#include "../LIB/MEM_MAP.h"
#include"../LIB/StdTypes.h"
#include "../Mcal/DIO.h"

void open(void);
void close(void);
void stop(void);

#endif /* HAL_M_DRIVER_H_ */
