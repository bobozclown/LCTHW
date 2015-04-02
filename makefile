CFLAGS=-Wall -g
SOURCES= ex1.c ex3.c ex4.c ex5.c ex6.c
OBJECTS=$(SOURCES:.c=)


all:
	make $(OBJECTS)
clean:
	rm -f $(OBJECTS)

