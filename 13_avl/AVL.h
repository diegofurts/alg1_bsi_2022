#ifndef AVL_H
#define AVL_H

#define JA_EXISTE -2
#define NAO_ENCONTROU -1
#define ERRO_CHEIA 0
#define SUCESSO 1

typedef int t_chave;

typedef struct {
	t_chave chave;
	char nome[50];
} t_elemento;

typedef struct t_no *t_apontador;
typedef struct t_no {
	t_elemento elemento;
	t_apontador esq, dir;
	int alt; //novo
} t_no;

typedef t_apontador t_avl;


int criar(t_avl *avl);
int retornar_altura(t_avl *avl);
int checar_fb(t_avl *avl);

int inserir(t_avl *avl, t_elemento elemento);
t_elemento pesquisar(t_avl *avl, t_chave chave);
int remover(t_avl *avl, t_chave chave);
// void imprimir(t_avl *avl);

#endif