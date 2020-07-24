/// @file main.c
/// @author Adham Mohamed
/// @brief Contains main entry of program

/// Internal RC oscillator frequency = 8MHz
/// Clock frequency = 1MHz - because CKDIV8 is set

#include "Gpio.h"
#include "Timer1.h"

/// # Main Entry
/// 
/// ## Program execution starts by this function.
int main()
{
	GpioInit();
	Timer1Init();

    while (1)
    {
    }
}

