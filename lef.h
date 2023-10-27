/* Implementa o TAD Lista de Eventos Futuros (LEF)
 * Feito em C para a disciplina CI1001 - Programacao 1
 * Autor: Luis C. E. Bona
 *
 * Versao 1.0.0 10/11/2021
 * Versao 1.0.1 16/08/2022
 * Versao 2.0.0 14/12/2022
 * Versao 2.1.0 05/10/2023
 */

/* A  LEF é uma lista que armazena eventos ordenados pelo membro tempo
 * do tipo evento_t. Cada evento pode ter um tipo e armazenar em dados
 * diferentes estruturas de dados que permitem descrever cada evento. */

#ifndef _LEF_H
#define _LEF_H

/*
 * evento_t possui os dados que descrevem os eventos
 */
struct evento_t
{
    int tempo; /* tempo logico do evento */
    int tipo;  /* inteiro para diferenciar os diferentes tipos de evento */
    int dado1; /* um inteiro para guardar dados do evento */
    int dado2; /* um inteiro para guardar dados do evento */
};

/*
 * nodo_t eh uma estrutura interna que representa cada nodo da LEF.
 * Externamente o usuario da biblioteca nao vai receber essa estrutura para
 * evitar acesso direto ao ponteiro prox.
 */
struct nodo_lef_t
{
    struct evento_t *evento;
    struct nodo_lef_t *prox;
};

/*
 * Representacao da LEF
 */
struct lef_t
{
    struct nodo_lef_t *primeiro;
};

/*
 * Cria um evento contendo os parâmetros informados.
 * Retorna um ponteiro para o evento ou NULL se falhar.
 */
struct evento_t *cria_evento(int tempo, int tipo, int dado1, int dado2);

/*
 * Destroi um evento e retorna NULL.
 */
struct evento_t *destroi_evento(struct evento_t *e);

/*
 * Cria uma LEF vazia
 * Retorna um ponteiro para a LEF ou NULL se falhar.
 */
struct lef_t *cria_lef();

/*
 * Destroi a LEF, liberando a memória ocupada por ela, inclusive os eventos.
 * Retorna NULL.
 */
struct lef_t *destroi_lef(struct lef_t *l);

/*
 * Insere o evento apontado na LEF na ordem de tempos crescentes.
 * Eventos com o mesmo tempo devem respeitar a politica FIFO.
 * Retorna 1 em caso de sucesso ou 0 caso contrario.
 */
int insere_lef(struct lef_t *l, struct evento_t *e);

/*
 * Retira o primeiro evento da LEF.
 * Retorna ponteiro para o evento ou NULL se falhar.
 */
struct evento_t *retira_lef(struct lef_t *l);

/*
 * Informa se a LEF está vazia.
 * Retorna 1 se vazia e 0 senao ou se falhar.
 */
int vazia_lef(struct lef_t *l);

/*
 * Imprime a LEF. Não faz parte do TAD, mas serve para depuração.
 * Formato de saída:
 * tempo tipo dado1 dado2
 * tempo tipo dado1 dado2
 * ...
 * total XX eventos
 */
void imprime_lef(struct lef_t *l);

#endif
