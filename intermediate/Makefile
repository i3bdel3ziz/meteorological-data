CC=g++
FLAGS=-Wall

all: intermediate

intermediate: main.o data.o
	$(CC) $(FLAGS) -o intermediate data.o main.o
main.o: main.cpp 
	$(CC) $(FLAGS) -c main.cpp
data.o:
	$(CC) $(FLAGS) -c data.cpp
clean:
	rm *.o intermediate
