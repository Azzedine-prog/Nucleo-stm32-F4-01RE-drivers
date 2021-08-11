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
#define DELAY 0xDEEFF
void set_clock_to_75Mhz(void);
//void delay(uint32_t seconds);
void set_clock_to_75Mhz(void){
	//making sure PLL is disabled
	RCC->CR &= (uint32_t)~(1<<24);
	
	//enabling internal clock source
	RCC->CR |= 1;
	
	//waiting for it to be ready
	while(!(RCC->CR & 0x2));
	
	//making HSI PLL clock_source
	RCC->PLLCFGR &= (uint32_t) ~(1<<22);
	
	//setting n = 12c,m = 10,p = 4 for 75
	
	//n=0x12c
	RCC->PLLCFGR |= 0x12c<<6;
	//RCC->PLLCFGR &=(uint32_t) ~(0x12c<<6);
	
	//m=0x10
	RCC->PLLCFGR |= 0x10;
	//RCC->PLLCFGR  &=(uint32_t) ~(0x10);
	
	//p=0x4
	RCC->PLLCFGR |= 0x4<<16;
	//RCC->PLLCFGR &=(uint32_t) ~(0x4<<16);
	
	//enabling PLL
	RCC->CR |= 1<<24;
	while(!((RCC->CR) & (1<<25)));
	
	//waiting for PLL to stabilise
	//RCC->PLLCFGR &= (uint32_t) ~(1<<22);
	RCC->CFGR |= 0x5<<13;
	RCC->CFGR |= 0x5<<10;
	
}
int main(){
	set_clock_to_75Mhz();
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
