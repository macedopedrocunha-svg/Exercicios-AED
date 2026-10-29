#include <stdio.h>
#include "lista.h"

int main() {
    Head *lista = criaLista();
    Info dado;
    int valores[] = {10, 25, 15, 30};
    int valor = 20;
    int i;

    for (i = 0; i < 4; i++) {
        dado.valor = valores[i];
        inserirFinal(lista, dado);
    }

    printf("Entrada: ");
    imprimirLista(lista);
    printf("Valor: %d\n", valor);
    printf("Quantidade: %d\n", contarMaiores(lista, valor));

    liberaLista(lista);
    return 0;
}
