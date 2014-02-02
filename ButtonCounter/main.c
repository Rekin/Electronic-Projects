/*
 * main.c
 *
 *  Created on: 31 sty 2014
 *      Author: Adam
 */

//ŒWIECENIE LCD 7 SEGMENT!

#include <avr/io.h>
#include <util/delay.h>
#define LED_PORT PORTD
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

//Max number on led segment.
const int MAXIMUM = 9;

void loop();
void _delay_ms_var(uint16_t a);
void showDigit(int);

int main(){
	  DDRD = 0xff;
	  LED_PORT = 0xff;
	  loop();
	  return 0;
}


//Main program loop.
void loop(){
	int counter = 0;

	while(1){
		showDigit(counter);

		if((PINC & (1<<PC0))==1) //Check if button was pressed.
		{
			if(counter>=MAXIMUM)
			{
				counter = 0;
			}
			else{
				counter++;
				_delay_ms_var(3000);
			}
		}
	}
}

//Prepared delay function.
void _delay_ms_var(uint16_t a)
{
  while(a--)
  {
    _delay_ms(1);
  }
}

//Display proper digit by LED_PORT.
void showDigit(int digit){
	if(digit<=MAXIMUM)
	{
		LED_PORT = digits[digit];
	}
}
