// Linked list based Node

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Queue{
    struct Node* r;
    struct Node* f;
};

struct Node* createNode(int data){
    struct Node* node = (struct Node *) malloc(sizeof(struct Node));
    node->next = NULL;
    node->data = data;
    return node;
}

// intialize Node with empty/null node
struct Queue* intializeQueue(){
    struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
    q->f = q->r = NULL;
    return q;
}

int isEmpty(struct Queue* q){
    if(q->f == NULL){
        return 1;
    }
    return 0;
}

void enqueue(struct Queue* q, int data){
    struct Node* nq = createNode(data);
    if(nq==NULL){
        printf("Node Overflow!\n");
        exit(1);
    }
    if(q->f == NULL){
        q->f = q->r = nq;
    }
    else{
        q->r->next = nq;
        q->r = nq;
    }
}

int dequeue(struct Queue* q){
    if(isEmpty(q)){
        printf("Queue Underflow!\n");
        exit(1);
    }
    int data = q->f->data;
    struct Node* ptr = q->f;
    q->f = q->f->next;
    free(ptr);
    return data;
}

int peek(struct Queue* q){
    if(isEmpty(q)){
        printf("Queue Underflow!\n");
        exit(1);
    }
    return q->f->data;
}

void traverse(struct Queue* q){
    printf("Queue Elements: \n");
    struct Node* ptr = q->f;
    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    struct Queue* q = intializeQueue();
    enqueue(q, 5);
    enqueue(q, 15);
    enqueue(q, 25);
    enqueue(q, 35);
    enqueue(q, 45);
    traverse(q);
    printf("Peeked val: %d\n", peek(q));
    printf("\n");
    printf("Dequed val: %d\n", dequeue(q));
    printf("Dequed val: %d\n", dequeue(q));
    printf("Peeked val: %d\n", peek(q));
    traverse(q);

    return 0;
}       