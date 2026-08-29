#include <stdio.h>

int soma(int *v, int n) {
    int s = 0;
    int *p = v;
    int *fim = v + n;

    while (p < fim) {
        s += *p;
        p++;
    }

    return s;
}

