#include <timer.c>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "hardware.h"

time_t start_time;

void set_timer();

int get_timer();

void reset_timer();
