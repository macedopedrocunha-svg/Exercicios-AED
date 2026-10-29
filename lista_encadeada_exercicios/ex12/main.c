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

void testar(int *valores, int n, int valor) {
    Head *lista = criaLista();
    preencher(lista, valores, n);

    printf("Entrada: ");
    imprimirLista(lista);
    printf("Valor: %d\n", valor);

    if (removerValor(lista, valor)) {
        printf("Saída: ");
    } else {
        printf("Valor não encontrado. Saída: ");
    }
    imprimirLista(lista);
    printf("\n");

    liberaLista(lista);
}

int main() {
    int v1[] = {10, 20, 30, 40};
    int v2[] = {10, 20, 30, 40};
    int v3[] = {10, 20, 30, 40};
    int v4[] = {10, 30, 20, 30};
    int v5[] = {10};
    int v6[] = {10, 20};

    testar(v1, 4, 30);
    testar(v2, 4, 10);
    testar(v3, 4, 40);
    testar(v4, 4, 30);
    testar(v5, 1, 10);
    testar(v6, 2, 99);

    return 0;
}
