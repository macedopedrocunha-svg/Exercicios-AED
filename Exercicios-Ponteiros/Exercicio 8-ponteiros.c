#include <stdio.h>

void min_max(int *v, int n, int *min, int *max) {
    if (n <= 0) return;

    *min = *v;
    *max = *v;

    for (int *p = v + 1; p < v + n; p++) {
        if (*p < *min) {
            *min = *p;
        }
        if (*p > *max) {
            *max = *p;
        }
    }
}

int main() {
    int v[] = {35, 12, 89, 4, 56, 23};
    int n = 6;
    int menor, maior;

    min_max(v, n, &menor, &maior);

    printf("Menor elemento: %d\n", menor);
    printf("Maior elemento: %d\n", maior);

    return 0;
}
