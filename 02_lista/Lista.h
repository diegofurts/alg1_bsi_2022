#ifndef LISTA_H
#define LISTA_H

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

int criar(t_lista *lista);
int inserir(t_lista *lista, t_elemento elemento);
int remover(t_lista *lista, t_chave chave);
t_elemento pesquisar(t_lista *lista, t_chave chave);
int alterar(t_lista *lista, t_elemento novo_elemento);
int vazia(t_lista *lista);
int cheia(t_lista *lista);
void imprimir(t_lista *lista);

#endif