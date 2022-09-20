CC = gcc
CFLAGS = -Wall
objects = main.o Fila.o

main: Fila.o main.c
	$(CC) -o main Fila.o main.c

executa: main
	./main
	
Fila.o: Fila.c Fila.h
	$(CC) -c Fila.c
	
clean:
	rm main $(objects)
