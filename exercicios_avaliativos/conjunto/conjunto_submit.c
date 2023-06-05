
#include <stdlib.h>
#include <stdbool.h>

#ifndef CONJUNTO_H
#define CONJUNTO_H

#include <stdbool.h>

#define MAX_ELEMENTOS 100

typedef struct
{
  int elementos[MAX_ELEMENTOS];
  int tamanho;
} Conjunto;

Conjunto *criaConjunto();

void insereElemento(Conjunto *conjunto, int elemento);

void removeElemento(Conjunto *conjunto, int elemento);

bool pertence(Conjunto *conjunto, int elemento);

Conjunto *uniao(Conjunto *conjunto1, Conjunto *conjunto2);

Conjunto *interseccao(Conjunto *conjunto1, Conjunto *conjunto2);

#endif

Conjunto *criaConjunto()
{
  Conjunto *conjunto = malloc(sizeof(Conjunto));
  conjunto->tamanho = 0;
  return conjunto;
}

void insereElemento(Conjunto *conjunto, int elemento)
{
  if (!pertence(conjunto, elemento))
  {
    conjunto->elementos[conjunto->tamanho] = elemento;
    conjunto->tamanho++;
  }
}

void removeElemento(Conjunto *conjunto, int elemento)
{
  int i;
  for (i = 0; i < conjunto->tamanho; i++)
  {
    if (conjunto->elementos[i] == elemento)
    {
      conjunto->tamanho--;
      for (; i < conjunto->tamanho; i++)
      {
        conjunto->elementos[i] = conjunto->elementos[i + 1];
      }
      break;
    }
  }
}

bool pertence(Conjunto *conjunto, int elemento)
{
  int i;
  for (i = 0; i < conjunto->tamanho; i++)
  {
    if (conjunto->elementos[i] == elemento)
    {
      return true;
    }
  }
  return false;
}

Conjunto *uniao(Conjunto *conjunto1, Conjunto *conjunto2)
{
  Conjunto *resultado = criaConjunto();
  int i;

  for (i = 0; i < conjunto1->tamanho; i++)
  {
    insereElemento(resultado, conjunto1->elementos[i]);
  }

  for (i = 0; i < conjunto2->tamanho; i++)
  {
    insereElemento(resultado, conjunto2->elementos[i]);
  }

  return resultado;
}

Conjunto *interseccao(Conjunto *conjunto1, Conjunto *conjunto2)
{
  Conjunto *resultado = criaConjunto();
  int i;

  for (i = 0; i < conjunto1->tamanho; i++)
  {
    if (pertence(conjunto2, conjunto1->elementos[i]))
    {
      insereElemento(resultado, conjunto1->elementos[i]);
    }
  }

  return resultado;
}

#include <stdio.h>

void imprimeConjunto(Conjunto *conjunto)
{
  int i;
  printf("{ ");
  for (i = 0; i < conjunto->tamanho; i++)
  {
    printf("%d ", conjunto->elementos[i]);
  }
  printf("}\n");
}

int main()
{
  Conjunto *conjunto1 = criaConjunto();
  Conjunto *conjunto2 = criaConjunto();
  Conjunto *conjuntoUniao;
  Conjunto *conjuntoInterseccao;

  insereElemento(conjunto1, 1);
  insereElemento(conjunto1, 2);
  insereElemento(conjunto1, 3);

  insereElemento(conjunto2, 2);
  insereElemento(conjunto2, 3);
  insereElemento(conjunto2, 4);

  printf("Conjunto 1: ");
  imprimeConjunto(conjunto1);

  printf("Conjunto 2: ");
  imprimeConjunto(conjunto2);

  int elemento = 2;
  if (pertence(conjunto1, elemento))
  {
    printf("O elemento %d pertence ao conjunto 1\n", elemento);
  }
  else
  {
    printf("O elemento %d não pertence ao conjunto 1\n", elemento);
  }

  conjuntoUniao = uniao(conjunto1, conjunto2);
  printf("União dos conjuntos: ");
  imprimeConjunto(conjuntoUniao);

  conjuntoInterseccao = interseccao(conjunto1, conjunto2);
  printf("Intersecção dos conjuntos: ");
  imprimeConjunto(conjuntoInterseccao);

  return 0;
}
