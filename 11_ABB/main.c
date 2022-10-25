#include <stdio.h>
#include "ABB.h"

int main() {
    t_abb raiz;
    t_elemento e;
	t_apontador p;

    criar(&raiz);

    e.chave = 5;
    inserir(&raiz, e);

    e.chave = 5;
    inserir(&raiz, e);
    e.chave = 2;
    inserir(&raiz, e);
    e.chave = 10;
    inserir(&raiz, e);
    e.chave = 1;
    inserir(&raiz, e);
    e.chave = 3;
    inserir(&raiz, e);
    e.chave = 8;
    inserir(&raiz, e);
    e.chave = 12;
    inserir(&raiz, e);
    e.chave = 6;
    inserir(&raiz, e);
    e.chave = 9;
    inserir(&raiz, e);
    e.chave = 14;
    inserir(&raiz, e);
    

    pesquisar(&raiz, 10);    
    pesquisar(&raiz, 9);
    remover(&raiz, 10);
    pesquisar(&raiz, 10);
    pesquisar(&raiz, 9);

 //	imprimir(&l);
	
	return 0;
}