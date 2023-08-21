#include <stdio.h>

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int low, int high)
{
  int pivot = arr[high];
  int i = low - 1;
  int j;

  for (j = low; j <= high - 1; j++)
  {
    if (arr[j] < pivot)
    {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

int quickSelect(int arr[], int low, int high, int k)
{
  if (low <= high)
  {
    int pivotIndex = partition(arr, low, high);
    if (pivotIndex == k - 1)
      return arr[pivotIndex];
    else if (pivotIndex > k - 1)
      return quickSelect(arr, low, pivotIndex - 1, k);
    else
      return quickSelect(arr, pivotIndex + 1, high, k);
  }
  return -1;
}

int main()
{
  int n, k;
  scanf("%d", &n);

  int arr[n];
  int i;
  for (i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  scanf("%d", &k);

  if (k >= 1 && k <= n)
  {
    int kthSmallest = quickSelect(arr, 0, n - 1, k);
    printf("%d\n", kthSmallest);
  }
  else
  {
    printf("Valor de k fora do intervalo válido.\n");
  }

  return 0;
}
