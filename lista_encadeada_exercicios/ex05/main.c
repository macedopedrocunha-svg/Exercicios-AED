#include <stdio.h>
#include "lista.h"

int main() {
    Head *lista = criaLista();
    Info dado;
    int valores[] = {10, 20, 30, 40, 50};
    int n = 3;
    int i;

    for (i = 0; i < 5; i++) {
        dado.valor = valores[i];
        inserirFinal(lista, dado);
    }

    printf("Entrada: ");
    imprimirLista(lista);
    printf("N: %d\n", n);

    inverterPrimeiros(lista, n);

    printf("Saída: ");
    imprimirLista(lista);

    liberaLista(lista);
    return 0;
}
