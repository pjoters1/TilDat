#include <stdio.h>
#include <string.h>
#include "floor_manager.h"



void set_order_direction(struct Floors *floor, int direction){
    floor->order_direction = direction;
}

void set_order_indicator(struct Floors *floor, int new_order_indicator){
    floor->order_indicator = new_order_indicator;
}

void set_floor_indicator(struct Floors *floor, int new_floor_indicator){
    floor->floor_indicator = new_floor_indicator;
}

void create_floors(){

    floor_1.floor_id, 1;
    floor_1.floor_indicator, 0;
    floor_1.order_direction, 0;
    floor_1.order_indicator, 0;
    floor_1.order, 0;

    floor_2.floor_id, 2;
    floor_2.floor_indicator, 0;
    floor_2.order_direction, 0;
    floor_2.order_indicator, 0;
    floor_2.order, 0;

    floor_3.floor_id, 3;
    floor_3.floor_indicator, 0;
    floor_3.order_direction, 0;
    floor_3.order_indicator, 0;
    floor_3.order, 0;

    floor_4.floor_id, 4;
    floor_4.floor_indicator, 0;
    floor_4.order_direction, 0;
    floor_4.order_indicator, 0;
    floor_4.order, 0;
    
}