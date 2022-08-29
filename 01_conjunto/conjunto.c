#include <stdio.h>
#include <string.h>
#include "conjunto.h"

void inicializar(t_conjunto c) {
	memset(c, 0, sizeof(t_conjunto));
}

char inserir(t_elemento e, t_conjunto c) {
	if (!pertence(e, c)) {
		c[e] = 1;
		return SEM_ERRO;
	} else {
		return JA_EXISTE;
	}
}

char remover(t_elemento e, t_conjunto c) {
	if (pertence(e, c)) {
		c[e] = 0;
		return SEM_ERRO;
	} else {
		return OUTRO_ERRO;
	}
}

char pertence(t_elemento e, t_conjunto c) {
	return c[e];
}

void imprimir(t_conjunto c)
{
	printf("{");
	for (int i = 0; i < max; i++)
		if (pertence(i, c))
			printf("%d, ", i);
	printf("}\n");
}
