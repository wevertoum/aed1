#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

typedef struct
{
  char data[MAX_LENGTH];
  int top;
} Stack;

void initStack(Stack *stack)
{
  stack->top = -1;
}

void push(Stack *stack, char value)
{
  stack->top++;
  stack->data[stack->top] = value;
}

char pop(Stack *stack)
{
  if (stack->top == -1)
  {
    return '\0'; // Pilha vazia
  }
  char value = stack->data[stack->top];
  stack->top--;
  return value;
}

char peek(Stack *stack)
{
  if (stack->top == -1)
  {
    return '\0'; // Pilha vazia
  }
  return stack->data[stack->top];
}

int isEmpty(Stack *stack)
{
  return stack->top == -1;
}

char verifica_parenteses(const char *expressao)
{
  Stack stack;
  initStack(&stack);
  int i;
  for (i = 0; expressao[i] != '\0'; i++)
  {
    if (expressao[i] == '(')
    {
      push(&stack, '(');
    }
    else if (expressao[i] == ')')
    {
      if (isEmpty(&stack))
      {
        return 'I'; // Incorreta
      }
      pop(&stack);
    }
  }

  if (!isEmpty(&stack))
  {
    return 'I'; // Incorreta
  }
  else
  {
    return 'C'; // Correta
  }
}

int main()
{
  char expressao[MAX_LENGTH];
  fgets(expressao, sizeof(expressao), stdin);
  expressao[strcspn(expressao, "\n")] = '\0'; // Remove o caractere de nova linha

  char resultado = verifica_parenteses(expressao);

  if (resultado == 'C')
  {
    printf("Correta\n");
  }
  else
  {
    printf("Incorreta\n");
  }

  return 0;
}
