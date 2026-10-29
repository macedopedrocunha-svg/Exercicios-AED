#include <stdio.h>
#include "lista.h"

int main() {
    Head *lista = criaLista();
    Info dado;
    int valores[] = {10, 20, 30, 40};
    int i;

    for (i = 0; i < 4; i++) {
        dado.valor = valores[i];
        inserirFinal(lista, dado);
    }

    printf("Entrada: ");
    imprimirLista(lista);
    printf("Quantidade: %d\n", quantidadeElementos(lista));

    liberaLista(lista);
    return 0;
}
