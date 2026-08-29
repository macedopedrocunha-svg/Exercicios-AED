#include <stdio.h>
#include <stdlib.h>

int main() {
    int *v = NULL;
    int qtd = 0;
    int num;

    while (1) {
        printf("Digite um numero inteiro (-1 para encerrar): ");
        scanf("%d", &num);

        if (num == -1) {
            break;
        }

        int *temp = (int *) realloc(v, (qtd + 1) * sizeof(int));
        if (temp == NULL) {
            printf("Erro de alocacao de memoria.\n");
            free(v);
            return 1;
        }
        v = temp;

        v[qtd] = num;
        qtd++;
    }

    if (qtd == 0) {
        printf("\nNenhum numero foi inserido.\n");
        free(v);
        return 0;
    }

    int menor = v[0];
    int maior = v[0];

    printf("\nValores armazenados: ");
    for (int i = 0; i < qtd; i++) {
        printf("%d ", v[i]);

        if (v[i] < menor) {
            menor = v[i];
        }
        if (v[i] > maior) {
            maior = v[i];
        }
    }

    printf("\nQuantidade de elementos: %d\n", qtd);
    printf("Maior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);

    free(v);
    v = NULL;

    return 0;
}
