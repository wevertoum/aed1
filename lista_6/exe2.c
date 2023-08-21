#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Aluno
{
  char nome[21];
  int problemas;
};

// Função de comparação para qsort
int compareAlunos(const void *a, const void *b)
{
  struct Aluno *alunoA = (struct Aluno *)a;
  struct Aluno *alunoB = (struct Aluno *)b;

  if (alunoA->problemas == alunoB->problemas)
  {
    return strcmp(alunoA->nome, alunoB->nome);
  }

  return alunoB->problemas - alunoA->problemas;
}

int main()
{
  int n;
  scanf("%d", &n);

  struct Aluno alunos[n];
  int i;
  for (i = 0; i < n; i++)
  {
    scanf("%s %d", alunos[i].nome, &alunos[i].problemas);
  }

  // Ordena os alunos usando qsort
  qsort(alunos, n, sizeof(struct Aluno), compareAlunos);

  // Imprime os alunos ordenados
  for (i = 0; i < n; i++)
  {
    printf("%s %d\n", alunos[i].nome, alunos[i].problemas);
  }

  return 0;
}
