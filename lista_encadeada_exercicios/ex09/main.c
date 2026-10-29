#include <stdio.h>
#include "lista.h"

int main() {
    Head *original = criaLista();
    Head *copia;
    Info dado;
    int valores[] = {10, 20, 30};
    int i;

    for (i = 0; i < 3; i++) {
        dado.valor = valores[i];
        inserirFinal(original, dado);
    }

    copia = copiarLista(original);

    printf("Lista original: ");
    imprimirLista(original);
    printf("Nova lista: ");
    imprimirLista(copia);

    dado.valor = 99;
    inserirFinal(copia, dado);
    removerInicio(original);

    printf("Após modificar as listas:\n");
    printf("Lista original: ");
    imprimirLista(original);
    printf("Nova lista: ");
    imprimirLista(copia);

    liberaLista(original);
    liberaLista(copia);
    return 0;
}
