#include <stdio.h>
#include <stdlib.h>

struct Stack
{
  char data;
  struct Stack *next;
};

typedef struct Stack Stack;

Stack *createNode(char data)
{
  Stack *node = (Stack *)malloc(sizeof(Stack));
  node->data = data;
  node->next = NULL;
  return node;
}

void push(Stack **top, char data)
{
  Stack *newNode = createNode(data);
  newNode->next = *top;
  *top = newNode;
}

void pop(Stack **top)
{
  if (*top == NULL)
    return;
  Stack *temp = *top;
  *top = (*top)->next;
  free(temp);
}

int areParenthesesBalanced(const char *expression)
{
  Stack *stack = NULL;
  int i = 0;
  while (expression[i] != '\0')
  {
    if (expression[i] == '(')
    {
      push(&stack, '(');
    }
    else if (expression[i] == ')')
    {
      if (stack == NULL)
        return 0;
      pop(&stack);
    }
    i++;
  }

  return stack == NULL ? 1 : 0;
}

int main()
{
  char expression[1001];
  printf("Digite a expressao: ");
  scanf("%1000s", expression);
  if (areParenthesesBalanced(expression))
  {
    printf("Correta\n");
  }
  else
  {
    printf("Incorreta\n");
  }

  return 0;
}
