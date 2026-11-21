#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

static void lerLinha(char *buf, int n) {
    if (fgets(buf, n, stdin) == NULL) {
        buf[0] = '\0';
        return;
    }
    buf[strcspn(buf, "\n")] = '\0';
}

int main(void) {
    FilaDocumento *fila = createDocumento();
    int proximoId = 1;
    char linha[128];
    int op;
    do {
        printf("\n1 - Adicionar documento\n2 - Imprimir próximo documento\n3 - Exibir documentos aguardando\n0 - Sair\nOpção: ");
        lerLinha(linha, sizeof(linha));
        op = atoi(linha);
        switch (op) {
            case 1: {
                Documento d;
                d.id = proximoId++;
                printf("Nome do documento: ");
                lerLinha(d.nome, sizeof(d.nome));
                printf("Número de páginas: ");
                lerLinha(linha, sizeof(linha));
                d.paginas = atoi(linha);
                enqueueDocumento(fila, d);
                printf("Documento adicionado: ID=%d, Nome=\"%s\", Páginas=%d.\n", d.id, d.nome, d.paginas);
                break;
            }
            case 2:
                if (emptyDocumento(fila)) {
                    printf("Nenhum documento aguardando.\n");
                } else {
                    Documento d = dequeueDocumento(fila);
                    printf("Imprimindo: %s (%d páginas).\n", d.nome, d.paginas);
                }
                break;
            case 3:
                printf("Documentos aguardando:\n");
                printDocumento(fila);
                break;
            case 0:
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (op != 0);
    destroyDocumento(fila);
    return 0;
}
