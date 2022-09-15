CC = g++
CFLAGS = -Wall -O3 --std=c++11

main.exe : main.o DSG.o graph_generator.o
	$(CC) DSG.o main.o graph_generator.o -o main.exe
main.o : main.cpp
	$(CC) -c main.cpp -o main.o $(CFLAGS)
DSG.o : DSG.cpp DSG.h
	$(CC) -c DSG.cpp -o DSG.o $(CFLAGS)
graph_generator.o : graph_generator.cpp graph_generator.h
	$(CC) -c graph_generator.cpp  -o graph_generator.o $(CFLAGS)
clean :
	rm *.o main.exe seed.out
