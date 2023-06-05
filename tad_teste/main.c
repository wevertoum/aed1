#include <stdio.h>
#include "soma_valores.h"

int main()
{
  int a = 2;
  int b = 3;
  int resultado;

  resultado = somavaloresfunc(a, b);

  printf("A soma de %d e %d eh %d\n", a, b, resultado);

  return 0;
}