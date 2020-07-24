/// @file Gpio.c
/// @author Adham Mohamed
/// @brief Contains implementation of functions related to GPIO

#include "Gpio.h"

void GpioInit()
{
	// Set OC1A (PINB1) as output
	DDRB |= _BV(PINB1);

	// Set OC1B (PINB2) as output
	DDRB |= _BV(PINB2);
}