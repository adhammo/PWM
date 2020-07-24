/// @file Gpio.h
/// @author Adham Mohamed
/// @brief Contains definition of functions related to GPIO

#ifndef GPIO_H_
#define GPIO_H_

#include <avr/io.h>

/// # GPIO Initialization
/// 
/// ## Initializes the GPIO pins peripheral
/// ### Initialization Includes:
/// - OC1A as an output pin
/// - OC1B as an output pin
void GpioInit();

#endif /* GPIO_H_ */