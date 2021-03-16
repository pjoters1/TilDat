#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "hardware.h"
#include "elevator_control.h"
#include "buttons.h"
#include <unistd.h>
#include "timer.h"
#include "door.h"

int floors[4] = {1,2,3,4};

int floor_order_internal[4] = {-1, -1, -1, -1};

int floor_order_external[6] = {-1, -1, -1, -1, -1, -1};

int orders[4] = {-1, -1, -1, -1};

int motor_dir;

int last_floor;

void clear_all_order_lights(){
    HardwareOrder order_types[3] = {
        HARDWARE_ORDER_UP,
        HARDWARE_ORDER_INSIDE,
        HARDWARE_ORDER_DOWN
    };

    for(int f = 0; f < HARDWARE_NUMBER_OF_FLOORS; f++){
        for(int i = 0; i < 3; i++){
            HardwareOrder type = order_types[i];
            hardware_command_order_light(f, type, 0);
        }
    }
}

void reset_elevator(){
    clear_all_order_lights();
    while(1){
        if(hardware_read_floor_sensor(0)){
            hardware_command_movement(HARDWARE_MOVEMENT_STOP);
            last_floor = 0;
            break;
        }else{
            hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
            motor_dir = 0;
        }
    }
}

void move_to(int f){
    if(door_close()){
        int current_floor = last_floor;
        if(f > current_floor){
            hardware_command_movement(HARDWARE_MOVEMENT_UP);
            motor_dir = 1;
        }else if(f < current_floor){
            hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
            motor_dir = 0;
        }else{
            hardware_command_movement(HARDWARE_MOVEMENT_STOP);
        }
    }
}

void stop_elevator(int floor){
    door_indicator_off();
    if(hardware_read_floor_sensor(floor)){
        door_open();
        hardware_command_movement(HARDWARE_MOVEMENT_STOP);
        last_floor = floor;
        hardware_command_order_light(floor, HARDWARE_ORDER_INSIDE, 0);
        hardware_command_order_light(floor, HARDWARE_ORDER_DOWN, 0);
        hardware_command_order_light(floor, HARDWARE_ORDER_UP, 0);
        delete_internal_order(floor);
        delete_external_order(floor);
        delete_order(floor);
    }
}

int repeat_check(int f, int size, int array[]){
    for(int j = 0; j<size; ++j){
        if(array[j] == f){
            return 0;
        }
    }
    return 1;
}

void add_internal_order(int floor){
    for(int i = 0; i<4; ++i){
        if((floor_order_internal[i] == -1) && (repeat_check(floor, 4, floor_order_internal))){
            floor_order_internal[i] = floor;
            add_order(floor);
            i = 4;
        }
    }
}

void add_external_order(int floor){
    for(int i = 0; i<6; ++i){
        if((floor_order_external[i] == -1) && (repeat_check(floor, 6, floor_order_external))){
            floor_order_external[i] = floor;
            if(floor%10 == 0){
                add_order(((floor)/10)-1);
            }else{
                add_order(((floor-1)/10)-1);
            }
            i = 6;
        }
    }
}

void add_order(int floor){
    for(int i = 0; i<4; ++i){
        if((orders[i] == -1) && (repeat_check(floor, 4, orders))){
            orders[i] = floor;
            i = 4;
        }
    }
}

void clear_all_orders(){
    for(int k = 0; k<4; k++){
        floor_order_internal[k] = -1;
        orders[k] = -1;
    }
    for(int l = 0; l<4; l++){
        floor_order_external[l] = -1;
    }
}


void delete_internal_order(int floor){
    for(int i = 0; i<4;++i){
        if(floor_order_internal[i] == floor){
            floor_order_internal[i] = -1;
            i = 4;
        }
    }
}

void delete_external_order(int floor){
    for(int i = 0; i<6;++i){
        if(floor_order_external[i] == (floor+1)*10){
            floor_order_external[i] = -1;
        }
        if(floor_order_external[i] == ((floor+1)*10)+1){
            floor_order_external[i] = -1;
        }
    }
}

void delete_order(int floor){
    for(int i = 0; i<4;++i){
        if(orders[i] == floor){
            orders[i] = -1;
            i = 4;
        }
    }
}

void follow_order(){
    int destination_floor;
    for(int i = 0; i<4;++i){
        if(orders[i] != -1){
            destination_floor = orders[i];
            move_to(destination_floor);
            break;
        }
    }
    stop_elevator(destination_floor);
}


