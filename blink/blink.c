#include "stm32f4xx.h"
#include <stdint.h>
/*
*
*		AUTHOR :  A Z Z E D I N E  L A K H D A R 
*		FILE : NUCLEO LED BLINKING 
*
*		after a lot of experience with those registers it fanally worked hhh
*
*		DATE : 1 8 / 0 7 / 2 0 2 1
*/
#define DELAY 0xEFFFF
void delay(uint32_t seconds);
int main(){

	RCC->AHB1ENR |= ((uint32_t)11111) ;//activation of clock of gpios
	GPIOA->MODER |= 1<<10;             //General purpose output of pin 5 in port A
	volatile uint32_t led = 1<<5;      // our value of the led
	volatile int i=0;                  //our delay variable 
	for (;;){
		GPIOA->ODR |= led;             //setting the led high
		for (i = 0; i < DELAY; i++);   //delay
		GPIOA->ODR &= ~led;            //setting the led LOW
		for (i = 0; i < DELAY; i++);   //delay
	}
}
