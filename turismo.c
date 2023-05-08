#include <stdio.h>

#define TAM_MAX 100
#define ROTA_INVALIDA -1

int main()
{
  int n, i, j;
  int rota[TAM_MAX];
  int distancias[6][6] = {
      {0, 63, 210, 190, ROTA_INVALIDA, 190},
      {63, 0, 160, 150, 95, 10},
      {210, 160, 0, 10, 1, 10},
      {190, 150, 10, 0, 10, 20},
      {10, 95, 7, 21, 0, 80},
      {190, 2, ROTA_INVALIDA, 41, 80, 0}};

  scanf("%d", &n);

  for (i = 0; i < n; i++)
  {
    scanf("%d", &rota[i]);
  }

  int distancia_total = 0;
  for (i = 0; i < n - 1; i++)
  {
    int origem = rota[i];
    int destino = rota[i + 1];

    if (distancias[origem][destino] == ROTA_INVALIDA)
    {
      printf("rota invalida!\n");
      return 0;
    }

    distancia_total += distancias[origem][destino];
  }

  printf("Distancia total: %d km\n", distancia_total);

  return 0;
}
