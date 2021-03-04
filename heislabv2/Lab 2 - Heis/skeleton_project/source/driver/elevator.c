#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "hardware.h"
#include "driver/timer.h"
#include "driver/elevator.h"

int get_floor(){
    for(int i; i<5;i++){
        if(hardware_read_floor_sensor(i)){
            return i;
            i = 5;
        }
    }
}
