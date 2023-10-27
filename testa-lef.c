// TAD lista de números inteiros - programa de teste
// Carlos Maziero - DINF/UFPR, Set 2023

#include <stdio.h>
#include <stdlib.h>
#include "lef.h"

int main()
{
    struct lef_t *l;
    struct evento_t *ev;

    // cria uma lista L vazia
    l = cria_lef();

    // imprime L
    imprime_lef(l);

    // insere eventos na LEF
    for (int i = 0; i < 4; i++)
    {
        ev = cria_evento(i, 0, 0, 0);
        insere_lef(l, ev);
    }

    // imprime L
    imprime_lef(l);

    // insere mais eventos na LEF
    for (int i = 2; i < 6; i++)
    {
        ev = cria_evento(i, 1, 1, 1);
        insere_lef(l, ev);
    }

    // imprime L
    imprime_lef(l);

    // enquanto L não estiver vazia
    while (!vazia_lef(l))
    {
        //   retira o primeiro evento de L
        ev = retira_lef(l);
        if (ev)
            printf("retirei evento %d %d %d %d\n", ev->tempo, ev->tipo,
                   ev->dado1, ev->dado2);
        else
            printf("sem evento\n");
        destroi_evento(ev);

        // imprime L
        imprime_lef(l);
    }

    // destrói L
    l = destroi_lef(l);

    // encerra
    return (0);
}
