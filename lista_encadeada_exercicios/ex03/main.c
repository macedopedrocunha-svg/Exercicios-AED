#include <stdio.h>
#include "lista.h"

int main() {
    Head *lista = criaLista();
    Info dado;
    int valores[] = {1, 2, 3, 2, 4};
    int valor = 2;
    int i;

    for (i = 0; i < 5; i++) {
        dado.valor = valores[i];
        inserirFinal(lista, dado);
    }

    printf("Entrada: ");
    imprimirLista(lista);
    printf("Valor: %d\n", valor);

    removerTodos(lista, valor);

    printf("Saída: ");
    imprimirLista(lista);

    liberaLista(lista);
    return 0;
}
