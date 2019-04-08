# use g++ as compiler
CC = g++

# add debugging info and compiler warnings
CFLAGS = -c -std=c++17 -Wconversion -Wall -Werror -Wextra -pedantic 

all: pencil test

pencil: main.o pencil.o
	$(CC) main.o pencil.o -o pencil

test: test*.o pencil.o
	$(CC) test*.o pencil.o -o test

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

pencil.o: pencil.cpp
	$(CC) $(CFLAGS) pencil.cpp

test.o:
	$(CC) $(CFLAGS) $(wildcard test*.cpp)

clean:
	rm -f *.o pencil test