#include <stdio.h>
#include <stdlib.h>

int *concatenar(int *v1, int n1, int *v2, int n2, int *n3) {
    int x = n1 + n2;
    *n3 = x;
    int *res = (int *)malloc(x * sizeof(int));
        for (int i =0; i < n1; i++) {
            res[i] = v1[i];
        }
            for (int i=0; i < n2; i++) {
            res[n1 +i] = v2[i];

            }
        return res;

    }

    int main() {

        int n1, n2, n3;
        int *v1, *v2, *res;

        printf("Digite o tamanho do primeiro vetor: ");
        scanf("%d", &n1);
        v1 = (int *)malloc(n1 * sizeof(int));
        printf("Digite os elementos do primeiro vetor: ");
        
        for (int i = 0; i < n1; i++) {
            scanf("%d", &v1[i]);
        }

        printf("Digite o tamanho do segundo vetor: ");
        scanf("%d", &n2);
        v2 = (int *)malloc(n2 * sizeof(int));
        printf("Digite os elementos do segundo vetor: ");

        for( int i = 0; i< n2; i++) {
            scanf("%d", &v2[i]);
        }
        res = concatenar(v1, n1, v2, n2, &n3);
        printf("Tamanho concatenado do: %d\n", n3);
        printf("Vetor concatenado: ");
        for (int i = 0; i < n3; i++) {
            printf("%d ", res[i]);
        }


        return 0;
        free(v1);
        free(v2);
        free(res);

    }
