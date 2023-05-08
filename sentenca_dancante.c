#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 50

void dancing_sentence(char texto[MAX_LEN + 1])
{
  int i;
  if (texto[strlen(texto) - 1] == '\n')
  {
    texto[strlen(texto) - 1] = '\0';
  }
  for (i = 0; i < strlen(texto); i++)
  {
    if (i % 2 == 0)
    {
      texto[i] = toupper(texto[i]);
    }
    else
    {
      texto[i] = tolower(texto[i]);
    }
  }
  printf("%s\n", texto);
}

int main()
{
  char textoUser[MAX_LEN + 1];

  printf("Digite as strings:\n");

  while (fgets(textoUser, sizeof(textoUser), stdin))
  {
    dancing_sentence(textoUser);
  }

  return 0;
}
