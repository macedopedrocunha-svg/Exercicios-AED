#include <stdio.h>
#include "pilha.h"

int main(void) {
    
    Pilha *pilha = create();
    int op;
    do {
        printf("\n1 - push\n2 - pop\n3 - top\n4 - size\n5 - empty\n6 - print\n7 - clear\n8 - reset\n0 - sair\nOpção: ");
        if (scanf("%d", &op) != 1) {
            break;
        }
        switch (op) {
            case 1: {
                Elem e;
                printf("Caractere: ");
                scanf(" %c", &e.carac);
                push(pilha, e);
                break;
            }
            case 2:
                if (empty(pilha)) {
                    printf("Pilha vazia.\n");
                } else {
                    Elem e = pop(pilha);
                    printf("Removido: %c\n", e.carac);
                }
                break;
            case 3:
                top(pilha);
                break;
            case 4:
                printf("Tamanho: %d\n", size(pilha));
                break;
            case 5:
                printf(empty(pilha) ? "A pilha está vazia.\n" : "A pilha não está vazia.\n");
                break;
            case 6:
                print(pilha);
                break;
            case 7:
                clear(pilha);
                break;
            case 8:
                reset(pilha);
                break;
            case 0:
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (op != 0);
    destroy(pilha);
    return 0;
}
