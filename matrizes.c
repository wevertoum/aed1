#include <stdio.h>

int main()
{
  int linhas, colunas, i, j;
  printf("Informe a quantidade de linhas da matriz: ");
  scanf("%d", &linhas);
  printf("Informe a quantidade de colunas da matriz: ");
  scanf("%d", &colunas);

  int matriz1[linhas][colunas];
  for (i = 0; i < linhas; i++)
  {
    for (j = 0; j < colunas; j++)
    {
      printf("matriz 1 - Digite o valor da linha %d e coluna %d: ", i + 1, j + 1);
      scanf("%d", &matriz1[i][j]);
    }
  }
  printf("Informe a operação que deseja realizar com as duas matrizes (+ ou x): \n");
  char operacao;
  scanf(" %c", &operacao);
  int matriz2[linhas][colunas];
  for (i = 0; i < linhas; i++)
  {
    for (j = 0; j < colunas; j++)
    {
      printf("matriz 2 - Digite o valor da linha %d e coluna %d: ", i + 1, j + 1);
      scanf("%d", &matriz2[i][j]);
    }
  }
  // realiza a operação inserida
  if (operacao == '+')
  {
    for (i = 0; i < linhas; i++)
    {
      for (j = 0; j < colunas; j++)
      {
        printf("%d ", matriz1[i][j] + matriz2[i][j]);
      }
      printf("\n");
    }
  }
  else if (operacao == 'x')
  {
    for (i = 0; i < linhas; i++)
    {
      for (j = 0; j < colunas; j++)
      {
        printf("%d ", matriz1[i][j] * matriz2[i][j]);
      }
      printf("\n");
    }
  }
  else
  {
    printf("Operação inválida");
  }
}
