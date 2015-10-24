CC=gcc
CFLAGS=-c -Wall -ggdb
LIB=-lcurses

all: rogl

rogl: main.o geometry.o object.o player.o room.o
	$(CC) $(LIB) main.o geometry.o  object.o player.o room.o -o rogl

main.o: main.c 
	$(CC) $(CFLAGS) main.c 

geometry.o: geometry.c
	$(CC) $(CFLAGS) geometry.c

light.o: light.c
	$(CC) $(CFLAGS) light.c

object.o: object.c
	$(CC) $(CFLAGS) $(LIB) object.c 

player.o: player.c
	$(CC) $(CFLAGS) $(LIB) player.c 

room.o: room.c
	$(CC) $(CFLAGS) $(LIB) room.c 

clean:
	rm -rf *o rogl

run:
	./rogl
