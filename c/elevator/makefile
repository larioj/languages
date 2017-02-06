CC=gcc
CFLAGS=-std=c99
DEPS = elevator.h elevator_controler.h
OBJ = elevator.o elevator_controler.o elevator_tests.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

elevator_tests: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

test: elevator_tests
	./elevator_tests

.PHONY: clean

clean:
	rm *.o elevator_tests
