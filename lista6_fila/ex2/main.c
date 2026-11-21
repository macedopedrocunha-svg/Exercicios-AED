#include <stdio.h>
#include "fila.h"

int maior(Fila *fila) {
    int n = size(fila);
    Elem e = dequeue(fila);
    int max = e.valor;
    enqueue(fila, e);
    for (int i = 1; i < n; i++) {
        e = dequeue(fila);
        if (e.valor > max) {
            max = e.valor;
        }
        enqueue(fila, e);
    }
    return max;
}

int main(void) {
    int n;
    Fila *fila = create();
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
    if (empty(fila)) {
        printf("Fila vazia.\n");
    } else {
        printf("Maior elemento: %d\n", maior(fila));
        printf("Fila após a busca: ");
        print(fila);
    }
    destroy(fila);
    return 0;
}
