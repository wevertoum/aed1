#include <stdio.h>

int fat_duplo(int n)
{
    if (n < 1)
    {
        return 1;
    }
    if ((n % 2))
    {
        return n * fat_duplo(n - 1);
    }
    else
    {
        return fat_duplo(n - 1);
    }
}

int main()
{
    int numero;
    scanf("%d", &numero);
    printf("%d", fat_duplo(numero));
    return 0;
}