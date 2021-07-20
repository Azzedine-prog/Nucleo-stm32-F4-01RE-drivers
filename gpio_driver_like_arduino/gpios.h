//int val_a = 0,val_b = 0,val_c = 0,val_d = 0,val_e = 0;
typedef enum gpio{
gpioa,gpiob,gpioc,gpiod,gpioe
}gpio;
//gpio gpio_array[] = {gpioa,gpiob,gpioc,gpiod,gpioe};
typedef enum status{
HIGH,LOW
}status;
typedef enum direction{
INPUT,OUTPUT,ALTERNATE,ANALOG
}direction;
typedef volatile struct pin{
	int pin_num;
	gpio port;
	direction dir;
}pin;
typedef enum boolean { True,False } boolean;
/*typedef enum pin_char{
A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,
B0,B1,B2,B3,B4,B5,B6,B7,B8,B9,B10,B11,B12,B13,B14,B15,
C0,C1,C2,C3,C4,C5,C6,C7,C8,C9,C10,C11,C12,C13,C14,C15,
D0,D1,D2,D3,D4,D5,D6,D7,D8,D9,D10,D11,D12,D13,D14,D15,
E0,E1,E2,E3,E4,E5,E6,E7,E8,E9,E10,E11,E12,E13,E14,E15
}pin_char;*/
void init_pin(pin* pin,int num,gpio port,direction direction_of_mypin);
void configure_pin(pin* pin);
void digitalWrite_by_pin(pin* pin,status status_tmp);
void pinMode(int pin_char,direction direction_desired);
void digitalWrite(int pin_char,status status_tmp);
