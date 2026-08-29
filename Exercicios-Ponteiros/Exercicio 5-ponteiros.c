
#include <stdio.h>

void inverter(int *v, int n) {
    int *inicio = v;
    int *fim = v + n - 1;
    int temp;

    while (inicio < fim) {
        temp = *inicio;
        *inicio = *fim;
        *fim = temp;

        inicio++;
        fim--;
    }
}

int main() {
    int v[] = {10, 20, 30, 40, 50};
    int n = 5;

    inverter(v, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    return 0;
}
