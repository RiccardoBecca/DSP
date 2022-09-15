CC = g++
CFLAGS = -Wall -O3 --std=c++11

main.exe : main.o DSG.o
	$(CC) DSG.o main.o -o main.exe
main.o : main.cpp
	$(CC) -c main.cpp -o main.o $(CFLAGS)
DSG.o : DSG.cpp DSG.h
	$(CC) -c DSG.cpp -o DSG.o $(CFLAGS)
clean :
	rm *.o main.exe seed.out
