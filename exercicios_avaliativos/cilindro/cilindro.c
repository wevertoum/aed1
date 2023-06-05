#include "cilindro.h"
#include <stdlib.h>
#define PI 3.14

float area_de_base_cilindro(Cilindro* cilindro){
    return cilindro->base;
}

float altura_do_cilindro(Cilindro* cilindro){
    return cilindro->altura;
}

float volume_do_cilindro(Cilindro* cilindro){
    return altura_do_cilindro(cilindro) * area_de_base_cilindro(cilindro);
}

Cilindro* cria_o_cilindro(float altura, float base){
    Cilindro* cilindro = malloc(sizeof(Cilindro));
    cilindro->altura = altura;
    cilindro->base = base;
    return cilindro;
}
