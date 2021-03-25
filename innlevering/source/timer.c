#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "hardware.h"
#include "time.h"
#include "timer.h"

int ms_now;
int ms_latest;

void set_timer(){
    ms_now = clock() * 1000 / CLOCKS_PER_SEC;
}

int get_timer(int ms_limit){
    if((hardware_read_obstruction_signal())||(hardware_read_stop_signal())){
        reset_timer();
        set_timer();
    }
    ms_latest = clock() * 1000 / CLOCKS_PER_SEC;
    if(ms_latest>=ms_now+ms_limit){
        return 1;
    }else{
        return 0;
    }
}

void reset_timer(){
    ms_now = 0;
    ms_latest = 0;
}