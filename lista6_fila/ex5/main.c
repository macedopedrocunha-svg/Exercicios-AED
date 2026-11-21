#include <stdio.h>
#include "fila.h"

void remover(Fila *fila, int valor) {
    int n = size(fila);
    for (int i = 0; i < n; i++) {
        Elem e = dequeue(fila);
        if (e.valor != valor) {
            enqueue(fila, e);
        }
    }
}

int main(void) {
    int n, alvo;
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
    printf("Valor a remover: ");
    if (scanf("%d", &alvo) != 1) {
        return 1;
    }
    printf("Fila original: ");
    print(fila);
    remover(fila, alvo);
    printf("Fila resultante: ");
    print(fila);
    destroy(fila);
    return 0;
}
