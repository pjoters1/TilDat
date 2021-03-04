#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "hardware.h"
#include "driver/timer.h"

int state_door();

int check_obstrucion();

void door_delay();

void stop_door();