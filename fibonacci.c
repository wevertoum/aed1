#include <stdio.h>

int fibonacci(int n);

int main()
{
  int linhas = 0;

  printf("Quantas linhas você deseja informar para calcular o fibonacci? ");
  scanf("%d", &linhas);

  if (linhas < 1 || linhas > 10)
  {
    printf("O número de linhas deve ser entre 1 e 10");
    return 0;
  }

  int numeros[linhas];

  int i = 0;
  for (i = 0; i < linhas; i++)
  {
    int numero = 0;
    printf("Digite o %dº número: ", i + 1);
    scanf("%d", &numero);
    if (numero < 3 || numero > 100)
    {
      printf("O número deve ser entre 3 e 100");
      return 0;
    }
    numeros[i] = numero;
  }

  for (i = 0; i < linhas; i++)
  {
    int resultado = 0;
    resultado = fibonacci(numeros[i]);
    printf("O número de Fibonacci de %d é %d\n", numeros[i], resultado);
  }

  return 0;
}

int fibonacci(int n)
{
  if (n <= 1)
  {
    return n;
  }
  else
  {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}
