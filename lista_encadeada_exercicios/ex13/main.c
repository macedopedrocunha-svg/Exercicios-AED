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

void testar(int *valores, int n) {
    Head *lista = criaLista();
    preencher(lista, valores, n);

    printf("Entrada: ");
    imprimirLista(lista);
    if (ehPalindromo(lista)) {
        printf("Saída: É palíndromo\n\n");
    } else {
        printf("Saída: Não é palíndromo\n\n");
    }

    liberaLista(lista);
}

int main() {
    int v1[] = {10, 20, 30, 20, 10};
    int v2[] = {1, 2, 2, 1};
    int v3[] = {1, 2, 3};
    int v4[] = {7};
    int v5[] = {1, 2};

    testar(v1, 5);
    testar(v2, 4);
    testar(v3, 3);
    testar(v4, 1);
    testar(v5, 2);

    return 0;
}
