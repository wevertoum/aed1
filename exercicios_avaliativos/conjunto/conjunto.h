#ifndef CONJUNTO_H
#define CONJUNTO_H

#include <stdbool.h>

#define MAX_ELEMENTOS 100

typedef struct {
    int elementos[MAX_ELEMENTOS];
    int tamanho;
} Conjunto;

Conjunto* criaConjunto();

void insereElemento(Conjunto* conjunto, int elemento);

void removeElemento(Conjunto* conjunto, int elemento);

bool pertence(Conjunto* conjunto, int elemento);

Conjunto* uniao(Conjunto* conjunto1, Conjunto* conjunto2);

Conjunto* interseccao(Conjunto* conjunto1, Conjunto* conjunto2);

#endif
