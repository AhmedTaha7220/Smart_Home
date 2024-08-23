


#ifndef UART_H_
#define UART_H_

#include "../LIB/MEM_MAP.h"
#include "../LIB/StdTypes.h"
#include "../Mcal/DIO.h"
#include <avr/io.h>
#define F_CPU 1000000UL
#define USART_BAUDRATE 9600

void UART_Init();

void UART_Transmit(u8 data);

u8 UART_Receive();

void UART_ReceiveStr(char* str);
void UART_TransmitStr(char* str);





#endif /* UART_H_ */
