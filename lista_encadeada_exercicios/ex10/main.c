#include <stdio.h>
#include "lista.h"

int main() {
    Head *lista = criaLista();
    Info dado;
    int valores[] = {1, 2, 4, 5, 8, 9};
    int i;

    for (i = 0; i < 6; i++) {
        dado.valor = valores[i];
        inserirFinal(lista, dado);
    }

    printf("Entrada: ");
    imprimirLista(lista);

    removerPares(lista);

    printf("Saída: ");
    imprimirLista(lista);

    liberaLista(lista);
    return 0;
}
