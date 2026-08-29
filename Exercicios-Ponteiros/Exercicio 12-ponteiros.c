#include <stdio.h>
#include <stdlib.h>

        int *inserir(int *v, int *n, int valor) {
            int *res = (int *)realloc(v, (*n +1) * sizeof(int));
            if (res == NULL) {
                printf("Erro ao realocar memoria.\n");
            } else {
                res[*n] = valor;
                (*n)++;
            }
            return res;
        }

        int main() {
            int n = 0;
            int *v = NULL;
            printf("Digite os elementos do vetor (digite -1 para parar): ");
            while (1) {
                int valor;
                scanf("%d", &valor);
                if (valor == -1) {
                    break;
                }
                v = inserir(v, &n, valor);
        }
         
            printf("Vetor final: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", v[i]);
            }
            printf("\n");

            free(v);
            return 0;
        }
