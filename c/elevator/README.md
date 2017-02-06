# Elevator Control System

## Elevator State
+ Up requests
  * array of size number of floors
+ Down requests
  * array of size number of floors
+ Destination requests
  * array of size number of floors
+ Direction
  * int or enum (better).
+ Current Floor
  * int

The arrays could be bit vectors, but I don't
care for the complexity given that the number
of floors should be relatively small.

## Elevator Overview
The control system keeps track of the up requests
at each floor, the down requests at each floor, and
the pending destination requests. If one thinks of this
as a real elevator, the up and down requests represent
individuals who have pressed the down/up button and
who are waiting at floor x. While the destination requests
represent the destinations of the people already in
the elevator.

The scheduling system is simplistic. When the elevator
reaches floor x, it removes any destination request pending
on that floor, meaning that it assumes all individuals
wanting that floor will get out when the doors open. It then
updates its direction. If it's going in direction a, and there
are destination request or up/down requests for floors in that direction, it will
keep going in that direction. If there are no more destination
requests in that direction, it will go the other direction.

This is a better strategy than FIFO because it provides a higher
quality of service for the riders (the elevator isn't going up
and down randomly). It has a higher resource utilization, meaning
that a multiple riders will be serviced on a single sweep if
it is possible. Finally, it does not allow for starvation; all
requests will eventually be serviced even as new requests arrive.


## To Run
+ make
+ make test

