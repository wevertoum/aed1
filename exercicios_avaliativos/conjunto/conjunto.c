#include "conjunto.h"
#include <stdlib.h>
#include <stdbool.h>

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
