/**
 * @file
 * @brief Main control for elevator movement.
 */


#ifndef ELEVATOR_CONTROL_H
#define ELEVATOR_CONTROL_H


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "hardware.h"

extern int floor_order_internal[];

extern int floor_order_external[];

extern int orders[];

extern int motor_dir;

void clear_all_order_lights();

void reset_elevator();

int get_floor();

void move_to(int f);

void stop_elevator(int floor);

int repeat_check(int f, int size, int array[]);

void add_internal_order(int floor);

void add_external_order(int floor);

void add_order(int floor);

void delete_internal_order(int floor);

void delete_external_order(int floor);

void delete_order(int floor);

void follow_internal_order();

void follow_external_order();

void clear_all_orders();

#endif
