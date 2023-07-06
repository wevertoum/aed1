#include <stdio.h>

#define MAX_STACK_SIZE 32

typedef struct {
    int data[MAX_STACK_SIZE];
    int top;
} Stack;

void initStack(Stack* stack) {
    stack->top = -1;
}

int isStackEmpty(Stack* stack) {
    return (stack->top == -1);
}

int isStackFull(Stack* stack) {
    return (stack->top == MAX_STACK_SIZE - 1);
}

void push(Stack* stack, int item) {
    if (isStackFull(stack)) {
        printf("Stack is full. Cannot push item.\n");
        return;
    }
    
    stack->top++;
    stack->data[stack->top] = item;
}

int pop(Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack is empty. Cannot pop item.\n");
        return -1;
    }
    
    int item = stack->data[stack->top];
    stack->top--;
    
    return item;
}

void decimalToBinary(int decimal) {
    Stack stack;
    initStack(&stack);
    
    if (decimal == 0) {
        printf("Binary: 0\n");
        return;
    }
    
    while (decimal > 0) {
        push(&stack, decimal % 2); // Empilha o dígito binário atual
        decimal = decimal / 2; // Divide o decimal por 2
    }
    
    printf("Binary: ");
    
    // Desempilha e imprime os dígitos binários
    while (!isStackEmpty(&stack)) {
        printf("%d", pop(&stack));
    }
    
    printf("\n");
}

int main() {
    int decimal;
    
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    
    decimalToBinary(decimal);
    
    return 0;
}
