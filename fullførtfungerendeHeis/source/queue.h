/**
 * @file
 * @brief Sets orders and controls queue.
 */
#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "hardware.h"
#include "elevator_control.h"
#include "buttons.h"
#include <unistd.h>
#include "timer.h"
#include "door.h"

/**
 * @brief Checks if there is an order at floor 1 or floor 4
 * and prioritizes according to direction of elevator.
 */
void check_extremities();

extern int sensor_floor;

/**
 * @brief The algorithm that decides which direction the
 * elevator should go, and if it should stop.
 */
void queue_algo();

#endif