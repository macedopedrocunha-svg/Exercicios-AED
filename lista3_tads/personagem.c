#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "personagem.h"

struct Personagem {
    char *nome;
    int vida;
    int vida_maxima;
    int ataque;
    int defesa;
};

Personagem *personagem_cria(char *nome, int vida, int ataque, int defesa) {
    Personagem *p = (Personagem*)malloc(sizeof(Personagem));

    if (p == NULL) {
        printf("Erro ao alocar memoria para o personagem.\n");
        exit(1);
    }

    p->nome = (char*)malloc(strlen(nome) + 1);
    if (p->nome == NULL) {
        printf("Erro ao alocar memoria para o nome do personagem.\n");
        free(p);
        exit(1);
    }

    strcpy(p->nome, nome);

    p->vida = vida;
    p->vida_maxima = vida;
    p->ataque = ataque;
    p->defesa = defesa;

    return p;
}

void personagem_atacar(Personagem *atacante, Personagem *alvo) {
    if (atacante == NULL || alvo == NULL) {
        return;
    }

    int dano = atacante->ataque - alvo->defesa;
    if (dano < 1) {
        dano = 1; 
    }

    alvo->vida -= dano;
    
    if (alvo->vida < 0) {
        alvo->vida = 0;
    }

    printf("%s atacou %s causando %d de dano!\n", atacante->nome, alvo->nome, dano);
}

void personagem_curar(Personagem *p, int quantidade) {
    if (p == NULL) {
        return;
    }

    p->vida += quantidade;
    if (p->vida > p->vida_maxima) {
        p->vida = p->vida_maxima;
    }
}

int personagem_vivo(Personagem *p) {
    if (p == NULL) {
        return 0;
    }

    return p->vida > 0;
}

void personagem_status(Personagem *p) {
    if (p == NULL) {
        return;
    }

    printf("-> [%s] Vida: %d/%d | Ataque: %d | Defesa: %d | Status: %s\n",
           p->nome, p->vida, p->vida_maxima, p->ataque, p->defesa,
           personagem_vivo(p) ? "Vivo" : "Derrotado");
}

void personagem_libera(Personagem *p) {
    if (p == NULL) {
        return;
    }

    free(p->nome);
    free(p);
}