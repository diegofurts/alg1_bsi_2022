#include "AVL.h"
#include <stdio.h>
#include <stdlib.h>

static int max(int a, int b) {
	return a > b ? a : b; 
}


static void rotacao_esq(t_avl *avl) {

	t_apontador j, B;

	// filho à esq da raiz
	j = (*avl)->esq;
	// filho à esq à dir da raiz
	B = j->dir;

	// a sub-arv muda de pai pela antiga raiz
	(*avl)->esq = B;
	// aux passa a ser a raiz
	j = (*avl);

	(*avl)->alt = max(retornar_altura(&(*avl)->esq),
						retornar_altura(&(*avl)->dir)) + 1;

	j->alt = max(retornar_altura(&j->esq),
						retornar_altura(&j->dir)) + 1;

	// mudar o ponteiro "de cima"
	*avl = j;

}

static void rotacao_dir(t_avl *avl) {

	t_apontador j, B;

	// filho à dir da raiz
	j = (*avl)->dir;
	// filho à dir à esq da raiz
	B = j->esq;

	// a sub-arv muda de pai pela antiga raiz
	(*avl)->dir = B;
	// aux passa a ser a raiz
	j = (*avl);

	(*avl)->alt = max(retornar_altura(&(*avl)->esq),
						retornar_altura(&(*avl)->dir)) + 1;

	j->alt = max(retornar_altura(&j->esq),
						retornar_altura(&j->dir)) + 1;

	// mudar o ponteiro "de cima"
	*avl = j;

}

static void rotacao_dir_esq(t_avl *avl) {

	//rotacionar à direita
	rotacao_dir(&(*avl)->dir);
	//rotacionar à esquerda
	rotacao_esq(avl);

}

static void rotacao_esq_dir(t_avl *avl) {

	rotacao_esq(&(*avl)->esq);
	rotacao_dir(avl);

}

int criar(t_avl *avl) {
	// ideal seria limpar caso houvesse algo
	*avl = NULL;
}

int static criar_raiz(t_avl *avl, t_elemento elemento){

	*avl = (t_avl) malloc(sizeof(t_no));
	if (*avl == NULL)
		return ERRO_CHEIA;
	
	(*avl)->esq = NULL;
	(*avl)->dir = NULL;
	(*avl)->elemento = elemento;
	(*avl)->alt = 0;

	return SUCESSO;

}

int retornar_altura(t_avl *avl) {
    if ((*avl) == NULL)
        return -1;
    else
        return (*avl)->alt;
}

int checar_fb(t_avl *avl) {
    if ((*avl) == NULL)
        return 0;
    else 
        return retornar_altura(&(*avl)->esq) - 
    			retornar_altura(&(*avl)->dir);
}

int inserir(t_avl *avl, t_elemento elemento) {
	
	if ((*avl)==NULL) {
		return criar_raiz(avl, elemento);
	}

	//considerar chaves primárias
	if ((*avl)->elemento.chave == elemento.chave) { 
		return JA_EXISTE;
	} else {

		if (elemento.chave < (*avl)->elemento.chave) {
			inserir(&(*avl)->esq, elemento);
			(*avl)->alt = max((*avl)->alt,
						retornar_altura(&(*avl)->esq) + 1);
		} else {
			inserir(&(*avl)->dir, elemento);
			(*avl)->alt = max((*avl)->alt,
						retornar_altura(&(*avl)->dir) + 1);
		}

	}

	// //opcao/variacao
	// (*avl)->alt = max(retornar_altura(&(*avl)->esq),
	// 					retornar_altura(&(*avl)->dir)) + 1;
    
	int fb = checar_fb(avl);
	//printf("%d - fb %d\n", elemento.chave, fb);

	if (fb > 1) { // esq

		// 2 casos
		int fb_filho = checar_fb(&(*avl)->esq);

		if (fb_filho >=0) {
			rotacao_dir(avl);
		} else {
			rotacao_esq_dir(avl);
		}

	} else if (fb < -1) { // dir

		int fb_filho = checar_fb(&(*avl)->dir);

		if (fb_filho <= 0) {
			rotacao_esq(avl);
		} else {
			rotacao_dir_esq(avl);
		}

	}

    return SUCESSO;

}




t_elemento pesquisar(t_avl *avl, t_chave chave) {

	if ((*avl)==NULL) {
		t_elemento e;
		printf("NOPE\n");
		e.chave = NAO_ENCONTROU;
		return e;
	}

	if ((*avl)->elemento.chave == chave) {

		printf("YEP\n"); 
		return (*avl)->elemento;
	} else {


		if (chave < (*avl)->elemento.chave) {
			return pesquisar(&(*avl)->esq, chave);
		} else {
			return pesquisar(&(*avl)->dir, chave);
		}

	}

}

static void buscaMaiorEsqETroca(t_avl *raiz, t_avl *subarv) {

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

int remover(t_avl *avl, t_chave chave) {

	// nao achou
	if ((*avl) == NULL)
		return NAO_ENCONTROU;

	// busca: direita ou esquerda
	if (chave > (*avl)->elemento.chave) {
		return remover(&(*avl)->dir, chave);
	} else if (chave < (*avl)->elemento.chave) {
		return remover(&(*avl)->esq, chave);
	}

	t_apontador p;

	//se passou, é porque achou a chave
	if ((*avl)->esq==NULL && (*avl)->dir==NULL) { //caso 1 (folha)
		p = *avl;
		*avl = NULL;
		free(p);
	} else if ((*avl)->esq==NULL) { // caso 2 (dir)
		p = *avl;
		*avl = (*avl)->dir;
		free(p);
	} else if ((*avl)->dir==NULL) { //caso 2 (esq)
		p = *avl;
		*avl = (*avl)->esq;
		free(p);
	} else { //caso 3
		buscaMaiorEsqETroca(avl, &(*avl)->esq);
	}

	return SUCESSO;

}
