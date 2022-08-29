#ifndef CONJUNTO_H
#define CONJUNTO_H

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
void imprimir(t_conjunto c);

#endif