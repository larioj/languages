#include "elevator.h"

#define MAX_ELEVATORS 16

struct elevator elevators[MAX_ELEVATORS];

int initalize_elevators();
int request_elevator(int elevator_id, int floor, enum DIRECTION direction);
int set_floor(int elevator_id, int floor);
int step();
