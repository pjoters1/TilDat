/**
 * @file
 * @brief Time commands for elevator.
 */
#ifndef TIMER_H
#define TIMER_H

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "hardware.h"
#include "time.h"
/**
 * @brief Sets timer in milliseconds.
 */
void set_timer();

/**
 * @brief Checks if the time limit is reached.
 * @param ms_limit is the selected time limit in milliseconds.
 * @return 1 if true. 0 Otherwise.
 */
int get_timer(int ms_limit);

/**
 * @brief Resets the timer to 0.
 */
void reset_timer();

#endif