#include <stdio.h>

int main()
{
  int a = 0;
  printf("Digite o ano em que estamos: ");
  scanf("%d", &a);
  
  if (a < 0 || a > 10000)
  {
    printf("O ano digitado é inválido");
  }
  else
  {
    int nextYear = a + (76 - ((a - 1986) % 76));
    if ((nextYear - 1986) % 4 == 0 && (nextYear - 1986) % 100 != 0 || (nextYear - 1986) % 400 == 0)
    {
      printf("O próximo ano que Halley será visível será em %d (ano bissexto)", nextYear);
    }
    else
    {
      printf("O próximo ano que Halley será visível será em %d", nextYear);
    }
  }
  return 0;
}
