CC = gcc
CFLAGS = -Wall
objects = main.o Lista.o

executa: main
	./main
	
main: Lista.o main.c
	$(CC) -o main Lista.o main.c
	
Lista.o: Lista.c Lista.h
	$(CC) -c Lista.c
	
clean:
	rm main $(objects)
