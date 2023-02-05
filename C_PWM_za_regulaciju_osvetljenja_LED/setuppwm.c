/*
 * setup_pwm.c
 *
 * Created: 3.1.2023. 21:22:49
 *  Author: user
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

double dutycycle;

void pwmsetup()
{
	TCCR0A = (1 << COM0A1) | (1 << WGM00) | (1 << WGM01);		// Fast PWM, clear OC0A on compare match, set OC0A at bottom
	TCCR0B = (1 << CS00) | (1 << CS02);
	
	TIMSK0 = (1 << TOIE0);
	
	OCR0A = (dutycycle/100.0) * 255;
	
	sei();
}