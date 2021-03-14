#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "hardware.h"
#include "elevator_control.h"
#include "buttons.h"
#include <unistd.h>
#include "queue.h"



int main(){
    int error = hardware_init();
    if(error != 0){
        fprintf(stderr, "Unable to initialize hardware\n");
        exit(1);
    }
    reset_elevator();
    
    printf("=== Example Program ===\n");
    printf("Press the stop button on the elevator panel to exit\n");

    while(1){
        if(hardware_read_stop_signal()){
            hardware_command_movement(HARDWARE_MOVEMENT_STOP);
            hardware_command_stop_light(1);
            clear_all_order_lights();
            clear_all_orders();
            for(int i = 0; i<4;++i){
                if(hardware_read_floor_sensor(i)){
                    door_open();
                }
            }
        }else{
            hardware_command_stop_light(0);
            /* Code block that makes the elevator go up when it reach the botton
            if(hardware_read_floor_sensor(0)){
                hardware_command_movement(HARDWARE_MOVEMENT_UP);
            }

            Code block that makes the elevator go down when it reach the top floor
            if(hardware_read_floor_sensor(HARDWARE_NUMBER_OF_FLOORS - 1)){
                hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
            }*/

            queue_algo();
            poll_buttons();
            follow_internal_order();
            //follow_external_order();
            //printf("%d", motor_dir);
            /*for(int i = 0; i<6;++i){
                printf("%d",floor_order_external[i]);
            }*/

            /* Code to clear all lights given the obstruction signal */
            /*if(hardware_read_obstruction_signal()){
                hardware_command_stop_light(1);
                clear_all_order_lights();
            }
            else{
                hardware_command_stop_light(0);
            }*/
        }
    }

    return 0;
}
