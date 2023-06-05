typedef struct
{
    float altura;
    float base;
} Cilindro;

float altura_do_cilindro(Cilindro *cilindro);
float area_de_base_cilindro(Cilindro *cilindro);
float volume_do_cilindro(Cilindro *cilindro);

Cilindro *cria_o_cilindro(float raio, float altura);
