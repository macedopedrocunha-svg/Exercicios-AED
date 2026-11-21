#include <stdio.h>
#include <string.h>
#include "pilha.h"

static int casa(char abre, char fecha) {
    return (abre == '(' && fecha == ')') ||
           (abre == '{' && fecha == '}') ||
           (abre == '[' && fecha == ']');
}

static int balanceada(const char *expr) {
    Pilha *pilha = create();
    int ok = 1;
    for (int i = 0; expr[i] != '\0' && ok; i++) {
        char c = expr[i];
        if (c == '(' || c == '{' || c == '[') {
            Elem e = {c};
            push(pilha, e);
        } else if (c == ')' || c == '}' || c == ']') {
            if (empty(pilha) || !casa(pop(pilha).carac, c)) {
                ok = 0;
            }
        }
    }
    if (ok && !empty(pilha)) {
        ok = 0;
    }
    destroy(pilha);
    return ok;
}

int main(void) {
    char expr[512];
    printf("Digite a expressão matemática: ");
    if (fgets(expr, sizeof(expr), stdin) == NULL) {
        return 1;
    }
    expr[strcspn(expr, "\n")] = '\0';
    if (balanceada(expr)) {
        printf("A expressão está corretamente balanceada.\n");
    } else {
        printf("A expressão não está corretamente balanceada.\n");
    }
    return 0;
}
