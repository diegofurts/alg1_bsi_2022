#include <stdio.h>
#include <string.h>

#define max 200

#define SEM_ERRO 0
#define JA_EXISTE 1
#define OUTRO_ERRO 2

typedef int t_elemento;
typedef t_elemento t_conjunto[max];

void inicializar(t_conjunto c);
char inserir(t_elemento e, t_conjunto c);
char remover(t_elemento e, t_conjunto c);
char pertence(t_elemento e, t_conjunto c);


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
}


void inicializar(t_conjunto c) {
	memset(c, 0, sizeof(t_conjunto));
}

char inserir(t_elemento e, t_conjunto c) {
	if (!pertence(e, c)) {
		c[e] = 1;
		return SEM_ERRO;
	} else {
		return JA_EXISTE;
	}
}

char remover(t_elemento e, t_conjunto c) {
	if (pertence(e, c)) {
		c[e] = 0;
		return SEM_ERRO;
	} else {
		return OUTRO_ERRO;
	}
}

char pertence(t_elemento e, t_conjunto c) {
	return c[e];
}

void imprimir(t_conjunto c)
{
	printf("{");
	for (int i = 0; i < max; i++)
		if (pertence(c, i))
			printf("%d, ", i);
	printf("}\n");
}
