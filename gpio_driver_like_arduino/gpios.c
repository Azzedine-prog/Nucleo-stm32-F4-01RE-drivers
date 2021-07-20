#include "gpios.h"
#include "stm32f4xx.h"
int A_port[] = {0xA0,0xA1,0xA2,0xA3,0xA4,0xA5,0xA6,0xA7,0xA8,0xA9,0xA10,0xA11,0xA12,0xA13,0xA14,0xA15}
   ,B_port[] = {0xB0,0xB1,0xB2,0xB3,0xB4,0xB5,0xB6,0xB7,0xB8,0xB9,0xB10,0xB11,0xB12,0xB13,0xB14,0xB15}
	 ,C_port[] = {0xC0,0xC1,0xC2,0xC3,0xC4,0xC5,0xC6,0xC7,0xC8,0xC9,0xC10,0xC11,0xC12,0xC13,0xC14,0xC15}
	 ,D_port[] = {0xD0,0xD1,0xD2,0xD3,0xD4,0xD5,0xD6,0xD7,0xD8,0xD9,0xD10,0xD11,0xD12,0xD13,0xD14,0xD15}
	 ,E_port[] = {0xE0,0xE1,0xE2,0xE3,0xE4,0xE5,0xE6,0xE7,0xE8,0xE9,0xE10,0xE11,0xE12,0xE13,0xE14,0xE15};
int check_if_existes(int my_num,int* myarray){
	int i = 16;
	int* tmp = myarray;
	//boolean return_value = False; 
	for(i=0;i<16;i++){
		if(*(tmp+i) == my_num){;
		return i;}
	}
	return i;
}
//configuration of the pin
void init_pin(pin* pin,int num,gpio port,direction direction_of_mypin){
	pin->pin_num = num;
	pin->port = port;
	pin->dir = direction_of_mypin;
}
void configure_pin(pin* pin){
	if(pin->port == gpioa){
		RCC->AHB1ENR |=1 ;
		if(pin->dir == INPUT){
			GPIOA->MODER |= 0<<(2*pin->pin_num);
		}
		else if(pin->dir == OUTPUT){
			GPIOA->MODER |= 1<<(2*pin->pin_num);
		}
		else if(pin->dir == ALTERNATE){
			GPIOA->MODER |= 10<<(2*pin->pin_num);
		}
		else if(pin->dir == ANALOG){
			GPIOA->MODER |= 11<<(2*pin->pin_num);
		}
	}
	else if(pin->port == gpiob){
		RCC->AHB1ENR |=1<<1 ;
		if(pin->dir == INPUT){
			GPIOB->MODER |= 0<<(2*pin->pin_num);
		}
		else if(pin->dir == OUTPUT){
			GPIOB->MODER |= 1<<(2*pin->pin_num);
		}
		else if(pin->dir == ALTERNATE){
			GPIOB->MODER |= 10<<(2*pin->pin_num);
		}
		else if(pin->dir == ANALOG){
			GPIOB->MODER |= 11<<(2*pin->pin_num);
		}
	}
	else if(pin->port == gpioc){
		RCC->AHB1ENR |=1<<2 ;
		if(pin->dir == INPUT){
			GPIOC->MODER |= 0<<(2*pin->pin_num);
		}
		else if(pin->dir == OUTPUT){
			GPIOC->MODER |= 1<<(2*pin->pin_num);
		}
		else if(pin->dir == ALTERNATE){
			GPIOC->MODER |= 10<<(2*pin->pin_num);
		}
		else if(pin->dir == ANALOG){
			GPIOC->MODER |= 11<<(2*pin->pin_num);
		}
	}
	else if(pin->port == gpiod){
		RCC->AHB1ENR |=1<<3 ;
		if(pin->dir == INPUT){
			GPIOD->MODER |= 0<<(2*pin->pin_num);
		}
		else if(pin->dir == OUTPUT){
			GPIOD->MODER |= 1<<(2*pin->pin_num);
		}
		else if(pin->dir == ALTERNATE){
			GPIOD->MODER |= 10<<(2*pin->pin_num);
		}
		else if(pin->dir == ANALOG){
			GPIOD->MODER |= 11<<(2*pin->pin_num);
		}
	}
	else if(pin->port == gpioe){
		RCC->AHB1ENR |=1<<4 ;
		if(pin->dir == INPUT){
			GPIOE->MODER |= 0<<(2*pin->pin_num);
		}
		else if(pin->dir == OUTPUT){
			GPIOE->MODER |= 1<<(2*pin->pin_num);
		}
		else if(pin->dir == ALTERNATE){
			GPIOE->MODER |= 10<<(2*pin->pin_num);
		}
		else if(pin->dir == ANALOG){
			GPIOE->MODER |= 11<<(2*pin->pin_num);
		}
	}
}
//********************* setting pin ****************************************
void digitalWrite_by_pin(pin* pin,status status_tmp){
	if(status_tmp == HIGH){
		if(pin->port == gpioa){
			GPIOA->ODR |=1<<pin->pin_num;
		}
		else if(pin->port == gpiob){
			GPIOB->ODR |=1<<pin->pin_num;
		}
		else if(pin->port == gpioc){
			GPIOC->ODR |=1<<pin->pin_num;
		}
		else if(pin->port == gpiod){
			GPIOD->ODR |=1<<pin->pin_num;
		}
		else if(pin->port == gpioe){
			GPIOE->ODR |=1<<pin->pin_num;
		}
	}
	if(status_tmp == LOW){
		if(pin->port == gpioa){
			GPIOA->ODR &=0<<pin->pin_num;
		}
		else if(pin->port == gpiob){
			GPIOB->ODR ^=0<<pin->pin_num;
		}
		else if(pin->port == gpioc){
			GPIOC->ODR ^=0<<pin->pin_num;
		}
		else if(pin->port == gpiod){
			GPIOD->ODR ^=0<<pin->pin_num;
		}
		else if(pin->port == gpioe){
			GPIOE->ODR ^=0<<pin->pin_num;
		}
	}
}

void pinMode(int pin_char,direction direction_desired){
	pin mypin_value;
	pin* mypin = &mypin_value;
	//********************************************
	if(check_if_existes(pin_char,A_port) != 16){
		init_pin(mypin,check_if_existes(pin_char,A_port),gpioa,direction_desired);
		configure_pin(mypin);
	}
	else if(check_if_existes(pin_char,B_port) != 16){
		init_pin(mypin,check_if_existes(pin_char,B_port),gpiob,direction_desired);
		configure_pin(mypin);
	}
	else if(check_if_existes(pin_char,C_port) != 16){
		init_pin(mypin,check_if_existes(pin_char,C_port),gpioc,direction_desired);
		configure_pin(mypin);
	}
	else if(check_if_existes(pin_char,D_port) != 16){
		init_pin(mypin,check_if_existes(pin_char,D_port),gpiod,direction_desired);
		configure_pin(mypin);
	}
	else if(check_if_existes(pin_char,E_port) != 16){
		init_pin(mypin,check_if_existes(pin_char,E_port),gpioe,direction_desired);
		configure_pin(mypin);
	}
	//*********************************************
}
void digitalWrite(int pin_char,status status_tmp){
	//********************************************
	if(status_tmp == HIGH){
		if(check_if_existes(pin_char,A_port) != 16){
		GPIOA->ODR |=1<<check_if_existes(pin_char,A_port);
	}
	else if(check_if_existes(pin_char,B_port) != 16){
		GPIOB->ODR |=1<<check_if_existes(pin_char,B_port);
	}
	else if(check_if_existes(pin_char,C_port) != 16){
		GPIOC->ODR |=1<<check_if_existes(pin_char,C_port);
	}
	else if(check_if_existes(pin_char,D_port) != 16){
		GPIOD->ODR |=1<<check_if_existes(pin_char,D_port);
	}
	else if(check_if_existes(pin_char,E_port) != 16){
		GPIOE->ODR |=1<<check_if_existes(pin_char,E_port);
	}
	}
	else if(status_tmp == LOW){
		if(check_if_existes(pin_char,A_port) != 16){
		GPIOA->ODR &=0<<check_if_existes(pin_char,A_port);
	}
	else if(check_if_existes(pin_char,B_port) != 16){
		GPIOB->ODR |=0<<check_if_existes(pin_char,B_port);
	}
	else if(check_if_existes(pin_char,C_port) != 16){
		GPIOC->ODR |=0<<check_if_existes(pin_char,C_port);
	}
	else if(check_if_existes(pin_char,D_port) != 16){
		GPIOD->ODR |=0<<check_if_existes(pin_char,D_port);
	}
	else if(check_if_existes(pin_char,E_port) != 16){
		GPIOE->ODR |=0<<check_if_existes(pin_char,E_port);
	}
	}
	
}
