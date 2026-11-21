#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

static void lerLinha(char *buf, int n) {
    if (fgets(buf, n, stdin) == NULL) {
        buf[0] = '\0';
        return;
    }
    buf[strcspn(buf, "\n")] = '\0';
}

static void mostrarAtual(PilhaStr *pilha) {
    ElemStr e = popString(pilha);
    pushString(pilha, e);
    printf("Página atual: %s\n", e.texto);
}

int main(void) {
    PilhaStr *historico = createString();
    char linha[256];
    int op;
    do {
        printf("\n1 - Visitar página\n2 - Voltar\n3 - Página atual\n4 - Histórico\n0 - Sair\nOpção: ");
        lerLinha(linha, sizeof(linha));
        op = atoi(linha);
        switch (op) {
            case 1: {
                ElemStr e;
                printf("Visitar: ");
                lerLinha(e.texto, sizeof(e.texto));
                if (e.texto[0] != '\0') {
                    pushString(historico, e);
                }
                break;
            }
            case 2:
                if (sizeString(historico) < 2) {
                    printf("Não há página anterior.\n");
                } else {
                    popString(historico);
                    mostrarAtual(historico);
                }
                break;
            case 3:
                if (emptyString(historico)) {
                    printf("Nenhuma página visitada.\n");
                } else {
                    mostrarAtual(historico);
                }
                break;
            case 4:
                printString(historico);
                break;
            case 0:
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (op != 0);
    destroyString(historico);
    return 0;
}
