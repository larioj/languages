#include "elevator_controler.h"

int initalize_elevators()
{
  for(size_t i = 0; i < sizeof(elevators); i++) {
    elevator_init(&elevators[i]);
  }
  return 0;
}

int request_elevator(int elevator_id, int floor, enum DIRECTION direction)
{
  if (elevator_id < 0 || elevator_id >= sizeof(elevators))
    return 0;

  return elevator_set_pickup(&elevators[elevator_id], floor, direction);
}

int set_floor(int elevator_id, int floor)
{
  if (elevator_id < 0 || elevator_id >= sizeof(elevators))
    return 0;
  return elevator_set_dropoff(&elevators[elevator_id], floor);
}

int step()
{
  for (int i = 0; i < sizeof(elevators); i++) {
    elevator_step(&elevators[i]);
  }
  return 0;
}

