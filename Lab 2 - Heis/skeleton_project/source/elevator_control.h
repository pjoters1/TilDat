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

/**
 * @brief Creates array for orders for internal buttons.
 */
extern int floor_order_internal[];

/**
 * @brief Creates array for orders for external buttons.
 */
extern int floor_order_external[];

/**
 * @brief Combines orders for both internal and external buttons.
 */
extern int orders[];

/**
 * @brief Defines the direction of the motor.
 */
extern int motor_dir;

/**
 * @brief Clears all order lights.
 */
void clear_all_order_lights();

/**
 * @brief Resets the elevator for use. During reset 
 * no orders can be taken.
 */
void reset_elevator();

/**
 * @brief Sets the elevator direction towards the destination
 * floor. @param f is the destination floor.
 */
void move_to(int f);

/**
 * @brief Stops the elevator and opens the door at
 * @param floor.
 */
void stop_elevator(int floor);

/**
 * @brief Makes sure orders @param f are not
 *  repeated in array @param array. The array
 *  has specified size @param size.
 */
int repeat_check(int f, int size, int array[]);

/**
 * @brief Adds an order to the internal array.
 * The order is for floor @param floor.
 */
void add_internal_order(int floor);

/**
 * @brief Adds an order to the external array.
 * The order is for floor @param floor.
 */
void add_external_order(int floor);

/**
 * @brief Adds an order to the main order array.
 * The order is for floor @param floor.
 */
void add_order(int floor);

/**
 * @brief Deletes an order from the internal array.
 * The order is for floor @param floor.
 */
void delete_internal_order(int floor);

/**
 * @brief Deletes an order from the internal array.
 * The order is for floor @param floor.
 */
void delete_external_order(int floor);

/**
 * @brief Deletes an order to the main order array.
 * The order is for floor @param floor.
 */
void delete_order(int floor);

/**
 * @brief Makes elevator follow the main order array.
 */
void follow_order();

/**
 * @brief Deletes all orders. (and system x32)
 */
void clear_all_orders();

#endif
