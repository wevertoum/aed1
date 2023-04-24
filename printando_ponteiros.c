#include <stdio.h>

int main()
{
  int x = 8;
  char w = 'a';

  int *y = &x;
  char *z = &w;

  printf("\nthe address of x is: %p", &x);
  printf("\nthe address of y is: %p", &y);
  printf("\nthe value of address of x is: %d", *y);
  printf("\nthe value of address of w is: %c", *z);

  return 0;
}
