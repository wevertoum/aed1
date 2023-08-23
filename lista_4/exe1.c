#include <stdio.h>
#include <string.h>

struct Contato
{
  char nome[20];
  char telefone[11];
  int ligacoes;
};

void ordenarContatos(struct Contato *contatos, int numContatos)
{
  struct Contato temp;
  int i, j;
  for (i = 0; i < numContatos - 1; i++)
  {
    for (j = 0; j < numContatos - i - 1; j++)
    {
      if (contatos[j].ligacoes < contatos[j + 1].ligacoes)
      {
        temp = contatos[j];
        contatos[j] = contatos[j + 1];
        contatos[j + 1] = temp;
      }
    }
  }
}

int main()
{
  struct Contato contatos[100];
  int numContatos = 2;

  strcpy(contatos[0].nome, "Hermanoteu");
  strcpy(contatos[0].telefone, "4523-2248");
  contatos[0].ligacoes = 300;

  strcpy(contatos[1].nome, "Ooloneia");
  strcpy(contatos[1].telefone, "4523-4887");
  contatos[1].ligacoes = 299;

  while (1)
  {
    char op;
    scanf(" %c", &op);

    if (op == 'I')
    {
      struct Contato novoContato;
      scanf("%s %s %d", novoContato.nome, novoContato.telefone, &novoContato.ligacoes);
      contatos[numContatos] = novoContato;
      numContatos++;
    }
    else if (op == 'R')
    {
      char nome[20];
      scanf("%s", nome);
      int i, j;
      for (i = 0; i < numContatos; i++)
      {
        if (strcmp(contatos[i].nome, nome) == 0)
        {
          for (j = i; j < numContatos - 1; j++)
          {
            contatos[j] = contatos[j + 1];
          }
          numContatos--;
          break;
        }
      }
    }
    else if (op == 'L')
    {
      char nome[20];
      scanf("%s", nome);
      int i;
      for (i = 0; i < numContatos; i++)
      {
        if (strcmp(contatos[i].nome, nome) == 0)
        {
          contatos[i].ligacoes++;
          break;
        }
      }
    }
    else if (op == 'F')
    {
      ordenarContatos(contatos, numContatos);
      int i;
      for (i = 0; i < numContatos; i++)
      {
        printf("%s - %s\n", contatos[i].nome, contatos[i].telefone);
      }
      break;
    }
  }

  return 0;
}
