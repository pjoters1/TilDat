/**
 * @file
 * @brief Commands for door.
 */

#ifndef DOOR_H
#define DOOR_H


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "hardware.h"
#include "elevator_control.h"
#include <unistd.h>


/**
 * @brief Opens door and hodors for 3 seconds.
 */
void door_open();
/**
 * @brief Turns off indicator for door.
 */
void door_indicator_off();
/**
 * @brief Closes door.
 */
int door_close();

#endif