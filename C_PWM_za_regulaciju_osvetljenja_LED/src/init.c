/*
 * init.c
 *
 * Created: 3.1.2023. 21:30:55
 *  Author: user
 */ 

#include <avr/io.h>

void init()
{
	DDRD |= (1 << PORTD6);
	PORTD |= (1 << PORTD6);
}