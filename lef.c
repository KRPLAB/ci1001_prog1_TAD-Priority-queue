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

int insere_lef(struct lef_t *l, struct evento_t *e)
{
    struct nodo_lef_t *novo, *aux, *ant;

    if (!(novo = malloc(sizeof(struct nodo_lef_t))))
        return 0;

    novo->evento = e;

    if (vazia_lef(l) || e->tempo < l->primeiro->evento->tempo)
    {
        novo->prox = l->primeiro;
        l->primeiro = novo;
        return 1;
    }

    aux = l->primeiro;
    ant = NULL;
    while (aux != NULL && e->tempo >= aux->evento->tempo)
    {
        ant = aux;
        aux = aux->prox;
    }

    if (ant != NULL)
        ant->prox = novo;

    novo->prox = aux;

    return 1;
}

struct evento_t *retira_lef(struct lef_t *l)
{
    struct nodo_lef_t *primeiro_nodo = l->primeiro;
    struct evento_t *evento_aux = primeiro_nodo->evento;

    if (vazia_lef(l))
        return NULL;

    primeiro_nodo = l->primeiro;
    evento_aux = primeiro_nodo->evento;
    l->primeiro = primeiro_nodo->prox;

    free(primeiro_nodo);

    return evento_aux;
}

void imprime_lef(struct lef_t *l)
{
    struct nodo_lef_t *nodo = l->primeiro;
    int total_eventos = 0;

    printf("LEF:\n");

    while (nodo != NULL)
    {
        struct evento_t *evento = nodo->evento;
        printf("  tempo %d tipo %d d1 %d d2 %d\n", evento->tempo, evento->tipo, evento->dado1, evento->dado2);
        nodo = nodo->prox;
        total_eventos++;
    }

    printf("  Total %d eventos\n", total_eventos);
}