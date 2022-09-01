#include "Lista.h"
#include <stdio.h>

/*
#define MAX_TAM 100

#define JA_EXISTE -2
#define NAO_ENCONTROU -1
#define ERRO_CHEIA 0
#define SUCESSO 1

typedef int t_chave;
typedef int t_apontador;

typedef struct {
	t_chave chave;
	char nome[50];
} t_elemento;

typedef struct {
	t_elemento elementos[MAX_TAM];
	t_apontador ultimo;
} t_lista;
*/

static t_apontador pesquisa_pos(t_lista *lista, t_chave chave) {
	t_apontador i;
	for (i=0; i <= lista->ultimo; i++) {
		if(lista->elementos[i].chave == chave) {
			return i;
		}
	}
	return NAO_ENCONTROU;

}


int criar(t_lista *lista) {
	lista->ultimo = -1;
}

int inserir(t_lista *lista, t_elemento elemento) {

	if (cheia(lista))
		return ERRO_CHEIA;
	if (pesquisa_pos(lista, elemento.chave)>=0)
		return JA_EXISTE;

	lista->ultimo++;
	lista->elementos[lista->ultimo] = elemento;

	return SUCESSO;

}


int remover(t_lista *lista, t_chave chave) {
	// TODO
}

t_elemento pesquisar(t_lista *lista, t_chave chave) {
	return lista->elementos[pesquisa_pos(lista, chave)];
}

int alterar(t_lista *lista, t_elemento novo_elemento) {
	//TODO
}

int vazia(t_lista *lista){
	if(lista->ultimo == -1)
		return 1;
	else
		return 0;
}

int cheia(t_lista *lista) {
	if(lista->ultimo == MAX_TAM-1)
		return 1;
	else
		return 0;
}

void imprimir(t_lista *lista) {
	t_apontador i;
	printf("{");
	for (i=0; i <= lista->ultimo; i++) {
		printf("%d, ", lista->elementos[i].chave);
	}
	printf("}\n");
	return;

}