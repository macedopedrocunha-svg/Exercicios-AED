#include <stdio.h>

#include "personagem.h"

int main(void) {
    Personagem *heroi = personagem_cria("Cavaleiro", 120, 25, 5);
    Personagem *vilao = personagem_cria("Orc Corrompido", 100, 30, 8);

    printf("=== Status inicial dos combatentes ===\n");
    personagem_status(heroi);
    personagem_status(vilao);

    printf("\n=== Inicio do Combate ===\n");
    while (personagem_vivo(heroi) && personagem_vivo(vilao)) {
        personagem_atacar(heroi, vilao);
        personagem_status(vilao);

        if (!personagem_vivo(vilao)) {
            break;
        }

        printf("\n");
        personagem_atacar(vilao, heroi);
        personagem_status(heroi);
        printf("\n");
    }

    printf("\n=== Resultado Final ===\n");
    if (personagem_vivo(heroi)) {
        printf("O heroi %s triunfou sobre o mal!\n", "Cavaleiro");
        
        printf("\n=== Evento de Cura ===\n");
        personagem_curar(heroi, 40);
        personagem_status(heroi);
    } else {
        printf("O vilao venceu a batalha...\n");
    }

    personagem_libera(heroi);
    personagem_libera(vilao);

    return 0;
}