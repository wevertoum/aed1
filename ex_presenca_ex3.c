#include <stdio.h>

void reverse(int numero)
{
    if(numero>0){
        if(numero%10!=0){
            printf("%d",numero%10);
        }
        reverse(numero/10);
    }
}

int main()
{
    int numero;
    scanf("%d", &numero);
    reverse(numero);
    return 0;
}