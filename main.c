/*
 * main.c
 *
 * Created: 4/2/2025 4:01:33 PM
 * Author : dspuser
 */ 

#define F_CPU 14745600UL

#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include <avr/iom16.h>

#include "timer.h"
#include "digit.h"

/*
Connections:
PA0 - SEG A
PA1 - SEG B
PA2 - SEG C
PA3 - SEG D
PA4 - SEG E
PA5 - SEG F
PA6 - SEG G
PA7 - DP

PB0 - CC1
PB1 - CC2
PB2 - CC3
PB3 - CC4
*/

int main(void){
	unsigned char digits[4];
	unsigned int seconds, milliseconds;
	unsigned long ms;

	init_digit();
	timer_init_interrupts();
	sei();

    while(1){
		ms = get_millis();
		seconds = (ms / 1000) % 60; // 0-59 seconds
		milliseconds = ms % 1000; // 0-999 milliseconds
		
		digits[0] = seconds / 10;
		digits[1] = seconds % 10;
		digits[2] = milliseconds / 100;
		digits[3] = (milliseconds /10) % 10;

		display_4digit(digits);			
	}
}


