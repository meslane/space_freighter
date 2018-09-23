CC = gcc
CFLAGS = -Wall
OBJS = main.o terrain_generator.o lang_generator.o rng.o
PROG = wengine

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(PROG)
	
main.o: main.c terrain_generator.h lang_generator.h defs.h
	$(CC) $(CFLAGS) -c main.c
	
terrain_generator.o: terrain_generator.c defs.h rng.h
	$(CC) $(CFLAGS) -c terrain_generator.c
	
lang_generator.o: lang_generator.c defs.h rng.h
	$(CC) $(CFLAGS) -c lang_generator.c
	
rng.o: rng.c defs.h
	$(CC) $(CFLAGS) -c rng.c