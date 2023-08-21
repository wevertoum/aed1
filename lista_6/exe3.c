#include <stdio.h>

int insertionSort(int arr[], int n)
{
  int trocas = 0;
  int i, j;
  for (i = 1; i < n; i++)
  {
    int key = arr[i];
    j = i - 1;

    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j--;
      trocas++;
    }
    arr[j + 1] = key;
    trocas++; // Incrementa a contagem de trocas a cada movimentação
  }

  return trocas;
}

int selectionSort(int arr[], int n)
{
  int trocas = 0;
  int i, j;

  for (i = 0; i < n - 1; i++)
  {
    int minIndex = i;

    for (j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[minIndex])
      {
        minIndex = j;
      }
    }

    if (minIndex != i)
    {
      int temp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = temp;
      trocas++;
    }
  }

  return trocas;
}

int main()
{
  int n;
  scanf("%d", &n);

  int arr[n];
  int i;
  for (i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  int insertionTrocas = insertionSort(arr, n);
  int selectionTrocas = selectionSort(arr, n);

  int diferenca = insertionTrocas - selectionTrocas;

  printf("%d\n", diferenca);

  return 0;
}