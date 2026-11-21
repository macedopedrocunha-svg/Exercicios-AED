#include <stdio.h>
#include "fila.h"
#include "pilha.h"

void inverter(Fila *fila) {
    Pilha *aux = createPilha();
    while (!empty(fila)) {
        pushPilha(aux, dequeue(fila).valor);
    }
    while (!emptyPilha(aux)) {
        Elem e = {popPilha(aux)};
        enqueue(fila, e);
    }
    destroyPilha(aux);
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
    print(fila);
    inverter(fila);
    print(fila);
    destroy(fila);
    return 0;
}
