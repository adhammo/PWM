/// @file Timer1.c
/// @author Adham Mohamed
/// @brief Contains implementation of functions related to Timer1

#include "Timer1.h"

void Timer1Init()
{
	// Used to store global status register value
	unsigned char sreg;
	
	
	// Set Timer1 in PWM phase correct mode with top set to ICR1 (WGM1[3:0] = 1 0 1 0 [decimal: 10])
	TCCR1A &= ~_BV(WGM10);
	TCCR1A |= _BV(WGM11);
	TCCR1B &= ~_BV(WGM12);
	TCCR1B |= _BV(WGM13);


	// Set Timer1 to no prescaling (CS1[2:0] = 0 0 1 [decimal: 1])
	TCCR1B |= _BV(CS10);
	TCCR1B &= ~_BV(CS11);
	TCCR1B &= ~_BV(CS12);

	
	/* --- Set ICR1 value --- */
	// save global status register value
	sreg = SREG;
	// disable interrupts
	cli();
	// set ICR1 value
	ICR1 = 100;		// TOP = f[clk] / (2 * prescalar * f[PWM]) = 1MHz / (2 * 1 * 5000Hz) = 100 < (2^16 - 1 = 65535)
	// enable interrupts back if it was previously enabled
	SREG = sreg;


	// Set OC1A in inverted mode (set when up-counting and clear when down-counting) (COM1A[1:0] = 1 1 [decimal: 3])
	TCCR1A |= _BV(COM1A0);
	TCCR1A |= _BV(COM1A1);

	// Set OC1A in non inverted mode (clear when up-counting and set when down-counting) (COM1A[1:0] = 1 0 [decimal: 2])
	TCCR1A &= ~_BV(COM1B0);
	TCCR1A |= _BV(COM1B1);
	
	
	/* --- Set OCR1A and OCR1B value --- */
	// save global status register value
	sreg = SREG;
	// disable interrupts
	cli();
	// set OCR1A value
	OCR1A = 45;	// PWM1 = TOP - (duty_cycle + [f(PWM) * dead_time]) * TOP = 100 - (0.5 + [5000 * 0.00001]) * 100 = 45
	// set OCR1B value
	OCR1B = 55;	// PWM2 = TOP - (duty_cycle - [f(PWM) * dead_time]) * TOP = 100 - (0.5 - [5000 * 0.00001]) * 100 = 55
	// enable interrupts back if it was previously enabled
	SREG = sreg;
}
