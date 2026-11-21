#include <stdio.h>
#include "fila.h"

int main(void) {
    Fila *fila = create();
    int op;
    do {
        printf("\n1 - enqueue\n2 - dequeue\n3 - front\n4 - size\n5 - empty\n6 - print\n7 - clear\n8 - reset\n0 - sair\nOpção: ");
        if (scanf("%d", &op) != 1) {
            break;
        }
        switch (op) {
            case 1: {
                Elem e;
                printf("Valor: ");
                scanf("%d", &e.valor);
                enqueue(fila, e);
                break;
            }
            case 2:
                if (empty(fila)) {
                    printf("Fila vazia.\n");
                } else {
                    Elem e = dequeue(fila);
                    printf("Removido: %d\n", e.valor);
                }
                break;
            case 3:
                front(fila);
                break;
            case 4:
                printf("Tamanho: %d\n", size(fila));
                break;
            case 5:
                printf(empty(fila) ? "A fila está vazia.\n" : "A fila não está vazia.\n");
                break;
            case 6:
                print(fila);
                break;
            case 7:
                clear(fila);
                break;
            case 8:
                reset(fila);
                break;
            case 0:
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (op != 0);
    destroy(fila);
    return 0;
}
