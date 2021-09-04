/*
 * uart1.h
 *
 *  Created on: 10 Jun 2020
 *  Author: Mohamed Osama
 */



#ifndef UART1_H_
#define UART1_H_



#include "micro_config.h"
#include "std_types.h"
#include "commonmacros.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

/* UART Driver Baud Rate */
#define USART_BAUDRATE 9600

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void UART_init(void);

void UART_sendByte(const uint8 data);

uint8 UART_recieveByte(void);

void UART_sendString(const uint8 *Str);

void UART_receiveString(uint8 *Str); // Receive until #

#endif /* UART_H_ */
