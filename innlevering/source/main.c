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
    
    printf("=== The cool Elevator program ===\n");
    printf("Press the ctrl z button to exit\n");

    while(1){
        if(hardware_read_stop_signal()){
            stop_signal_activated();
        }else{
            hardware_command_stop_light(0);

            queue_algo();
            poll_buttons();
            follow_order();
        }
    }

    return 0;
}
