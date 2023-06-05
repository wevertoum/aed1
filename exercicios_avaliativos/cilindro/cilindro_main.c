#include <stdio.h>
#include "cilindro.h"
#include <stdlib.h>

int main(){
    float altura, raio;
    Cilindro* cilindro;

    printf("digite as dimensoes do cilindro a ser criado\n");
    printf("Altura:");
    scanf("%f",&altura);
    printf("raio:");
    scanf("%f",&raio);

    cilindro = cria_cilindro(raio,altura);
    printf("A area da base do cilidro eh: %.2f\n",area_base_cilindro(cilindro));
    printf("O raio do cilidro eh: %.2f\n",raio_cilindro(cilindro));
    printf("O volume do cilidro eh: %.2f\n",volume_cilindro(cilindro));
    printf("A altura do cilidro eh: %.2f\n",altura_cilindro(cilindro));

    return 0;
}