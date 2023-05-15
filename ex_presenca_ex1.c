#include <stdio.h>

void imprime_valores(int n, int c)
{
    if (c <= n)
    {
        printf("%d ", c++);
        imprime_valores(n, c);
    }
}

int main()
{
    int num, counter = 1;
    scanf("%d", &num);
    imprime_valores(num, counter);
    return 0;
}
