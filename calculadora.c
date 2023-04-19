#include <stdio.h>

int main()
{
  int x, y, operacao, i, potencia = 1;
  printf("Digite o primeiro valor: ");
  scanf("%d", &x);
  printf("Digite o segundo valor: ");
  scanf("%d", &y);
  printf("Digite a operação desejada: \n");
  printf("1 - calcula a potencia de x elevado a y \n");
  printf("2 - calcula a multiplicação de x por y \n");
  printf("3 - calcula a divisão de x por y \n");
  scanf("%d", &operacao);
  switch (operacao)
  {
  case 1:
    for (i = 0; i < y; i++)
    {
      potencia = potencia * x;
    }
    printf("O resultado é 1: %d", potencia);
    break;
  case 2:
    printf("O resultado é 2: %d", x * y);
    break;
  case 3:
    printf("O resultado é 3: %d", x / y);
    break;
  default:
    printf("Operação inválida");
  }
}