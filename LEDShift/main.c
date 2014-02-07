/*
 * main.c
 *
 *  Created on: 7 lut 2014
 *      Author: Adam
 */


#include <avr/io.h>
#include <util/delay.h>

#define true "true"
#define false "false"

#define SHIFT_REG DDRB		//Shift registers
#define SHIFT_PORT PORTB	//Shift ports
#define DATA (1<<PB3)		//MASTER OUT SLAVE IN - PL = Dane
#define LATCH (1<<PB2)		//SS				  - PL = Zatrzask
#define CLOCK (1<<PB5)		//SCK				  - PL = Zegar
#define F_CPU 1000000UL

//DIGITS
uint8_t digits[] = {
		0b01111011, //0
		0b01100000, //1
		0b00110111, //2
		0b01110110, //3
		0b01101100, //4
		0b01011110, //5
		0b01011111, //6
		0b01110000, //7
		0b01111111, //8
		0b01111110  //9
};

//Display digit
void DisplayDigit(uint8_t digit){
	SHIFT_PORT &= ~LATCH;
	SPDR = digit;
	while(!(SPSR & (1<<SPIF)));
	SHIFT_PORT |= LATCH;
	_delay_ms(5000);
}

//Shift register initialization
void ShiftInit(){
	//SET SHIFT REGISTER ON
	SHIFT_REG |= (DATA | LATCH | CLOCK);
	SHIFT_PORT &= ~(DATA | LATCH | CLOCK);

	//SET SPI SETTINGS
	SPCR = (1<<SPE) | (1<<MSTR);
}

//MAIN PROGRAM LOOP
void MainProgramLoop(){
	while(true){
		int i = 0;
		for(;i<10;i++)
		{
			DisplayDigit(digits[i]);
		}
	}
}

int main(){
	ShiftInit();
	MainProgramLoop();
}
