/*
 * digit.c
 *
 * Created: 4/2/2025 4:56:49 PM
 *  Author: dspuser
 */ 

#include "digit.h"

void init_digit(){
	DDRA |= 0xFF;
	DDRB |= 0X0F;
}

void display_digit(uint8_t digit){
	PORTA = ~digitmap[digit];
}

void display_4digit(unsigned char digits[]){
	for(int i=0; i<4; i++){
		PORTB = (1<<i);
		display_digit(digits[i]);
		_delay_ms(1);
	}
}

void clear_digit(){	PORTA &= 0x00;}
