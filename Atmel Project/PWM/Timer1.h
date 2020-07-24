/// @file Timer1.h
/// @author Adham Mohamed
/// @brief Contains definition of functions related to Timer1

#ifndef TIMER1_H_
#define TIMER1_H_

#include <avr/io.h>
#include <avr/common.h>
#include <avr/interrupt.h>

/// # Timer 1 Initialization
/// 
/// ## Initializes the Timer1 peripheral
/// - The Timer1 is in phase correct PWM mode
/// - ICR1 contains the top value
/// - OC1A output PWM signal with frequency of 5000Hz
/// - OC1B output PWM signal with frequency of 5000Hz complementary to OC1A
/// - There's a dead-time of 10us
void Timer1Init();

#endif /* TIMER1_H_ */