#include <stdio.h>
#include "arvore.h"

int main() {

    Arv *no2 = criar_arv(2, criar_arv_vazia(), criar_arv_vazia());
    Arv *no7 = criar_arv(7, criar_arv_vazia(), criar_arv_vazia());
    Arv *no5 = criar_arv(5, no2, no7);
    Arv *no15 = criar_arv(15, criar_arv_vazia(), criar_arv_vazia());

    Arv *raiz = criar_arv(10, no5, no15);

    int alvos[] = {17, 22, 25, 20};
    for (int i = 0; i < 4; i++) {
        printf("Existe caminho da raiz até uma folha com soma %d? %s\n",
               alvos[i], existeCaminhoSoma(raiz, alvos[i]) ? "Sim" : "Não");
    }

    liberar_arv(raiz);

    return 0;
}
