#include "Pilha.h"
#include <stdio.h>
#include <stdlib.h>

static int num_nos;

int criar(t_pilha *pilha) {
	pilha->topo = NULL;
	num_nos = 0;
}

int empilhar(t_pilha *pilha, t_elemento elemento) {

	t_apontador novo = (t_apontador) malloc(sizeof(t_no));
	if (novo == NULL)
		return ERRO_CHEIA;

	novo->elemento = elemento;

	novo->proximo = pilha->topo;
	pilha->topo = novo;
	
	num_nos++;

	return SUCESSO;

}


int desempilhar(t_pilha *pilha) {

	if (vazia(pilha)) 
		return NAO_ENCONTROU;

	t_apontador aux = pilha->topo;
	pilha->topo = pilha->topo->proximo;
	free(aux);

	num_nos--;

	return SUCESSO;

}

t_no topo(t_pilha *pilha) {
	//TODO
	/*if (vazia(pilha))
		return NO_VAZIO;*/ 
	return *(pilha->topo);
}

int vazia(t_pilha *pilha) {
	if(pilha->topo == NULL)
		return 1;
	else
		return 0;
}

int cheia(t_pilha *pilha) {

}

int contar(t_pilha *pilha) {
	return num_nos;
}

void imprimir(t_pilha *pilha);