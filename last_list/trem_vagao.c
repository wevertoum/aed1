#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n;
  while (scanf("%d", &n) == 1 && n != 0)
  {
    int *permutation = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &permutation[i]);
    }

    int expected = 1;
    int i = 0;
    int top = -1;
    int station[1000]; // Usando um array para simular a estação

    while (i < n || top >= 0)
    {
      if (i < n && permutation[i] == expected)
      {
        expected++;
        i++;
      }
      else if (top >= 0 && station[top] == expected)
      {
        expected++;
        top--;
      }
      else if (i < n)
      {
        station[++top] = permutation[i];
        i++;
      }
      else
      {
        break;
      }
    }

    if (expected == n + 1)
    {
      printf("Yes\n");
    }
    else
    {
      printf("No\n");
    }

    free(permutation);
  }

  return 0;
}
