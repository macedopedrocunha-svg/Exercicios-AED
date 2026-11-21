#include <stdio.h>
#include <string.h>
#include "pilha.h"

void remover(Pilha *pilha, float valor) {
    Pilha *aux = create();
    while (!empty(pilha)) {
        Elem e = pop(pilha);
        if ((float)e.carac != valor) {
            push(aux, e);
        }
    }
    while (!empty(aux)) {
        push(pilha, pop(aux));
    }
    destroy(aux);
}

int main(void) {
    char entrada[256];
    char alvo;
    printf("Elementos da pilha (base ao topo): ");
    if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
        return 1;
    }
    entrada[strcspn(entrada, "\n")] = '\0';
    printf("Remover: ");
    if (scanf(" %c", &alvo) != 1) {
        return 1;
    }

    Pilha *pilha = create();
    for (int i = 0; entrada[i] != '\0'; i++) {
        if (entrada[i] != ' ') {
            Elem e = {entrada[i]};
            push(pilha, e);
        }
    }
    printf("Pilha: ");
    print(pilha);
    remover(pilha, (float)alvo);
    printf("Saída: ");
    print(pilha);
    destroy(pilha);
    return 0;
}
