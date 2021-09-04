/*
 * weed.c
 *
 *  Created on: 19 Aug 2020
 *  Author: Mohamed Osama
 */

#include "uart0.h"
#include "lcd.h"
int main(void) {
	uint8 data;
	UART_init();
	LCD_init(); /* initialize LCD */
	PORTD &= (~(1 << PD7)); //relay off
	PORTD = PORTD & (~(1 << PD6));    // LED OFF
	PORTD &= (~(1 << PD4));    //relay off
	PORTD = PORTD & (~(1 << PD5));    // LED OFF
	PORTA &= (~(1 << PA3));    //relay off
	PORTD = PORTD & (~(1 << PD2));    // LED OFF
	PORTA &= (~(1 << PA4));    //relay off
	PORTD = PORTD & (~(1 << PD3));    // LED OFF
	DDRD = DDRD | (1 << PD6); //configure pin 6 in PORTD as output pin
	DDRD = DDRD | (1 << PD5); //configure pin 5 in PORTD as output pin
	DDRD = DDRD | (1 << PD4); //configure pin 4 in PORTD as output pin
	DDRD = DDRD | (1 << PD7); //configure pin 7 in PORTD as output pin
	DDRD = DDRD | (1 << PD2); //configure pin 2 in PORTC as output pin
	DDRD = DDRD | (1 << PD3); //configure pin 3 in PORTC as output pin
	DDRC = DDRC | (1 << PC4); //configure pin 3 in PORTC as output pin
	DDRC = DDRC | (1 << PC5); //configure pin 3 in PORTC as output pin
	DDRC = DDRC | (1 << PC6); //configure pin 3 in PORTC as output pin
	DDRC = DDRC | (1 << PC7); //configure pin 3 in PORTC as output pin
	DDRA = DDRA | (1 << PA3); //configure pin 1 in PORTB as output pin
	DDRA = DDRA | (1 << PA4); //configure pin 3 in PORTB as output pin
	DDRB = DDRB | (1 << PB3); //configure pin 3 in PORTB as output pin
	DDRB = DDRB | (1 << PB2); //configure pin 3 in PORTB as output pin
	DDRB = DDRB | (1 << PB1); //configure pin 3 in PORTB as output pin
    char b=1;
    LCD_clearScreen(); /* clear the LCD display */
   	LCD_displayString("Not in Range");
	while (1)

	{
		data = UART_recieveByte(); //Receive Byte from Terminal1
		//LCD_clearScreen(); /* clear the LCD display */
		//LCD_displayString("Not in Range");
		switch (data) {
		case ('a'):
			PORTD |= ((1 << PD7)); //relay on
			PORTD = PORTD | (1 << PD6); //LED ON
			LCD_clearScreen(); /* clear the LCD display */
			LCD_displayString("valve 1 ON");
             _delay_ms(450);
             LCD_clearScreen(); /* clear the LCD display */
             b=0;
			break;
		case ('b'):
			PORTD |= ((1 << PD4)); //relay on
			PORTD = PORTD | (1 << PD5); //LED ON
			LCD_clearScreen(); /* clear the LCD display */
			LCD_displayString("valve 2 ON");
			 _delay_ms(450);
			 LCD_clearScreen(); /* clear the LCD display */
			 b=0;
			break;
		case ('c'):
			PORTA |= ((1 << PA3)); //relay on
			PORTD = PORTD | (1 << PD2); // LED ON
			LCD_clearScreen(); /* clear the LCD display */
			LCD_displayString("valve 3 ON");
			 _delay_ms(450);
			 LCD_clearScreen(); /* clear the LCD display */
			 b=0;
			break;
		case ('d'):
			PORTA |= ((1 << PA4)); //relay on
			PORTD = PORTD | (1 << PD3); // LED ON
			LCD_clearScreen(); /* clear the LCD display */
			LCD_displayString("valve 4 ON");
			 _delay_ms(450);
			 LCD_clearScreen(); /* clear the LCD display */
			 b=0;
			break;
		case ('e'):
			//LCD_clearScreen(); /* clear the LCD display */
			//LCD_displayString("Not in Range");
			//LCD_clearScreen(); /* clear the LCD display */
					if(b==0){
						LCD_displayString("Not in Range");
						b++;
					}
			PORTD &= (~(1 << PD7)); //relay off
			PORTD = PORTD & (~(1 << PD6));    // LED OFF
			PORTD &= (~(1 << PD4));    //relay off
			PORTD = PORTD & (~(1 << PD5));    // LED OFF
			PORTA &= (~(1 << PA3));    //relay off
			PORTD = PORTD & (~(1 << PD2));    // LED OFF
			PORTA &= (~(1 << PA4));    //relay off
			PORTD = PORTD & (~(1 << PD3));    // LED OFF
			break;

		}
	}
}

