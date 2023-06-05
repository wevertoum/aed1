typedef struct{
    float altura;
    float raio;
} Cilindro;

float areaBaseCilindro(Cilindro* cilindro);

float alturaCilindro(Cilindro* cilindro);

float volumeCilindro(Cilindro* cilindro);

float raioCilindro(Cilindro* cilindro);

Cilindro* criaCilindro(float raio, float altura);
