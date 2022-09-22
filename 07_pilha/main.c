#include <stdio.h>
#include "Pilha.h"

int main() {
    t_pilha f;
    t_elemento e;
	t_apontador p;
    t_no no;

    criar(&f);

    e.chave = 5;
    empilhar(&f, e);
    no = topo(&f);
    printf("%d (%d elementos)\n", no.elemento.chave, contar(&f));

    e.chave = 3;
    empilhar(&f, e);
    no = topo(&f);
    printf("%d (%d elementos)\n", no.elemento.chave, contar(&f));

    e.chave = 7;
    empilhar(&f, e);
    no = topo(&f);
    printf("%d (%d elementos)\n", no.elemento.chave, contar(&f));

    no = topo(&f);
    desempilhar(&f);
    printf("%d (%d elementos)\n", no.elemento.chave, contar(&f));

    no = topo(&f);
    desempilhar(&f);
    printf("%d (%d elementos)\n", no.elemento.chave, contar(&f));

	return 0;
}