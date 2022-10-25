#ifndef ABB_H
#define ABB_H

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
} t_no;

typedef t_apontador t_abb;


int criar(t_abb *abb);
int inserir(t_abb *abb, t_elemento elemento);
t_elemento pesquisar(t_abb *abb, t_chave chave);
int remover(t_abb *abb, t_chave chave);
// int alterar(t_abb *abb, t_elemento novo_elemento);
// int vazia(t_abb *abb);
// int cheia(t_abb *abb);
// void imprimir(t_abb *abb);

#endif