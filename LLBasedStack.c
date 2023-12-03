// Linked List Based Implementation of stack

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Stack
{
    struct Node* top;
};

// initialize empty stack
struct Stack* initializeStack(){
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

struct Node* createNode(int data){
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int isEmpty(struct Stack* stack){
    if(stack->top == NULL){
        return 1;
    }
    return 0;
}

int isFull(struct Stack* stack){
    struct Node* n = (struct Node*) malloc(sizeof(struct Node));;
    if(n == NULL){
        return 1;
    }
    return 0;
}

void push(struct Stack* stack, int data){
    if(isFull(stack)){
        printf("Stack Overflow!\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(struct Stack* stack){
    if(isEmpty(stack)){
        printf("Stack Underflow!\n");
        exit(1);
    }
    struct Node* ptr = stack->top;
    stack->top = stack->top->next;
    int data = ptr->data;
    free(ptr);
    return data;
}

int peek(struct Stack* stack){
    if(isEmpty(stack)){
        printf("Stack Underflow!\n");
        exit(1);
    }
    return stack->top->data;
}

void traverse(struct Stack* stack){
    struct Node* ptr = stack->top;
    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}


int main(){
    struct Stack* stack = initializeStack();
    push(stack, 78);
    push(stack, 7);
    push(stack, 8);
    push(stack, 38);
    push(stack, 29);
    printf("Popped value: %d\n", pop(stack));
    printf("Popped value: %d\n", pop(stack));
    printf("peeked value: %d\n", peek(stack));
    traverse(stack);
    printf("\n");
    push(stack, 500);
    push(stack, 600);
    push(stack, 700);
    push(stack, 800);
    traverse(stack);

    return 0;
}           