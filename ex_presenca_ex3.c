#include <stdio.h>

void reverte_numero(int n)
{
    if (n > 0)
    {
        if (n % 10 != 0)
        {
            printf("%d", n % 10);
        }
        reverte_numero(n / 10);
    }
}

int main()
{
    int valor;
    scanf("%d", &valor);
    reverte_numero(valor);
    return 0;
}