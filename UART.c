#include "UART.h"

#define BAUD_PRESCALE (((F_CPU / (9600 * 8UL))) - 1)

void UART_Init()
{
	//Baud Rate
	/* First 8 bits from the BAUD_PRESCALE inside UBRRL and last 4 bits in UBRRH*/
	UBRRH = 0;
	UBRRL = 12;
//	UCSRA = (1<<1);
//	/************************** UCSRB Description **************************
//	 * RXCIE = 0 Disable USART RX Complete Interrupt Enable
//	 * TXCIE = 0 Disable USART Tx Complete Interrupt Enable
//	 * UDRIE = 0 Disable USART Data Register Empty Interrupt Enable
//	 * RXEN  = 1 Receiver Enable
//	 * RXEN  = 1 Transmitter Enable
//	 * UCSZ2 = 0 For 8-bit data mode
//	 * RXB8 & TXB8 not used for 8-bit data mode
//	 ***********************************************************************/
//	UCSRB = (1<<3) | (1<<4);
//
//	/************************** UCSRC Description **************************
//	 * URSEL   = 1 The URSEL must be one when writing the UCSRC
//	 * UMSEL   = 0 Asynchronous Operation
//	 * UPM1:0  = 00 Disable parity bit
//	 * USBS    = 0 One stop bit
//	 * UCSZ1:0 = 11 For 8-bit data mode
//	 * UCPOL   = 0 Used with the Synchronous operation only
//	 ***********************************************************************/
//	UCSRC = (1<<7) | (1<<2) | (1<<1);

	//Normal Speed
	CLR_BIT(UCSRA,1);

	//frame -> parity,stopbits, databits
		/*even parity*/
	CLR_BIT(UCSRC,5);
	CLR_BIT(UCSRC,4);
		/*1 stop bit*/
	CLR_BIT(UCSRC,3);
		/*data bits*/
	SET_BIT(UCSRC,1);
	SET_BIT(UCSRC,2);
	CLR_BIT(UCSRB,2);

	//mode default Asynchronus
	//enable RX
	SET_BIT(UCSRB,4);
	//enable TX
	SET_BIT(UCSRB,3);
}

void UART_Transmit(u8 data)
{
	while(! GET_BIT(UCSRA,5));
	UDR = data;
}


u8 UART_Receive()
{
	/* RXC flag is set when the UART receive data so wait until this
	 * flag is set to one */
	while(BIT_IS_CLEAR(UCSRA,7)){}
	/* Read the received data from the Rx buffer (UDR) and the RXC flag
	   will be cleared after read this data */
    return UDR;
}

void UART_ReceiveStr(char* str)
{
	u8 data =  UART_Receive();
	u8 i = 0;
	str[i] = data;
	i++;
	while(data != '\r') //continue recieve until Enter
	{
		data =  UART_Receive();
		str[i] = data;
		i++;
	}
	str[i] = '\0';
}

void UART_TransmitStr(char* str)
{
	u8 i = 0;
	while(str[i] != '\0')
	{
		while(! GET_BIT(UCSRA,5));
		UDR = str[i];
		i++;
	}
	
}
