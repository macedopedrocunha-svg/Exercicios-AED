#include <stdio.h>
#include "lista.h"

int main() {
    Head *lista1 = criaLista();
    Head *lista2 = criaLista();
    Info dado;
    int valores1[] = {10, 20, 30};
    int valores2[] = {40, 50};
    int i;

    for (i = 0; i < 3; i++) {
        dado.valor = valores1[i];
        inserirFinal(lista1, dado);
    }
    for (i = 0; i < 2; i++) {
        dado.valor = valores2[i];
        inserirFinal(lista2, dado);
    }

    printf("Lista 1: ");
    imprimirLista(lista1);
    printf("Lista 2: ");
    imprimirLista(lista2);

    concatenar(lista1, lista2);

    printf("Saída:\n");
    printf("Lista 1: ");
    imprimirLista(lista1);
    printf("Lista 2: ");
    imprimirLista(lista2);

    liberaLista(lista1);
    liberaLista(lista2);
    return 0;
}
