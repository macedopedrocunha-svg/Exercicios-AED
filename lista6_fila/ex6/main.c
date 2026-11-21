#include <stdio.h>
#include "fila.h"

Fila *intercalar(Fila *a, Fila *b) {
    Fila *resultado = create();
    int na = size(a);
    int nb = size(b);
    int max = na > nb ? na : nb;
    for (int i = 0; i < max; i++) {
        if (i < na) {
            Elem e = dequeue(a);
            enqueue(resultado, e);
            enqueue(a, e);
        }
        if (i < nb) {
            Elem e = dequeue(b);
            enqueue(resultado, e);
            enqueue(b, e);
        }
    }
    return resultado;
}

static void ler(Fila *fila, int numero) {
    int n;
    printf("Quantidade de elementos da fila %d: ", numero);
    if (scanf("%d", &n) != 1) {
        return;
    }
    for (int i = 0; i < n; i++) {
        Elem e;
        printf("Elemento %d: ", i + 1);
        scanf("%d", &e.valor);
        enqueue(fila, e);
    }
}

int main(void) {
    Fila *f1 = create();
    Fila *f2 = create();
    ler(f1, 1);
    ler(f2, 2);
    Fila *res = intercalar(f1, f2);
    printf("Fila 1: ");
    print(f1);
    printf("Fila 2: ");
    print(f2);
    printf("Resultado: ");
    print(res);
    destroy(f1);
    destroy(f2);
    destroy(res);
    return 0;
}
