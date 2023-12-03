// Array based implementation of stack

#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

struct Stack
{
    int top;
    int arr[SIZE];
};

// Creates and initializes stack
struct Stack* createStack(){
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

int isEmpty(struct Stack* stack){
    if(stack->top == -1){
        return 1;
    }
    return 0;
}

int isFull(struct Stack* stack){
    if(stack->top >= SIZE-1){
        return 1;
    }
    return 0;
}

void push(struct Stack* stack, int data){
    if(isFull(stack)){
        printf("Stack Overflow!\n");
        exit(1);
    }
    stack->top++;
    stack->arr[stack->top] = data;
}

int pop(struct Stack* stack){
    if(isEmpty(stack)){
        printf("Stack Underflow!\n");
        exit(1);
    }
    int value = stack->arr[stack->top];
    stack->top--;
    return value;
}

int peek(struct Stack* stack){
    return stack->arr[stack->top];
}

void traverse(struct Stack* stack){
    for(int i = stack->top; i >= 0; i--){
        printf("%d\n", stack->arr[i]);
    }
}


int main(){
    struct Stack* stack = createStack();
    push(stack, 5);
    push(stack, 10);
    push(stack, 15);
    traverse(stack);
    printf("\n");
    printf("Popped value: %d\n", pop(stack));
    printf("Peeked value: %d\n", peek(stack));
    traverse(stack);

    return 0;
}   