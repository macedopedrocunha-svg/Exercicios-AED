#include <stdio.h>
#include <string.h>
#include "pilha.h"

int main(void) {
    char entrada[256];
    char saida[256];
    printf("Digite uma string: ");
    if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
        return 1;
    }
    entrada[strcspn(entrada, "\n")] = '\0';

    Pilha *pilha = create();
    for (int i = 0; entrada[i] != '\0'; i++) {
        Elem e = {entrada[i]};
        push(pilha, e);
    }
    int j = 0;
    while (!empty(pilha)) {
        saida[j++] = pop(pilha).carac;
    }
    saida[j] = '\0';

    printf("Original: %s\n", entrada);
    printf("Invertida: %s\n", saida);
    destroy(pilha);
    return 0;
}
