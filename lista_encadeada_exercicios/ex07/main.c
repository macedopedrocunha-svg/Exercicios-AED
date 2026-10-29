#include <stdio.h>
#include "lista.h"

void preencher(Head *lista, int *valores, int n) {
    Info dado;
    int i;
    for (i = 0; i < n; i++) {
        dado.valor = valores[i];
        inserirFinal(lista, dado);
    }
}

void testar(int *v1, int n1, int *v2, int n2) {
    Head *lista1 = criaLista();
    Head *lista2 = criaLista();

    preencher(lista1, v1, n1);
    preencher(lista2, v2, n2);

    printf("Lista 1: ");
    imprimirLista(lista1);
    printf("Lista 2: ");
    imprimirLista(lista2);

    intercalar(lista1, lista2);

    printf("Saída:\n");
    printf("Lista 1: ");
    imprimirLista(lista1);
    printf("Lista 2: ");
    imprimirLista(lista2);
    printf("\n");

    liberaLista(lista1);
    liberaLista(lista2);
}

int main() {
    int a1[] = {10, 30, 50};
    int b1[] = {20, 40, 60};
    int a2[] = {1, 3, 5, 7, 9};
    int b2[] = {2, 4};
    int a3[] = {1, 3};
    int b3[] = {2, 4, 6, 8, 10};

    testar(a1, 3, b1, 3);
    testar(a2, 5, b2, 2);
    testar(a3, 2, b3, 5);

    return 0;
}
