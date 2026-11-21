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
    int proximo = 101;
    char linha[128];
    int op;
    do {
        printf("\n1 - Cadastrar paciente\n2 - Chamar próximo paciente\n3 - Consultar próximo paciente\n4 - Exibir pacientes aguardando\n0 - Sair\nOpção: ");
        lerLinha(linha, sizeof(linha));
        op = atoi(linha);
        switch (op) {
            case 1: {
                Cliente p;
                p.numero = proximo++;
                printf("Nome do paciente: ");
                lerLinha(p.nome, sizeof(p.nome));
                enqueueCliente(fila, p);
                printf("Paciente cadastrado: %d - %s\n", p.numero, p.nome);
                break;
            }
            case 2:
                if (emptyCliente(fila)) {
                    printf("Nenhum paciente aguardando.\n");
                } else {
                    Cliente p = dequeueCliente(fila);
                    printf("Atendendo: %d - %s\n", p.numero, p.nome);
                }
                break;
            case 3:
                if (emptyCliente(fila)) {
                    printf("Nenhum paciente aguardando.\n");
                } else {
                    Cliente p = peekCliente(fila);
                    printf("Próximo paciente: %d - %s\n", p.numero, p.nome);
                }
                break;
            case 4:
                printf("Pacientes aguardando:\n");
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
