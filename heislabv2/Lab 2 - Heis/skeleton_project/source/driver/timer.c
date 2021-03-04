#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "hardware.h"

time_t start_time;

void set_timer(){
    time_t start_time = time(NULL);
    time_t latest_time;
}

int get_timer(){
    time_t latest_time = time(NULL);
    return((latest_time-start_time)>3);
}

void reset_timer(){
    start_time = 0;
}