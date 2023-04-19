#include <stdio.h>

int main()
{
  int linhas, colunas, i, j;
  printf("Informe a quantidade de linhas e colunas: ");
  scanf("%d %d", &linhas, &colunas);
  int matriz[linhas][colunas];
  for (i = 0; i < linhas; i++)
  {
    for (j = 0; j < colunas; j++)
    {
      printf("Digite o valor da linha %d e coluna %d: ", i + 1, j + 1);
      scanf("%d", &matriz[i][j]);
    }
  }
  printf("A matriz digitada é: \n");
}
