#include <stdio.h>
#include <stdlib.h>

int main()
{
  int tamanho_vetor;

  printf("Digite o tamanho do vetor: ");
  scanf("%d", &tamanho_vetor);

  char *palavra = (char *)malloc(tamanho_vetor * sizeof(char));

  printf("Digite a string a ser armazenada no vetor: ");
  scanf("%s", palavra);

  printf("O vetor digitado foi: %s\n", palavra);

  free(palavra);

  return 0;
}