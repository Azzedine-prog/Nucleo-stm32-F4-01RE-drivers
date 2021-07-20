#include "stm32f4xx.h"
#include <stdint.h>
#define DELAY 0xEFFFF
#include "gpios.h"
int main(){	
	volatile int i=0;
	pinMode(0xA5,OUTPUT);
	for (;;){
		digitalWrite(0xA5,HIGH);
		for (i = 0; i < DELAY; i++);
		digitalWrite(0xA5,LOW);
		for (i = 0; i < DELAY; i++);
	}
}
