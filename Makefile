# use g++ as compiler
CC = g++

# add debugging info and compiler warnings
CFLAGS = -c -std=c++17 -Wconversion -Wall -Werror -Wextra -pedantic 

test: test*.o pencil.o
	$(CC) test*.o pencil.o -o test

pencil.o: pencil.cpp
	$(CC) $(CFLAGS) pencil.cpp

test.o:
	$(CC) $(CFLAGS) $(wildcard test*.cpp)

clean:
	rm -f *.o pencil test