CC = gcc
CFLAGS = -Wall -I C:\SDL2-devel-2.0.8\SDL2-2.0.8\i686-w64-mingw32\include -L C:\SDL2-devel-2.0.8\SDL2-2.0.8\i686-w64-mingw32\lib -lmingw32 -lSDL2main -lSDL2 -mwindows
OBJS = main.o big_generator.o 
PROG = spacefreighter

all: $(PROG)

$(PROG): main.o big_generator.o
	$(CC) $(CFLAGS) $(OBJS) -o $(PROG)

main.o: main.c big_generator.h defs.h
	$(CC) $(CFLAGS) -c main.c
	
big_generator.o: big_generator.c big_generator.h defs.h
	$(CC) $(CFLAGS) -c big_generator.c