#include <stdio.h>
#include "Lista.h"

int main() {
    t_lista l;
    t_elemento e;
	t_apontador p;

    criar(&l);

    e.chave = 5;
    inserir(&l, e);

    e.chave = 3;
    inserir(&l, e);

    e.chave = 7;
    inserir(&l, e);

 	imprimir(&l);
	
	return 0;
}