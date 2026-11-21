#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila_circular.h"

static void lerLinha(char *buf, int n) {
    if (fgets(buf, n, stdin) == NULL) {
        buf[0] = '\0';
        return;
    }
    buf[strcspn(buf, "\n")] = '\0';
}

int main(void) {
    FilaCircular *fila = createCircular();
    int proximo = 1;
    char linha[128];
    int op;
    do {
        printf("\n1 - Cadastrar cliente\n2 - Chamar próximo cliente\n3 - Consultar próximo cliente\n4 - Exibir clientes aguardando\n0 - Sair\nOpção: ");
        lerLinha(linha, sizeof(linha));
        op = atoi(linha);
        switch (op) {
            case 1:
                if (fullCircular(fila)) {
                    printf("Fila cheia. Não é possível cadastrar um novo cliente.\n");
                } else {
                    Cliente c;
                    c.numero = proximo++;
                    printf("Nome do cliente: ");
                    lerLinha(c.nome, sizeof(c.nome));
                    enqueueCircular(fila, c);
                    printf("Cliente cadastrado: %d - %s\n", c.numero, c.nome);
                }
                break;
            case 2:
                if (emptyCircular(fila)) {
                    printf("Nenhum cliente aguardando.\n");
                } else {
                    Cliente c = dequeueCircular(fila);
                    printf("Atendendo: %d - %s\n", c.numero, c.nome);
                }
                break;
            case 3:
                if (emptyCircular(fila)) {
                    printf("Nenhum cliente aguardando.\n");
                } else {
                    Cliente c = peekCircular(fila);
                    printf("Próximo cliente: %d - %s\n", c.numero, c.nome);
                }
                break;
            case 4:
                printf("Clientes aguardando:\n");
                printCircular(fila);
                break;
            case 0:
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (op != 0);
    destroyCircular(fila);
    return 0;
}
