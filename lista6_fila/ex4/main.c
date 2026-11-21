#include <stdio.h>
#include "fila.h"

void separar(Fila *origem, Fila *pares, Fila *impares) {
    int n = size(origem);
    for (int i = 0; i < n; i++) {
        Elem e = dequeue(origem);
        if (e.valor % 2 == 0) {
            enqueue(pares, e);
        } else {
            enqueue(impares, e);
        }
        enqueue(origem, e);
    }
}

int main(void) {
    int n;
    Fila *fila = create();
    Fila *pares = create();
    Fila *impares = create();
    printf("Quantidade de elementos: ");
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    for (int i = 0; i < n; i++) {
        Elem e;
        printf("Elemento %d: ", i + 1);
        scanf("%d", &e.valor);
        enqueue(fila, e);
    }
    separar(fila, pares, impares);
    printf("Fila original: ");
    print(fila);
    printf("Pares: ");
    print(pares);
    printf("Ímpares: ");
    print(impares);
    destroy(fila);
    destroy(pares);
    destroy(impares);
    return 0;
}
