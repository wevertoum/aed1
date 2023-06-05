#include "cilindro.h"
#include <stdlib.h>
#define PI 3.14

float area_de_base_cilindro(Cilindro* cilindro){
    return PI * (cilindro->raio * cilindro->raio);
}

float altura_do_cilindro(Cilindro* cilindro){
    return cilindro->altura;
}

float volume_do_cilindro(Cilindro* cilindro){
    return altura_do_cilindro(cilindro) * area_de_base_cilindro(cilindro);
}

float raio_do_cilindro(Cilindro* cilindro){
    return cilindro->raio;
}

Cilindro* cria_o_cilindro(float raio, float altura){
    Cilindro* cilindro = malloc(sizeof(Cilindro));
    cilindro->raio = raio;
    cilindro->altura = altura;
    return cilindro;
}
