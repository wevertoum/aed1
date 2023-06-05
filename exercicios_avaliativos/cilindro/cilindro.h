typedef struct{
    float altura;
    float raio;
}Cilindro;

float area_base_cilindro(Cilindro* cilindro);

float altura_cilindro(Cilindro* cilindro);

float volume_cilindro(Cilindro* cilindro);

float raio_cilindro(Cilindro* cilindro);

Cilindro* cria_cilindro(float raio, float altura);


