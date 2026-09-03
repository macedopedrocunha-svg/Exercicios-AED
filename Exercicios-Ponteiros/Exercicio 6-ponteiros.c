#include <stdio.h>

int soma(int *v, int n) {
    int total = 0;
    
    for (int i = 0; i < n; i++) {
        total += v[i];
    }
    
    return total;
}

int main() {
    int v[] = {10, 20, 30, 40, 50};
    int n = 5;

    int resultado = soma(v, n);

    printf("A soma dos elementos do vetor eh: %d\n", resultado);

    return 0;
}
