
CC=g++
FLAGS=-Wall

all:basic

basic: data.o analyze.o
	$(CC) $(FLAGS) -o basic data.o analyze.o

data.o: data.cpp
	$(CC) $(FLAGS) -c data.cpp

analyze.o: analyze.cpp
	$(CC) $(FLAGS) -c analyze.cpp
clean:
	rm *.o basic
