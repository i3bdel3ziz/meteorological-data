CC=g++
FLAGS=-Wall

all:   main.o
	$(CC) $(FLAGS)  -o advanced main.o data.o gnuplot_i.hpp
main.o: main.cpp data.o 
	$(CC) $(FLAGS) -c main.cpp	
data.o: data.cpp 
	$(CC) $(FLAGS)  -c  data.cpp
gnuplot_i.o: gnuplot_i.hpp
	$(CC) $(FLAGS) -c  gnuplot_i.hpp -o gnuplot_i.o
clean:
	rm *.o advanced
