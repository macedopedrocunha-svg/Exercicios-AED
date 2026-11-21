#include <stdio.h>
#include <string.h>
#include "pilha.h"

static void descarregar(Pilha *pilha, char *saida, int *k) {
    while (!empty(pilha)) {
        saida[(*k)++] = pop(pilha).carac;
    }
}

int main(void) {
    char entrada[512];
    char saida[512];
    printf("Entrada: ");
    if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
        return 1;
    }
    entrada[strcspn(entrada, "\n")] = '\0';

    Pilha *pilha = create();
    int k = 0;
    for (int i = 0; entrada[i] != '\0'; i++) {
        if (entrada[i] == ' ') {
            descarregar(pilha, saida, &k);
            saida[k++] = ' ';
        } else {
            Elem e = {entrada[i]};
            push(pilha, e);
        }
    }
    descarregar(pilha, saida, &k);
    saida[k] = '\0';
    printf("Saída: %s\n", saida);
    destroy(pilha);
    return 0;
}
