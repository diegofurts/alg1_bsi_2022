#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>

int criar(t_lista *lista) {
	lista->primeiro = NULL;
	//lista->ultimo = NULL;
}

int inserir(t_lista *lista, t_elemento elemento) {

	t_apontador novo = (t_apontador) malloc(sizeof(t_no));
	if (novo == NULL)
		return ERRO_CHEIA;

	novo->elemento = elemento;
	novo->proximo = lista->primeiro;
	lista->primeiro = novo;

	return SUCESSO;

}

static t_apontador pesquisa_pos(t_lista *lista, t_chave chave) {

	t_apontador P = lista->primeiro;
	if(P == NULL)
		return NULL;

	while(P != NULL) {
		if (P->elemento.chave == chave)
			return P;
		P = P->proximo;
	}

	return NULL;

}

int remover(t_lista *lista, t_chave chave) {

	t_apontador P = lista->primeiro;
	if(P == NULL)
		return NAO_ENCONTROU;

	// elemento a remover é o primeiro da lista
	if (P->elemento.chave == chave) { 
		lista->primeiro = lista->primeiro->proximo;
		free(P);
		return SUCESSO;
	}

	while(P->proximo != NULL) {
		if (P->proximo->elemento.chave == chave) {
			t_apontador aux = P->proximo;
			P->proximo = P->proximo->proximo;
			free(aux);
			return SUCESSO;
		}
		P = P->proximo;
	}

	return NAO_ENCONTROU;

}

t_elemento pesquisar(t_lista *lista, t_chave chave) {
	t_apontador P = pesquisa_pos(lista, chave);
	return P->elemento;
}

int alterar(t_lista *lista, t_elemento novo_elemento);
int vazia(t_lista *lista);
int cheia(t_lista *lista);

void imprimir(t_lista *lista) {

	t_apontador P = lista->primeiro;
	
	while(P != NULL) {
		printf("%d ", P->elemento.chave);
		P = P->proximo;
	}
	printf("\n");

}