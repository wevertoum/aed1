#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int *elementos;
  int tamanho;
} Conjunto;

Conjunto *criaConjunto(int tamanho)
{
  Conjunto *conjunto = malloc(sizeof(Conjunto));
  conjunto->elementos = malloc(tamanho * sizeof(int));
  conjunto->tamanho = tamanho;
  return conjunto;
}

void destroiConjunto(Conjunto *conjunto)
{
  free(conjunto->elementos);
  free(conjunto);
}

int pertenceConjunto(Conjunto *conjunto, int elemento)
{
  int i;
  for (i = 0; i < conjunto->tamanho; i++)
  {
    if (conjunto->elementos[i] == elemento)
    {
      return 1;
    }
  }
  return 0;
}

Conjunto *uniaoConjuntos(Conjunto *conjunto1, Conjunto *conjunto2)
{
  int tamanhoUniao = conjunto1->tamanho + conjunto2->tamanho;
  Conjunto *uniao = criaConjunto(tamanhoUniao);

  int index = 0;
  int i;
  for (i = 0; i < conjunto1->tamanho; i++)
  {
    uniao->elementos[index] = conjunto1->elementos[i];
    index++;
  }

  int j;
  for (j = 0; j < conjunto2->tamanho; j++)
  {
    if (!pertenceConjunto(conjunto1, conjunto2->elementos[j]))
    {
      uniao->elementos[index] = conjunto2->elementos[j];
      index++;
    }
  }

  uniao->tamanho = index;

  return uniao;
}

Conjunto *intersecaoConjuntos(Conjunto *conjunto1, Conjunto *conjunto2)
{
  int tamanhoIntersecao = 0;
  Conjunto *intersecao = criaConjunto(tamanhoIntersecao);

  int i;
  for (i = 0; i < conjunto1->tamanho; i++)
  {
    if (pertenceConjunto(conjunto2, conjunto1->elementos[i]))
    {
      intersecao->elementos = realloc(intersecao->elementos, (tamanhoIntersecao + 1) * sizeof(int));
      intersecao->elementos[tamanhoIntersecao] = conjunto1->elementos[i];
      tamanhoIntersecao++;
    }
  }

  intersecao->tamanho = tamanhoIntersecao;

  return intersecao;
}

int main()
{
  int n1, n2;
  scanf("%d", &n1);

  Conjunto *conjunto1 = criaConjunto(n1);
  int i;
  for (i = 0; i < n1; i++)
  {
    scanf("%d", &conjunto1->elementos[i]);
  }

  scanf("%d", &n2);

  Conjunto *conjunto2 = criaConjunto(n2);
  int j;
  for (j = 0; j < n2; j++)
  {
    scanf("%d", &conjunto2->elementos[j]);
  }

  int t;
  scanf("%d", &t);

  for (i = 0; i < t; i++)
  {
    int operacao, elemento;
    scanf("%d", &operacao);

    switch (operacao)
    {
    case 1:
      scanf("%d", &elemento);
      if (pertenceConjunto(conjunto1, elemento))
      {
        printf("S\n");
      }
      else
      {
        printf("N\n");
      }
      break;

    case 2:
      scanf("%d", &elemento);
      if (pertenceConjunto(conjunto2, elemento))
      {
        printf("S\n");
      }
      else
      {
        printf("N\n");
      }
      break;

    case 3:
    {
      Conjunto *uniao = uniaoConjuntos(conjunto1, conjunto2);
      for (j = 0; j < uniao->tamanho; j++)
      {
        printf("%d ", uniao->elementos[j]);
      }
      printf("\n");
      destroiConjunto(uniao);
    }
    break;

    case 4:
    {
      Conjunto *intersecao = intersecaoConjuntos(conjunto1, conjunto2);
      for (j = 0; j < intersecao->tamanho; j++)
      {
        printf("%d ", intersecao->elementos[j]);
      }
      printf("\n");
      destroiConjunto(intersecao);
    }
    break;
    }
  }

  destroiConjunto(conjunto1);
  destroiConjunto(conjunto2);

  return 0;
}
