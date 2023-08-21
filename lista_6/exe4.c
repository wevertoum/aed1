#include <stdio.h>

int binarySearch(int arr[], int n, int target)
{
  int left = 0;
  int right = n - 1;
  int result = n; // Initialize with n to cover the case where no cafe is affordable

  while (left <= right)
  {
    int mid = left + (right - left) / 2;

    if (arr[mid] >= target)
    {
      result = mid;
      right = mid - 1;
    }
    else
    {
      left = mid + 1;
    }
  }

  return result;
}

int main()
{
  int n;
  scanf("%d", &n);

  int x[n];
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &x[i]);
  }

  int prefixSum[n];
  prefixSum[0] = x[0];
  for (int i = 1; i < n; i++)
  {
    prefixSum[i] = prefixSum[i - 1] + x[i];
  }

  int q;
  scanf("%d", &q);

  int m;
  for (int i = 0; i < q; i++)
  {
    scanf("%d", &m);

    int cafes = binarySearch(prefixSum, n, m);

    printf("%d\n", cafes); // The result is already 0-indexed
  }

  return 0;
}
