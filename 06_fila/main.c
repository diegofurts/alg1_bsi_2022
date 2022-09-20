#include <stdio.h>
#include "Fila.h"

int main() {
    t_fila f;
    t_elemento e;
	t_apontador p;
    t_no no;

    criar(&f);

    e.chave = 5;
    enfileirar(&f, e);
    no = frente(&f);
    printf("%d (%d elementos)\n", no.elemento.chave, contar(&f));

    e.chave = 3;
    enfileirar(&f, e);
    no = frente(&f);
    printf("%d (%d elementos)\n", no.elemento.chave, contar(&f));

    e.chave = 7;
    enfileirar(&f, e);
    no = frente(&f);
    printf("%d (%d elementos)\n", no.elemento.chave, contar(&f));

    desenfileirar(&f);
    no = frente(&f);
    printf("%d (%d elementos)\n", no.elemento.chave, contar(&f));

    desenfileirar(&f);
    no = frente(&f);
    printf("%d (%d elementos)\n", no.elemento.chave, contar(&f));

	return 0;
}