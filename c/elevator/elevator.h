#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FLOORS 16

enum DIRECTION
{
  UP,
  DOWN
};

struct elevator
{
  int floor;
  enum DIRECTION direction;
  int up_requests[MAX_FLOORS];
  int down_requests[MAX_FLOORS];
  int destination_requests[MAX_FLOORS];
};

int elevator_step(struct elevator *el);
int elevator_init(struct elevator *el);
int elevator_set_pickup(struct elevator *el, int floor, enum DIRECTION dir);
int elevator_set_dropoff(struct elevator *el, int floor);
int elevator_set_state(struct elevator *el,
		       int *pickups, enum DIRECTION *dirs, int psize,
		       int *dropoffs, int dsize);
