CFLAGS=-Wall -g
SOURCES= ex1.c ex3.c ex4.c ex5.c ex6.c ex7.c ex8.c ex9.c ex10.c ex11.c ex12.c ex13.c ex14.c ex15.c ex16.c ex17.c
OBJECTS=$(SOURCES:.c=)


all:
	make $(OBJECTS)
clean:
	rm -f $(OBJECTS)

