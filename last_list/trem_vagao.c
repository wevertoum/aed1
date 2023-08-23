#include <stdio.h>

#define MAX_N 1000

typedef struct
{
  int data[MAX_N];
  int top;
} Stack;

void initStack(Stack *stack)
{
  stack->top = -1;
}

void push(Stack *stack, int value)
{
  stack->top++;
  stack->data[stack->top] = value;
}

int pop(Stack *stack)
{
  int value = stack->data[stack->top];
  stack->top--;
  return value;
}

int main()
{
  int n;
  int sequence[MAX_N];

  while (1)
  {
    scanf("%d", &n);
    if (n == 0)
    {
      break;
    }

    while (1)
    {
      int i1;
      for (i1 = 0; i1 < n; i1++)
      {
        scanf("%d", &sequence[i1]);
      }

      if (sequence[0] == 0)
      {
        break;
      }

      Stack station;
      initStack(&station);
      int expected = 1;
      int possible = 1;

      int i;
      for (i = 0; i < n; i++)
      {
        while (station.top >= 0 && station.data[station.top] == expected)
        {
          pop(&station);
          expected++;
        }

        if (sequence[i] == expected)
        {
          expected++;
        }
        else if (station.top >= 0 && station.data[station.top] < sequence[i])
        {
          possible = 0;
        }
        else
        {
          push(&station, sequence[i]);
        }
      }

      while (station.top >= 0)
      {
        if (station.data[station.top] == expected)
        {
          pop(&station);
          expected++;
        }
        else
        {
          possible = 0;
          break;
        }
      }

      if (possible)
      {
        printf("Yes\n");
      }
      else
      {
        printf("No\n");
      }
    }

    printf("\n");
  }

  return 0;
}
