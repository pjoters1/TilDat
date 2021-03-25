#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "hardware.h"
#include "elevator_control.h"
#include <unistd.h>
#include "timer.h"

void door_open(){
    set_timer();
    hardware_command_door_open(1);
}

void door_indicator_off(){
    if(get_timer(3000)){
        hardware_command_door_open(0);
    }
}

int door_close(){
    if(get_timer(3000)){
        hardware_command_door_open(0);
        return 1;
        reset_timer();
    }else{
        return 0;
    }
}
