#include "ABB.h"
#include <stdio.h>
#include <stdlib.h>

int criar(t_abb *abb) {
	// ideal seria limpar caso houvesse algo
	*abb = NULL;
}

int static criar_raiz(t_abb *abb, t_elemento elemento){

	*abb = (t_abb) malloc(sizeof(t_no));
	if (*abb == NULL)
		return ERRO_CHEIA;
	
	(*abb)->esq = NULL;
	(*abb)->dir = NULL;
	(*abb)->elemento = elemento;

	return SUCESSO;

}

int inserir(t_abb *abb, t_elemento elemento) {
	
	if ((*abb)==NULL) {
		return criar_raiz(abb, elemento);
	}

	//considerar chaves primárias
	if ((*abb)->elemento.chave == elemento.chave) { 
		return JA_EXISTE;
	} else {

		if (elemento.chave < (*abb)->elemento.chave) {
			return inserir(&(*abb)->esq, elemento);
		} else {
			return inserir(&(*abb)->dir, elemento);
		}

	}

}

t_elemento pesquisar(t_abb *abb, t_chave chave) {

	if ((*abb)==NULL) {
		t_elemento e;
		printf("NOPE\n");
		e.chave = NAO_ENCONTROU;
		return e;
	}

	if ((*abb)->elemento.chave == chave) {

		printf("YEP\n"); 
		return (*abb)->elemento;
	} else {


		if (chave < (*abb)->elemento.chave) {
			return pesquisar(&(*abb)->esq, chave);
		} else {
			return pesquisar(&(*abb)->dir, chave);
		}

	}

}

static void buscaMaiorEsqETroca(t_abb *raiz, t_abb *subarv) {

	if ((*subarv)->dir == NULL) {

		t_apontador p;

		(*raiz)->elemento = (*subarv)->elemento;

		p = *subarv;
		*subarv = (*subarv)->esq;
		free(p);

	} else {
		buscaMaiorEsqETroca(raiz, &(*subarv)->dir);		
	}

}

int remover(t_abb *abb, t_chave chave) {

	// nao achou
	if ((*abb) == NULL)
		return NAO_ENCONTROU;

	// busca: direita ou esquerda
	if (chave > (*abb)->elemento.chave) {
		return remover(&(*abb)->dir, chave);
	} else if (chave < (*abb)->elemento.chave) {
		return remover(&(*abb)->esq, chave);
	}

	t_apontador p;

	//se passou, é porque achou a chave
	if ((*abb)->esq==NULL && (*abb)->dir==NULL) { //caso 1 (folha)
		p = *abb;
		*abb = NULL;
		free(p);
	} else if ((*abb)->esq==NULL) { // caso 2 (dir)
		p = *abb;
		*abb = (*abb)->dir;
		free(p);
	} else if ((*abb)->dir==NULL) { //caso 2 (esq)
		p = *abb;
		*abb = (*abb)->esq;
		free(p);
	} else { //caso 3
		buscaMaiorEsqETroca(abb, &(*abb)->esq);
	}

	return SUCESSO;

}
