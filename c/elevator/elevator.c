#include "elevator.h"

void update_direction(struct elevator *el)
{
  if (el->floor == 0) {
    el->direction = UP;
  } else if (el->floor == MAX_FLOORS - 1) {
    el->direction = DOWN;
  } else if (el->direction == UP) {
    for (int i = el->floor + 1; i < MAX_FLOORS ; i++) {
      if (el->destination_requests[i] ||
	  el->up_requests[i] ||
	  el->down_requests[i]) {
	return;
      }
    }
    el->direction = DOWN;
  } else if (el->direction == DOWN) {
    for (int i = 0; i < el->floor; i++) {
      if (el->destination_requests[i] ||
	  el->up_requests[i] ||
	  el->down_requests[i]) {
	return;
      }
    }
    el->direction = UP;
  }
}

int elevator_step(struct elevator *el)
{
  if (el->direction == DOWN) {
    el->floor--;
    el->down_requests[el->floor] = 0;
  }

  if (el->direction == UP) {
    el->floor++;
    el->up_requests[el->floor] = 0;
  }

  el->destination_requests[el->floor] = 0;
  update_direction(el);

  if (el->direction == DOWN) {
    el->down_requests[el->floor] = 0;
  }

  if (el->direction == UP) {
    el->up_requests[el->floor] = 0;
  }

  return 0;
}


int elevator_init(struct elevator *el)
{
  memset(el, 0, sizeof(*el));
  el->direction = UP;
  return 0;
}

int elevator_set_pickup(struct elevator *el, int floor, enum DIRECTION dir)
{
  if (floor < 0 || floor >= MAX_FLOORS)
    return 0;
  if (dir == UP)
    return ++(el->up_requests[floor]);
  if (dir == DOWN)
    return ++(el->down_requests[floor]);
  return 0;
}

int elevator_set_dropoff(struct elevator *el, int floor)
{
  if (floor < 0 || floor >= MAX_FLOORS)
    return 0;
  return ++(el->destination_requests[floor]);
}

int elevator_set_state(struct elevator *el,
		       int *pickups, enum DIRECTION *dirs, int psize,
		       int *dropoffs, int dsize)
{
  for (int i = 0; i < psize; i++) {
    elevator_set_pickup(el, pickups[i], dirs[i]);
  }
  for (int i = 0; i < dsize; i++) {
    elevator_set_dropoff(el, dropoffs[i]);
  }
  return 0;
}
