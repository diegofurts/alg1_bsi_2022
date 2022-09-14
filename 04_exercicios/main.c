#include <stdio.h>
#include "Lista.h"

void reverse(t_lista *lista) {


    if(lista->primeiro == NULL)
        printf("Lista vazia\n");
    if (lista->primeiro->proximo == NULL)
        printf("Lista unitária, ta feito!\n");

    t_apontador ant = NULL;
    t_apontador prox = lista->primeiro;

    do { // para quando o prox for null
        prox = lista->primeiro->proximo;
        lista->primeiro->proximo = ant; // inverter o proximo
        ant = lista->primeiro; // andar com o ant pra frente
        lista->primeiro = prox; // cuidado com a cabeça da lista indo pra frente
    } while(prox != NULL);
    lista->primeiro = ant;

    //TODO cabeça da lista

}

int main() {
    t_lista l;
    t_elemento e;
	
    /*
    Operações
    0 - sair
    1 - inserir (pergunto o elemento)
    2 - remover (pergunto o elemento)
    3 - imprimir
    4 - reverse
    */

    int opcao = -1;
    criar(&l);

    while (opcao != 0) {

        scanf("%d ", &opcao);

        switch (opcao) {
            case 0: // sair
                //TODO funcao de limpar a lista
                break;
            case 1: // inserir
                scanf("%d ", &e.chave);
                inserir(&l, e);
                break;
            case 2: // remover
                scanf("%d ", &e.chave);
                remover(&l, e.chave);
                break;
            case 3: // imprimir
                imprimir(&l);
                break;
            case 4: // reverse
                reverse(&l);
                break;
            default:
                printf("Operacao invalida\n");
        }

    }

	return 0;
}