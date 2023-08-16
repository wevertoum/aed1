#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int *data;
  int front;
  int rear;
  int size;
} Queue;

Queue *createQueue(int size)
{
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  queue->data = (int *)malloc(size * sizeof(int));
  queue->front = queue->rear = -1;
  queue->size = size;
  return queue;
}

int isEmpty(Queue *queue)
{
  return queue->front == -1;
}

void enqueue(Queue *queue, int value)
{
  if (queue->rear == queue->size - 1)
  {
    printf("Queue is full\n");
    return;
  }
  if (isEmpty(queue))
  {
    queue->front = queue->rear = 0;
  }
  else
  {
    queue->rear++;
  }
  queue->data[queue->rear] = value;
}

int dequeue(Queue *queue)
{
  if (isEmpty(queue))
  {
    printf("Queue is empty\n");
    return -1;
  }
  int value = queue->data[queue->front];
  if (queue->front == queue->rear)
  {
    queue->front = queue->rear = -1;
  }
  else
  {
    queue->front++;
  }
  return value;
}

int isPossible(int *permutation, int n)
{
  Queue *station = createQueue(n);
  int target = 1;
  int i = 0;

  while (i < n)
  {
    if (!isEmpty(station) && station->data[station->front] == target)
    {
      dequeue(station);
      target++;
    }
    else if (permutation[i] == target)
    {
      target++;
      i++;
    }
    else
    {
      enqueue(station, permutation[i]);
      i++;
    }
  }

  while (!isEmpty(station) && station->data[station->front] == target)
  {
    dequeue(station);
    target++;
  }

  int result = target == n + 1;

  free(station->data);
  free(station);

  return result;
}

int main()
{
  int n;
  while (scanf("%d", &n) == 1)
  {
    int *permutation = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &permutation[i]);
    }

    if (isPossible(permutation, n))
    {
      printf("Yes\n");
    }
    else
    {
      printf("No\n");
    }

    free(permutation);
  }

  return 0;
}
