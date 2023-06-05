#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    float altura;
    float base;
} Cilindro;

float altura_do_cilindro(Cilindro *cilindro);
float area_de_base_cilindro(Cilindro *cilindro);
float volume_do_cilindro(Cilindro *cilindro);

Cilindro *cria_o_cilindro(float raio, float altura);

float area_de_base_cilindro(Cilindro *cilindro)
{
    return cilindro->base;
}

float altura_do_cilindro(Cilindro *cilindro)
{
    return cilindro->altura;
}

float volume_do_cilindro(Cilindro *cilindro)
{
    return altura_do_cilindro(cilindro) * area_de_base_cilindro(cilindro);
}

Cilindro *cria_o_cilindro(float altura, float base)
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
        float altura, raio;

        scanf("%f %f", &altura, &raio);

        cilindros[index] = *cria_o_cilindro(altura, raio);
    }

    for (index = 0; index < n; index++)
    {
        printf("%.2f %.2f %.2f", altura_do_cilindro(&cilindros[index]), area_de_base_cilindro(&cilindros[index]), volume_do_cilindro(&cilindros[index]));
    }

    free(cilindros);

    return 0;
}
