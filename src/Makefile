CC = gcc
OBJS = main.c big_generator.c defs.h
EXE = spacefreighter
INCL = -I C:\SDL2-devel-2.0.8\SDL2-2.0.8\i686-w64-mingw32\include -L C:\SDL2-devel-2.0.8\SDL2-2.0.8\i686-w64-mingw32\lib -lmingw32 -lSDL2main -lSDL2 -mwindows

all : $(OBJS) 
	$(CC) $(OBJS) $(INCL) -o $(EXE)