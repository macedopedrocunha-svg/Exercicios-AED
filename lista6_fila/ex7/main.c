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
    FilaCliente *fila = createCliente();
    int proxima = 1;
    char linha[128];
    int op;
    do {
        printf("\n1 - Gerar nova senha\n2 - Chamar próxima senha\n3 - Consultar próxima senha\n4 - Quantidade aguardando\n5 - Exibir fila\n0 - Sair\nOpção: ");
        lerLinha(linha, sizeof(linha));
        op = atoi(linha);
        switch (op) {
            case 1: {
                Cliente c;
                c.numero = proxima++;
                printf("Nome: ");
                lerLinha(c.nome, sizeof(c.nome));
                enqueueCliente(fila, c);
                printf("Senha gerada: %d - %s\n", c.numero, c.nome);
                break;
            }
            case 2:
                if (emptyCliente(fila)) {
                    printf("Nenhuma senha aguardando.\n");
                } else {
                    Cliente c = dequeueCliente(fila);
                    printf("Chamando senha: %d - %s\n", c.numero, c.nome);
                }
                break;
            case 3:
                if (emptyCliente(fila)) {
                    printf("Nenhuma senha aguardando.\n");
                } else {
                    Cliente c = peekCliente(fila);
                    printf("Próxima senha: %d - %s\n", c.numero, c.nome);
                }
                break;
            case 4:
                printf("Aguardando atendimento: %d\n", sizeCliente(fila));
                break;
            case 5:
                printCliente(fila);
                break;
            case 0:
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (op != 0);
    destroyCliente(fila);
    return 0;
}
