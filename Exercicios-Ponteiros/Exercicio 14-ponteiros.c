#include <stdio.h>
#include <stdlib.h>

int *intercalar(int *v1, int *v2, int n, int *n3) {
    *n3 = 2 * n;
    
    int *res = (int *) malloc((*n3) * sizeof(int));
    if (res == NULL) return NULL;

    for (int i = 0; i < n; i++) {
        res[2 * i]     = v1[i];
        res[2 * i + 1] = v2[i];
    }

    return res;
}

int main() {
    int n = 3;
    int v1[] = {10, 20, 30};
    int v2[] = {40, 50, 60};
    int n3;

    int *resultado = intercalar(v1, v2, n, &n3);

    if (resultado != NULL) {
        printf("Resultado: ");
        for (int i = 0; i < n3; i++) {
            printf("%d ", resultado[i]);
        }
        printf("\n");

        free(resultado);
    }

    return 0;
}
