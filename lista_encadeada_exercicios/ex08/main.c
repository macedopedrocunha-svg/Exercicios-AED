#include <stdio.h>
#include "lista.h"

int main() {
    Head *lista = criaLista();
    Head *impares = criaLista();
    Head *pares = criaLista();
    Info dado;
    int valores[] = {10, 20, 30, 40, 50};
    int i;

    for (i = 0; i < 5; i++) {
        dado.valor = valores[i];
        inserirFinal(lista, dado);
    }

    printf("Entrada: ");
    imprimirLista(lista);

    separarPosicoes(lista, impares, pares);

    printf("Lista posições ímpares: ");
    imprimirLista(impares);
    printf("Lista posições pares: ");
    imprimirLista(pares);

    liberaLista(lista);
    liberaLista(impares);
    liberaLista(pares);
    return 0;
}
