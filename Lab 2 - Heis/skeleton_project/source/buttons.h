/**
 * @file
 * @brief Commands for buttons.
 */

#ifndef BUTTONS_H
#define BUTTONS_H


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "hardware.h"
#include "elevator_control.h"
#include <unistd.h>

/**
 * @brief Polls all buttons and adds orders to queue.
 */

void poll_buttons();

#endif