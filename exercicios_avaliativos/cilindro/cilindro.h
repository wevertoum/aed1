typedef struct{
    float altura;
    float raio;
} Cilindro;

float area_de_base_cilindro(Cilindro* cilindro);

float altura_do_cilindro(Cilindro* cilindro);

float volume_do_cilindro(Cilindro* cilindro);

float raio_do_cilindro(Cilindro* cilindro);

Cilindro* cria_o_cilindro(float raio, float altura);
