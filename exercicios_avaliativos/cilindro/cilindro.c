#include "cilindro.h"
#include <stdlib.h>
#define PI 3.14

float area_base_cilindro(Cilindro* cilindro){
    return PI*(cilindro->raio*cilindro->raio);
}

float altura_cilindro(Cilindro* cilindro){
    return cilindro->altura;
}

float volume_cilindro(Cilindro* cilindro){
    return altura_cilindro(cilindro)*area_base_cilindro(cilindro);
}

float raio_cilindro(Cilindro* cilindro){
    return cilindro->raio;
}

Cilindro* cria_cilindro(float raio, float altura){
    Cilindro* cilindro = malloc(1*sizeof(Cilindro));
    cilindro->raio = raio;
    cilindro->altura = altura;
    return cilindro;
}