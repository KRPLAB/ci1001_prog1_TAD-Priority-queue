#include <stdio.h>
#include <stdlib.h>
#include "lef.h"

struct evento_t *cria_evento(int tempo, int tipo, int dado1, int dado2)
{
    struct evento_t *event;

    if (!(event = malloc(sizeof(struct evento_t))))
        return NULL;

    event->tempo = tempo;
    event->tipo = tipo;
    event->dado1 = dado1;
    event->dado2 = dado2;

    return event;
}

struct evento_t *destroi_evento(struct evento_t *e)
{
    free(e);
    return NULL;
}

struct lef_t *cria_lef()
{
    struct lef_t *lef;

    if (!(lef = malloc(sizeof(struct lef_t))))
        return NULL;

    lef->primeiro = NULL;

    return lef;
}

int vazia_lef(struct lef_t *l)
{
    return !l->primeiro;
}

struct lef_t *destroi_lef(struct lef_t *l)
{
    struct nodo_lef_t *aux;

    while (!vazia_lef(l))
    {
        aux = l->primeiro;
        l->primeiro = l->primeiro->prox;
        aux->evento = destroi_evento(aux->evento);
        free(aux);
    }

    free(l);

    return NULL;
}