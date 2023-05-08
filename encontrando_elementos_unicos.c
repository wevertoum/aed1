#include <stdio.h>

int main()
{
  int qtd_elementos = 0, i = 0, j = 0, count = 0, unique_count = 0;
  printf("Digite a quantidade de elementos: ");
  scanf("%d", &qtd_elementos);
  int elementos[qtd_elementos];
  int unique[qtd_elementos];

  printf("Digite os %d elementos: ", qtd_elementos);
  for (i = 0; i < qtd_elementos; i++)
  {
    scanf("%d", &elementos[i]);
  }

  for (i = 0; i < qtd_elementos; i++)
  {
    count = 0;
    for (j = 0; j < qtd_elementos; j++)
    {
      if (elementos[i] == elementos[j])
      {
        count++;
      }
    }
    if (count == 1)
    {
      unique[unique_count] = elementos[i];
      unique_count++;
    }
  }

  printf("Elementos únicos: ");
  for (i = 0; i < unique_count; i++)
  {
    printf("%d ", unique[i]);
  }

  return 0;
}
