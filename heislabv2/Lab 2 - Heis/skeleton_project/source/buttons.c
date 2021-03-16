#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "hardware.h"
#include "elevator_control.h"
#include "buttons.h"
#include <unistd.h>

int floora = 0;

void poll_buttons(){
            /* Lights are set and cleared like this: */
        for(int f = 0; f < HARDWARE_NUMBER_OF_FLOORS; f++){
            /* Internal orders */
            if(hardware_read_order(f, HARDWARE_ORDER_INSIDE)){
                hardware_command_order_light(f, HARDWARE_ORDER_INSIDE, 1);
                floora = f;
                for (int i = 0; i < 4; i++){
                    if(floor_order_internal[i] == -1){
                        add_internal_order(floora);
                        i = 4;
                    }
                }
                
                //sleep(1);
                //move_to(floor);
            }
            

            /* Orders going up */
            if(hardware_read_order(f, HARDWARE_ORDER_UP)){
                hardware_command_order_light(f, HARDWARE_ORDER_UP, 1);
                floora = f;
                for (int i = 0; i < 6; i++){
                    if(floor_order_external[i]==-1){
                        add_external_order(((floora+1)*10)+1);
                        i=6;
                    }
                }
            }

            /* Orders going down */
            if(hardware_read_order(f, HARDWARE_ORDER_DOWN)){
                hardware_command_order_light(f, HARDWARE_ORDER_DOWN, 1);
                floora = f;
                for (int i = 0; i < 6; i++){
                    if(floor_order_external[i]==-1){
                        add_external_order((floora+1)*10);
                        i=6;
                    }
                }
            }
        }
        //stop_elevator(floor);
}