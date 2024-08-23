#include "../LIB/MEM_MAP.h"
/*
 * '../' means go back from that folder and if there are 2 folders that you
 * want to get out of them write two like that '../../'
 */

#ifndef DIO_H_
#define DIO_H_
//=======================================================
//Bitwise operations
#define CLR_BIT(REG,PIN) (REG=REG & ~(1<<PIN))
#define SET_BIT(REG,PIN) (REG=REG | (1<<PIN))
#define TOG(REG,PIN) (REG=REG ^ (1<<PIN))
#define GET_BIT(REG,PIN) (REG & (1<<PIN))
#define BIT_IS_CLEAR(REG,PIN) (!(REG & (1<<PIN)))

#define DIO_PORTB 0
#define DIO_PORTC 1
#define DIO_PORTD 2

#define BIN0 0
#define BIN1 1
#define BIN2 2
#define BIN3 3
#define BIN4 4
#define BIN5 5
#define BIN6 6
#define BIN7 7

#define INPUT 0
#define OUTPUT 1
#define HIGH 1
#define LOW 0

void DIO_Digital_write(char PORT,char PIN,char VALUE);
void DIO_InitPort(char port,char direction);
char DIO_Digital_Read(char port,char pin);
void DIO_Init_pin(char PORT,char PIN,char MODE);

#endif
