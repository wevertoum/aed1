#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int altura;
    int base;
} Cilindro;

int altura_do_cilindro(Cilindro *cilindro);
int base_do_cilindro(Cilindro *cilindro);
int volume_do_cilindro(Cilindro *cilindro);

Cilindro *cria_o_cilindro(int base, int altura);

int base_do_cilindro(Cilindro *cilindro)
{
    return cilindro->base;
}

int altura_do_cilindro(Cilindro *cilindro)
{
    return cilindro->altura;
}

int volume_do_cilindro(Cilindro *cilindro)
{
    return altura_do_cilindro(cilindro) * base_do_cilindro(cilindro);
}

Cilindro *cria_o_cilindro(int altura, int base)
{
    Cilindro *cilindro = malloc(sizeof(Cilindro));
    cilindro->altura = altura;
    cilindro->base = base;
    return cilindro;
}

int main()
{
    int n;
    scanf("%d", &n);

    Cilindro *cilindros = malloc(n * sizeof(Cilindro));

    int index;
    for (index = 0; index < n; index++)
    {
        int altura, base;

        scanf("%d %d", &altura, &base);

        cilindros[index] = *cria_o_cilindro(altura, base);
    }

    for (index = 0; index < n; index++)
    {
        printf("%d %d %d\n", altura_do_cilindro(&cilindros[index]), base_do_cilindro(&cilindros[index]), volume_do_cilindro(&cilindros[index]));
    }

    free(cilindros);

    return 0;
}
