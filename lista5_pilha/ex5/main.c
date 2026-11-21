#include <stdio.h>
#include <string.h>
#include "pilha.h"

int main(void) {
    char entrada[256];
    char saida[256];
    printf("Entrada: ");
    if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
        return 1;
    }
    entrada[strcspn(entrada, "\n")] = '\0';

    Pilha *pilha = create();
    for (int i = 0; entrada[i] != '\0'; i++) {
        Elem atual = {entrada[i]};
        int repetido = 0;
        if (!empty(pilha)) {
            Elem topo = pop(pilha);
            push(pilha, topo);
            repetido = (topo.carac == atual.carac);
        }
        if (!repetido) {
            push(pilha, atual);
        }
    }
    int n = size(pilha);
    saida[n] = '\0';
    for (int i = n - 1; i >= 0; i--) {
        saida[i] = pop(pilha).carac;
    }
    printf("Saída: %s\n", saida);
    destroy(pilha);
    return 0;
}
