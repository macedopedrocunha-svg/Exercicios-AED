#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"

int main(void) {
    char palavra[256];
    printf("Digite uma palavra: ");
    if (scanf("%255s", palavra) != 1) {
        return 1;
    }

    Pilha *pilha = create();
    for (int i = 0; palavra[i] != '\0'; i++) {
        Elem e = {palavra[i]};
        push(pilha, e);
    }
    int palindromo = 1;
    for (int i = 0; palavra[i] != '\0'; i++) {
        Elem e = pop(pilha);
        if (toupper((unsigned char)e.carac) != toupper((unsigned char)palavra[i])) {
            palindromo = 0;
            break;
        }
    }
    printf("%s → %s\n", palavra, palindromo ? "palíndromo" : "não é palíndromo");
    destroy(pilha);
    return 0;
}
