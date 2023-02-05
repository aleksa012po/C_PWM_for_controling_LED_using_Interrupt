/*
 * C_PWM_za_regulaciju_osvetljenja_LED.c
 *
 * Created: 3.1.2023. 21:19:42
 * Author : Aleksandar Bogdanovic
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "init.h"
#include "setuppwm.h"

extern double dutycycle = 0;

int main(void)
{
    init();
	pwmsetup();
	
    while (1) 
    {
		_delay_ms(200);		
		dutycycle += 5;
		
		if (dutycycle >= 100)
		{
			dutycycle = 0;
		}
	}
}
			
ISR(TIMER0_OVF_vect)
{
	OCR0A =(dutycycle/100.0)*255;
}