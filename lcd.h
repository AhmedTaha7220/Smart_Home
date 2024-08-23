 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.h
 *
 * Description: Header file for the LCD driver
 *
 * 
 *
 *******************************************************************************/

#ifndef LCD_H_
#define LCD_H_

#include "../LIB/MEM_MAP.h"
#include "../Mcal/DIO.h"
#include<util/delay.h>
#include <stdlib.h> //For using the function 'itoa'


/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
/* LCD HW Pins */
#define RS 4
#define RW 5
#define E  6
#define LCD_CTRL_PORT PORTD
#define LCD_CTRL_PORT_DIR DDRD

#define LCD_DATA_PORT PORTB
#define LCD_DATA_PORT_DIR DDRB

/* LCD Commands */
#define CLEAR_COMMAND 0x01
#define TWO_LINE_LCD_Eight_BIT_MODE 0x38
#define CURSOR_OFF 0x0C
#define CURSOR_ON 0x0E
#define SET_CURSOR_LOCATION 0x80 

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void LCD_sendCommand(unsigned int command);
void LCD_displayCharacter(unsigned int data);
void LCD_displayString(const char *Str);
void LCD_init(void);
void LCD_clearScreen(void);
void LCD_displayStringRowColumn(unsigned int row,unsigned int col,const char *Str);
void LCD_goToRowColumn(unsigned int row,unsigned int col);
void LCD_intgerToString(int data);

#endif /* LCD_H_ */
