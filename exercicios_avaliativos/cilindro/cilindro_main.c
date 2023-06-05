#include <stdio.h>
#include "cilindro.h"
#include <stdlib.h>

int main(){
    float altura, raio;
    Cilindro* cilindro;

    printf("Digite as dimensões do cilindro a ser criado\n");
    printf("Altura: ");
    scanf("%f", &altura);
    printf("Raio: ");
    scanf("%f", &raio);

    cilindro = criaCilindro(raio, altura);
    printf("A área da base do cilindro é: %.2f\n", areaBaseCilindro(cilindro));
    printf("O raio do cilindro é: %.2f\n", raioCilindro(cilindro));
    printf("O volume do cilindro é: %.2f\n", volumeCilindro(cilindro));
    printf("A altura do cilindro é: %.2f\n", alturaCilindro(cilindro));

    return 0;
}
