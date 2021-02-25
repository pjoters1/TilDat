#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "hardware.h"
#include "driver/timer.h"
#include "driver/door.h"

int state_door(){

}

int check_obstrucion(){

}

void door_delay(){
    start_timer();
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