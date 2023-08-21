#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura da fila
typedef struct Node
{
  int arrival_time;
  int critical_time;
  struct Node *next;
} Node;

typedef struct Queue
{
  Node *front;
  Node *rear;
} Queue;

// Inicialização da fila
void initializeQueue(Queue *q)
{
  q->front = q->rear = NULL;
}

// Inserção de um elemento na fila
void enqueue(Queue *q, int arrival_time, int critical_time)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->arrival_time = arrival_time;
  newNode->critical_time = critical_time;
  newNode->next = NULL;

  if (q->rear == NULL)
  {
    q->front = q->rear = newNode;
    return;
  }

  q->rear->next = newNode;
  q->rear = newNode;
}

// Remoção de um elemento da fila
void dequeue(Queue *q)
{
  if (q->front == NULL)
    return;

  Node *temp = q->front;
  q->front = q->front->next;

  if (q->front == NULL)
    q->rear = NULL;

  free(temp);
}

int main()
{
  int N;
  scanf("%d", &N); // Número de pacientes

  Queue q;
  initializeQueue(&q);

  int critical_count = 0; // Contador de pacientes críticos

  int i;
  for (i = 0; i < N; i++)
  {
    int H, M, C;
    scanf("%d %d %d", &H, &M, &C); // Hora, Minuto, Tempo até condição crítica
    int arrival_time = H * 60 + M; // Converter hora e minuto para minutos
    enqueue(&q, arrival_time, C);  // Inserir paciente na fila
  }

  int current_time = 7 * 60; // Tempo de início do atendimento
  while (q.front != NULL)
  {
    Node *current_patient = q.front;

    if (current_time >= current_patient->arrival_time && current_time <= current_patient->arrival_time + current_patient->critical_time)
    {
      critical_count++;
    }

    current_time = (current_patient->arrival_time + 30 <= current_time) ? current_time + 30 : current_patient->arrival_time + 30;
    dequeue(&q); // Remover paciente da fila
  }

  printf("%d\n", critical_count);

  return 0;
}
