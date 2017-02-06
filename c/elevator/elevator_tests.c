#include "elevator.h"

void animate(struct elevator *el);

int main(int argc, char *argv[])
{
  struct elevator el;

  elevator_init(&el);
  elevator_set_pickup(&el, 4, DOWN);
  for (int i = 0; i < 10; i++) {
    animate(&el);
    elevator_step(&el);
  }

  printf("\n\n");

  elevator_init(&el);
  elevator_set_pickup(&el, 4, DOWN);
  elevator_set_dropoff(&el, 5);
  for (int i = 0; i < 14; i++) {
    animate(&el);
    elevator_step(&el);
  }

  printf("\n\n");

  elevator_init(&el);
  int pickups[] = {3, 5, 4, 8};
  enum DIRECTION dirs[] = {UP, UP, DOWN, DOWN};
  int dropoffs[] = {3, 9, 4, 11};

  elevator_set_state(&el ,pickups, dirs, sizeof(pickups)/sizeof(pickups[0]),
		     dropoffs, sizeof(dropoffs)/sizeof(dropoffs[0]));
  for (int i = 0; i < 20; i++) {
    animate(&el);
    elevator_step(&el);
  }

  return 0;
}

void animate(struct elevator *el)
{
  /* |x du|x du|[<-]|x   |    | */
  for (int i = 0; i < MAX_FLOORS; i++) {
    if (i == el->floor)
      printf("|[%s]", (el->direction == UP ? "->" : "<-"));
    else
      printf("|%c %c%c",
	     (el->destination_requests[i] ? 'x' : ' '),
	     (el->down_requests[i] ? 'd' : ' '),
	     (el->up_requests[i] ? 'u' : ' '));
  }
  printf("|\n");
}
