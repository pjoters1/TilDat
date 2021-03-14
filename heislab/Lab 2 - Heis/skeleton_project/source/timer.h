#ifndef TIMER_H
#define TIMER_H

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "hardware.h"
#include "time.h"

void set_timer();

int get_timer(int ms_limit);

void reset_timer();

#endif