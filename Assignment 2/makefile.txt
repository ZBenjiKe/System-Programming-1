CC = gcc
AR = ar -rcs
CFLAGS = -Wall -g 

.PHONY: clean all

# Making the o files
main.o: main.c my_mat.h
	$(CC) $(CFLAGS) -fPIC -c main.c

my_mat.o: my_mat.c my_mat.h
	$(CC) $(CFLAGS) -fPIC -c my_mat.c 

# Making the library my_mat
my_mat.a: my_mat.o
	$(AR) my_mat.a my_mat.o
	ranlib my_mat.a 

## Making the main file
connections: my_mat.a main.o
	$(CC) $(CFLAGS) main.o my_mat.a -o connections -lm

all: connections

clean: 
	rm -f *.o *.a connections
