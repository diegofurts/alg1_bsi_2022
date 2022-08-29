#include <stdio.h>
#include "conjunto.h"

int main() {
	t_conjunto meu_conjunto;
	t_elemento meu_elemento;

	inicializar(meu_conjunto);

	meu_elemento = 45;
	printf("pertence %d\n", pertence(meu_elemento, meu_conjunto));

	meu_elemento = 45;
	printf("insere %d %d\n", meu_elemento, inserir(meu_elemento, meu_conjunto));

	meu_elemento = 45;
	printf("insere %d %d\n", meu_elemento, inserir(meu_elemento, meu_conjunto));

	meu_elemento = 5;
	printf("insere %d %d\n", meu_elemento, inserir(meu_elemento, meu_conjunto));

	meu_elemento = 5;
	printf("pertence %d\n", pertence(meu_elemento, meu_conjunto));

	meu_elemento = 4;
	printf("pertence %d\n", pertence(meu_elemento, meu_conjunto));

	meu_elemento = 45;
	printf("pertence %d\n", pertence(meu_elemento, meu_conjunto));

	meu_elemento = 75;
	printf("insere %d %d\n", meu_elemento, inserir(meu_elemento, meu_conjunto));

	meu_elemento = 22;
	printf("insere %d %d\n", meu_elemento, inserir(meu_elemento, meu_conjunto));

	meu_elemento = 98;
	printf("insere %d %d\n", meu_elemento, inserir(meu_elemento, meu_conjunto));

	imprimir(meu_conjunto);

	meu_elemento = 45;
	remover(meu_elemento, meu_conjunto);

	imprimir(meu_conjunto);


}


