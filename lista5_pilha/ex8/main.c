#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilhanum.h"

static int avaliar(const char *expr, double *resultado) {
    char copia[512];
    strncpy(copia, expr, sizeof(copia) - 1);
    copia[sizeof(copia) - 1] = '\0';

    PilhaNum *pilha = createNum();
    int ok = 1;
    for (char *tok = strtok(copia, " \t"); tok != NULL && ok; tok = strtok(NULL, " \t")) {
        if (strcmp(tok, "=") == 0) {
            continue;
        }
        if (strlen(tok) == 1 && strchr("+-*/", tok[0]) != NULL) {
            if (sizeNum(pilha) < 2) {
                ok = 0;
                break;
            }
            double b = popNum(pilha);
            double a = popNum(pilha);
            double r = 0;
            if (tok[0] == '+') {
                r = a + b;
            } else if (tok[0] == '-') {
                r = a - b;
            } else if (tok[0] == '*') {
                r = a * b;
            } else {
                if (b == 0) {
                    ok = 0;
                    break;
                }
                r = a / b;
            }
            pushNum(pilha, r);
        } else {
            char *fim;
            double v = strtod(tok, &fim);
            if (*fim != '\0') {
                ok = 0;
                break;
            }
            pushNum(pilha, v);
        }
    }
    if (ok && sizeNum(pilha) == 1) {
        *resultado = popNum(pilha);
    } else {
        ok = 0;
    }
    destroyNum(pilha);
    return ok;
}

int main(void) {
    char linha[512];
    while (1) {
        printf("Entrada (string): ");
        if (fgets(linha, sizeof(linha), stdin) == NULL) {
            break;
        }
        linha[strcspn(linha, "\n")] = '\0';
        if (linha[0] == '\0') {
            break;
        }
        double r;
        if (avaliar(linha, &r)) {
            printf("Saída: %.10g\n", r);
        } else {
            printf("Expressão inválida.\n");
        }
    }
    return 0;
}
