#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "hardware.h"
#include "driver/timer.h"
#include "driver/door.h"
#include "driver/elevator.h"
#include "driver/elevator_control.h"
#include "driver/floor_manager.h"
#include "queue.h"

int current_floor_direction(){
    switch(get_floor()){
        case 1:
            return floor_1.order_direction;
            break;
        case 2:
            return floor_2.order_direction;
            break;
        case 3:
            return floor_3.order_direction;
            break;
        case 4:
            return floor_4.order_direction;
            break;
    }
}


void reset_elevator(){
    while(1){
        for(int i = 0; i<4;++i){
            if((hardware_read_floor_sensor(i) == 0) || (hardware_read_floor_sensor != 1)){
                hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
            }else{
                hardware_command_movement(HARDWARE_MOVEMENT_STOP);
                i = 4;
            }
        }
    }
}

void check_floor(){
    if(check_order()){
        int direction = get_direction();
        hardware_command_movement(HARDWARE_MOVEMENT_STOP);
        stop_door();

        if(hardware_read_floor_sensor(4)){
            direction = 0;
        }else if(hardware_read_floor_sensor(1)){
            direction = -1;
    }
        if(direction == 1){
            hardware_command_movement(HARDWARE_MOVEMENT_UP);
        }else if(direction == 0){
            hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
        }else{
            hardware_command_movement(HARDWARE_MOVEMENT_STOP);
        }
    }
}

void start_elevator(){

}


void run_elevator(){
    reset_elevator();
    while(1){
        if(hardware_read_stop_signal()){
            hardware_command_movement(HARDWARE_MOVEMENT_STOP);
            break;
        }
        check_floor();
        start_elevator();
    }
}











/*for(int f = 0; f < HARDWARE_NUMBER_OF_FLOORS; f++){
            if(hardware_read_floor_sensor(f)){
                hardware_command_floor_indicator_on(f);
            }
        }*/

/*void floor_control(){
    switch(get_floor()){
            case 1:
                hardware_command_floor_indicator_on(1);
                door_delay();
                break;
            case 2:
                hardware_command_floor_indicator_on(2);
                door_delay();
                break;
            case 3:
                hardware_command_floor_indicator_on(3);
                door_delay();
                break;
            case 4:
                hardware_command_floor_indicator_on(4);
                door_delay();
                break;
        }
}*/