#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "hardware.h"
#include "queue.h"
#include "io.h"
#include "channels.h"
#include "elevator_control.h"

#include <comedilib.h>

int get_direction(){
    int direction = io_read_bit(MOTORDIR);
}
int check_order(){
    if(current_floor_direction() == get_direction()){
        return 1;
    }else{
        return 0;
    }
}

void new_order(struct Floors edit_floor, int direction){

}