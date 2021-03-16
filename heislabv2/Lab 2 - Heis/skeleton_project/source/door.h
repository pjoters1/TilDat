#ifndef DOOR_H
#define DOOR_H


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "hardware.h"
#include "elevator_control.h"
#include <unistd.h>

void door_open();

void door_indicator_off();

int door_close();

#endif