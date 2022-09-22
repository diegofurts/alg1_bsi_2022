CC = gcc
CFLAGS = -Wall
objects = main.o Pilha.o

main: Pilha.o main.c
	$(CC) -o main Pilha.o main.c

executa: main
	./main
	
Pilha.o: Pilha.c Pilha.h
	$(CC) -c Pilha.c
	
clean:
	rm main $(objects)
