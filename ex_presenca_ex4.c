#include <stdio.h>

int fatorial_duplo(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    if (n % 2 == 0)
    {
        n--;
    }
    return n * fatorial_duplo(n - 2);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", fatorial_duplo(n));
    return 0;
}
