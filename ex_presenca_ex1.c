#include <stdio.h>

void imprime_numeros(int num, int counter)
{
    if (counter <= num)
    {
        printf("%d ", counter++);
        imprime_numeros(num, counter);
    }
}

int main()
{
    int num, counter = 1;
    scanf("%d", &num);
    imprime_numeros(num, counter);
    return 0;
}