#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "hardware.h"
#include "driver/timer.h"
#include "driver/door.h"
#include "driver/channels.h"

int state_door(){

}

int check_obstrucion(){
    return hardware_read_obstruction_signal();
}

void door_delay(){
    set_timer();
}

void stop_door(){
    switch(get_floor()){
        case 1:
            door_delay();
            break;
        case 2:
            door_delay();
            break;
        case 3:
            door_delay();
            break;
        case 4:
            door_delay();
            break;
    }
}