#include <stdio.h>

int main()
{
  int x, *px, *py;
  x = 9;
  px = &x;
  py = px;

  printf("\nx = %d", x);
  printf("\n&x = %p", &x);
  printf("\npx = %p", px);
  printf("\n*px = %p", *px);
  printf("\n*py = %p", *py);

  return 0;
}