CC=gcc
CFLAGS=-c -Wall -ggdb
LIB=-lcurses

all: rogl

rogl: main.o geometry.o object.o player.o room.o ui.o input.o
	$(CC) $(LIB) main.o geometry.o  object.o player.o room.o ui.o input.o -o rogl

main.o: main.c 
	$(CC) $(CFLAGS) main.c 

geometry.o: geometry.c
	$(CC) $(CFLAGS) geometry.c

input.o: input.c
	$(CC) $(CFLAGS) input.c

light.o: light.c
	$(CC) $(CFLAGS) light.c

object.o: object.c
	$(CC) $(CFLAGS) object.c 

player.o: player.c
	$(CC) $(CFLAGS) player.c 

room.o: room.c
	$(CC) $(CFLAGS) room.c

ui.o: ui.c
	$(CC) $(CFLAGS) ui.c

clean:
	rm -rf *o rogl

run:
	./rogl
