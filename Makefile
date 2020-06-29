OBJS	= main.o
SOURCE	= main.c
HEADER	= 
OUT	= strcmp
CC	 = gcc
FLAGS	 = -g -std=c89 -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.c
	$(CC) $(FLAGS) main.c

clean:
	rm -f $(OBJS) $(OUT)

install:
	cp $(OUT) /usr/bin/

remove:
	rm /usr/bin/$(OUT)
