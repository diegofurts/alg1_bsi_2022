CC = gcc
CFLAGS = -Wall
objects = main.o AVL.o

executa: main
	./main
	
main: AVL.o main.c
	$(CC) -o main AVL.o main.c
	
AVL.o: AVL.c AVL.h
	$(CC) -c AVL.c
	
clean:
	rm main $(objects)
