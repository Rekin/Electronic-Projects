/*
 * main.c
 *
 *  Created on: 7 lut 2014
 *      Author: Adam
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define BAUD 9600
#define BAUD_PRESCALLER (((F_CPU / (BAUD * 16UL))) - 1)

//Initialize USART communication.
void USARTInit(){
	UBRR0H = (uint8_t)(BAUD_PRESCALLER>>8);
	UBRR0L = (uint8_t)(BAUD_PRESCALLER);
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	UCSR0C = (1<<UCSZ00) | (1<<UCSZ01);
}

//Watch for the incoming data.
unsigned char USARTReceive(){
	while(!(UCSR0A & (1<<RXC0)));
	return UDR0;
}

//Send data by USART to listener.
void USARTSend(unsigned char data){
	while(!(UCSR0A & (1<<UDRE0)));
	UDR0 = data;
}

//Send complex string message by USART.
void USARTSendMessage(char* message){
	while(*message!='\0'){
		USARTSend(*message);
		message++;
	}
}

//Main program loop.
void MainProgramLoop(){
	while(1){
		USARTSendMessage("ABCDEFGHIJKLMNOPRSTUWXYZ");
		_delay_ms(5000);
	}
}

//main function
int main (void)
{
	USARTInit();
	MainProgramLoop();
}
