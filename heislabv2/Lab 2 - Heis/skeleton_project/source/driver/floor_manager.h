#include <stdio.h>
#include <string.h>


struct Floors {
        int order_direction;
        int order_indicator;
        int floor_indicator;
        int floor_id;
        int order;
    };

struct Floors floor_1;
struct Floors floor_2;
struct Floors floor_3;
struct Floors floor_4;

void create_floors();

void set_order_direction(struct Floors *floor, int direction);

void set_order_indicator(struct Floors *floor, int order_indicator);

void set_floor_indicator(struct Floors *floor, int floor_indicator);