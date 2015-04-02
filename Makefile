CFLAGS=-Wall -g
SOURCES=ex1.c ex3.c
OBJECTS=$(SOURCES:.c=.o)


all:
	make $(OBJECTS)
clean:
	rm -f *.o

