#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    float altura;
    float raio;
} Cilindro;

float area_de_base_cilindro(Cilindro *cilindro)
{
    float PI = 3.14;
    return PI * (cilindro->raio * cilindro->raio);
}

float altura_do_cilindro(Cilindro *cilindro)
{
    return cilindro->altura;
}

float volume_do_cilindro(Cilindro *cilindro)
{
    return altura_do_cilindro(cilindro) * area_de_base_cilindro(cilindro);
}

float raio_do_cilindro(Cilindro *cilindro)
{
    return cilindro->raio;
}

Cilindro *cria_o_cilindro(float raio, float altura)
{
    Cilindro *cilindro = malloc(sizeof(Cilindro));
    cilindro->raio = raio;
    cilindro->altura = altura;
    return cilindro;
}

int main()
{
    float altura, raio;
    Cilindro *cilindro;

    printf("Digite as dimensões do cilindro a ser criado\n");
    printf("Altura: ");
    scanf("%f", &altura);
    printf("Raio: ");
    scanf("%f", &raio);

    cilindro = cria_o_cilindro(raio, altura);
    printf("(a) a altura; %.2f\n", altura_do_cilindro(cilindro));
    printf("(b) o raio; %.2f\n", raio_do_cilindro(cilindro));
    printf("(c) a área de sua base; %.2f\n", area_de_base_cilindro(cilindro));
    printf("(d) o volume; %.2f\n", volume_do_cilindro(cilindro));

    free(cilindro);

    return 0;
}
