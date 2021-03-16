#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "hardware.h"
#include "elevator_control.h"
#include "buttons.h"
#include <unistd.h>
#include "timer.h"
#include "door.h"

int current_floor;

void check_extremeties(){
    if (motor_dir == 0){
        for (int i = 0; i < 4; i++){
            if((orders[i] == 0)){
                int move1 = orders[i];
                int move2 = orders[0];
                orders[i] = move2;
                orders[0] = move1;
            }
        }
    }else if (motor_dir == 1){
        for (int i = 0; i < 4; i++){
            if(orders[i] == 3){
                int move1 = orders[i];
                int move2 = orders[0];
                orders[i] = move2;
                orders[0] = move1;
            }
        }
    }
}

void queue_algo(){
    /* All buttons must be polled, like this: */
        for(int f = 0; f < HARDWARE_NUMBER_OF_FLOORS; f++){
            if(hardware_read_floor_sensor(f)){
                hardware_command_floor_indicator_on(f);
                current_floor = f;
                check_extremeties();
                for(int i = 0; i<4; ++i){
                    if(current_floor==orders[i]){
                        if (current_floor == floor_order_internal[i]){
                            stop_elevator(current_floor);
                        }else{
                            for(int j = 0; j<6; ++j){
                                if((floor_order_external[j] == ((current_floor+1)*10))||(floor_order_external[j] == ((current_floor+1)*10+1))){
                                    if(motor_dir == (floor_order_external[j]%10)){
                                        stop_elevator(current_floor);
                                    }
                                }
                            }
                        } 
                    }
                }
            }
        }
}