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

    cilindro = cria_o_cilindro(raio, altura);
    printf("A altura do cilindro é: %.2f\n", altura_do_cilindro(cilindro));
    printf("A área da base do cilindro é: %.2f\n", area_de_base_cilindro(cilindro));
    printf("O volume do cilindro é: %.2f\n", volume_do_cilindro(cilindro));

    return 0;
}
