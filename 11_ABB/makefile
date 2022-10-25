CC = gcc
CFLAGS = -Wall
objects = main.o ABB.o

executa: main
	./main
	
main: ABB.o main.c
	$(CC) -o main ABB.o main.c
	
ABB.o: ABB.c ABB.h
	$(CC) -c ABB.c
	
clean:
	rm main $(objects)
