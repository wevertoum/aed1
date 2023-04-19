#include <stdio.h>

int main()
{
  int linhas = 0;

  printf("Quantas linhas você deseja informar? ");
  scanf("%d", &linhas);
  int numeros[linhas];

  int i = 0;
  for (i = 0; i < linhas; i++)
  {
    int numero = 0;
    printf("Digite o %dº número: ", i + 1);
    scanf("%d", &numero);
    numeros[i] = numero;
  }
  for (i = 0; i < linhas; i++)
  {
    int numero = numeros[i];
    int j = 0;
    int divisores = 0;
    for (j = 1; j <= numero; j++)
    {
      if (numero % j == 0)
      {
        divisores++;
      }
    }
    if (divisores == 2)
    {
      printf("%d primo \n", numero);
    }
    else
    {
      printf("%d composto \n", numero);
    }
  }
  return 0;
}
