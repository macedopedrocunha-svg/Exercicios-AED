#include <stdio.h>
        #include <stdlib.h>

        int *remover(int **v, int *n, int posicao) {
            if (posicao < 0 || posicao >= *n) {
                printf("Posição inválida.\n");
                return *v;
            } else {
                for (int i = posicao; i < *n -1; i++) {
                    (*v)[i] = (*v)[i +1];
                }
                (*n)--;
                int *res = (int *)realloc(*v, (*n) * sizeof(int));
                if (res == NULL && *n > 0) {
                    printf("Erro ao realocar memória.\n");
                    return *v;
                } else {
                    *v = res;
                    return *v;
                }
            }
        }

        int main() {
            int n = 0;
            int *v = NULL;
            printf("Digite os elementos do vetor (digite -1 para parar): '\n");
            while (1) {
                int valor;
                scanf("%d", &valor);
                if (valor == -1) {
                    break;
                }else {
                    int *res = (int *)realloc(v, (n + 1) * sizeof(int));
                    if (res == NULL) {
                        printf("Erro ao realocar memória.\n");
                        free(v);
                        return 1;
                    } else {
                        v = res;
                        v[n] = valor;
                        n++;
                    }
                }
        }
        
            printf("Vetor final: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", v[i]);
            }
            printf("\n");

            int posicao;
            printf("Digite a posição do elemento a ser removido (sendo 0 a posição inicial):  ");
            scanf("%d", &posicao);
            v = remover(&v, &n, posicao);

            printf("Vetor após remoção: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", v[i]);
            }
            printf("\n");

            free(v);
            return 0;
        }
