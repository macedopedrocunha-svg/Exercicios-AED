#include <stdio.h>
#include "lista.h"

int main() {
    Head *lista = criaLista();
    Info dado;
    Info resultado;

    printf("Lista vazia: %d\n", listaVazia(lista));

    dado.valor = 20;
    inserirInicio(lista, dado);
    dado.valor = 10;
    inserirInicio(lista, dado);
    dado.valor = 30;
    inserirFinal(lista, dado);
    dado.valor = 40;
    inserirFinal(lista, dado);

    imprimirLista(lista);

    printf("Buscar 30: %d\n", buscar(lista, 30, &resultado));
    if (buscar(lista, 30, &resultado)) {
        printf("Encontrado: %d\n", resultado.valor);
    }
    printf("Buscar 99: %d\n", buscar(lista, 99, &resultado));

    removerInicio(lista);
    imprimirLista(lista);

    removerFinal(lista);
    imprimirLista(lista);

    removerInicio(lista);
    removerInicio(lista);
    printf("Remover em lista vazia: %d\n", removerInicio(lista));
    printf("Lista vazia: %d\n", listaVazia(lista));
    imprimirLista(lista);

    liberaLista(lista);
    return 0;
}
