
#include<util/delay.h>
#include"HAL/lcd.h"
#include"Mcal/ADC.h"
#include"HAL/UART.h"
#include"HAL/leds.h"
#include"HAL/m_driver.h"
#include"Mcal/interrupt.h"

#define buz 3

ISR(INT0_vect)
{
	CLR_BIT(PORTD,buz); //toggle led state
}


int main(void){
	//char c[2];
	IN0_Init();
	ADC_Init(AVCC,128);
	LCD_init();
	UART_Init();
	LCD_clearScreen();

	//Initializing buzzer
	SET_BIT(DDRD,buz);

	//Initializing variable that will hold value
	u8 c ;

	//LCD_displayCharacter(c[0]);
	unsigned long temp;
	while (1){

		c=UART_Receive();
		if(c=='t'){
			LCD_displayString("Temperature:");
			temp = (ADC_Read(0)/2)-2;
			LCD_goToRowColumn(1,0);
			LCD_intgerToString(temp);
			if(temp>90){
				SET_BIT(PORTD,buz);
				re(1);
				LCD_clearScreen();
				LCD_displayString("FIRE!!!");
			}
		}
		if(c=='o'){
			bl(0);
			LCD_clearScreen();
			LCD_displayString("Opening Door..");
			open();
			ye(1);
			_delay_ms(1500);
			ye(0);
			stop();
			LCD_clearScreen();
			LCD_displayString("Door is opened");
			gr(1);

		}
		if(c=='c'){
			gr(0);
			LCD_clearScreen();
			LCD_displayString("Closing Door..");
			close();
			ye(1);
			_delay_ms(1500);
			ye(0);
			stop();
			LCD_clearScreen();
			LCD_displayString("Door is Closed");
			bl(1);

		}
		LCD_displayCharacter(c);



		}

}

