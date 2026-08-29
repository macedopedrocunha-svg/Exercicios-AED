#include <stdio.h>
#include <stdlib.h>

int *copia_vetor(int *v, int n) {
    if (n <= 0 || v == NULL) return NULL;

    int *novo = (int *) malloc(n * sizeof(int));
    if (novo == NULL) return NULL;

    for (int i = 0; i < n; i++) {
        *(novo + i) = *(v + i);
    }

    return novo;
}

int main() {
    int v[] = {10, 20, 30, 40, 50};
    int n = 5;

    int *copia = copia_vetor(v, n);

    if (copia != NULL) {
        printf("Vetor original: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", v[i]);
        }

        printf("\nVetor copiado:  ");
        for (int i = 0; i < n; i++) {
            printf("%d ", copia[i]);
        }
        printf("\n");

        free(copia);
    }

    return 0;
}
