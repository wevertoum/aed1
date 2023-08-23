#include <stdio.h>

#define MAX_PACIENTES 25

typedef struct
{
  int H, M, C;
} Paciente;

typedef struct
{
  Paciente data[MAX_PACIENTES];
  int front, rear;
} Fila;

void initFila(Fila *fila)
{
  fila->front = 0;
  fila->rear = -1;
}

void enqueue(Fila *fila, Paciente paciente)
{
  fila->rear++;
  fila->data[fila->rear] = paciente;
}

Paciente dequeue(Fila *fila)
{
  if (fila->front > fila->rear)
  {
    Paciente emptyPaciente = {0, 0, 0};
    return emptyPaciente; // Fila vazia
  }
  Paciente paciente = fila->data[fila->front];
  fila->front++;
  return paciente;
}

int isEmpty(Fila *fila)
{
  return fila->front > fila->rear;
}

int main()
{
  Fila fila;
  initFila(&fila);

  int N;
  scanf("%d", &N);
  int i;
  for (i = 0; i < N; i++)
  {
    Paciente paciente;
    scanf("%d %d %d", &paciente.H, &paciente.M, &paciente.C);
    enqueue(&fila, paciente);
  }

  int atendimento_hora = 7;
  int atendimento_minuto = 0;
  int pacientes_criticos = 0;

  while (!isEmpty(&fila))
  {
    Paciente paciente = dequeue(&fila);

    int tempo_atual = (paciente.H - atendimento_hora) * 60 + (paciente.M - atendimento_minuto);

    if (tempo_atual + paciente.C <= 0)
    {
      pacientes_criticos++;
    }

    atendimento_minuto += 30;
    if (atendimento_minuto >= 60)
    {
      atendimento_hora++;
      atendimento_minuto -= 60;
    }
  }

  printf("%d\n", pacientes_criticos);

  return 0;
}