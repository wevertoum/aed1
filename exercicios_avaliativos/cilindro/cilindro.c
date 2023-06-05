#include "cilindro.h"
#include <stdlib.h>
#define PI 3.14

float areaBaseCilindro(Cilindro* cilindro){
    return PI * (cilindro->raio * cilindro->raio);
}

float alturaCilindro(Cilindro* cilindro){
    return cilindro->altura;
}

float volumeCilindro(Cilindro* cilindro){
    return alturaCilindro(cilindro) * areaBaseCilindro(cilindro);
}

float raioCilindro(Cilindro* cilindro){
    return cilindro->raio;
}

Cilindro* criaCilindro(float raio, float altura){
    Cilindro* cilindro = malloc(sizeof(Cilindro));
    cilindro->raio = raio;
    cilindro->altura = altura;
    return cilindro;
}
