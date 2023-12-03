// queue implementation using array

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

struct queue
{
    int data, r, f;
    int arr[SIZE];
};

struct queue* intializeQueue(){
    struct queue* q = (struct queue*) malloc(sizeof(struct queue));
    q->r = q->f = -1;
}

int isEmpty(struct queue* q){
    if(q->f == -1){
        return 1;
    }
    return 0;
}

int isFull(struct queue* q){
    if(q->r == SIZE-1){
        return 1;
    }
    return 0;
}

void enqueue(struct queue* q, int data){
    if(isFull(q)){
        printf("Queue Overflow!\n");
        exit(1);
    }
    if(q->f == -1){
        q->f++;
    }
    q->r++;
    q->arr[q->r] = data;
}

int dequeue(struct queue* q){
    if(isEmpty(q)){
        printf("Queue Underflow!\n");
        exit(1);
    }
    int val = q->arr[q->f];
    q->f++;
    return val;
}

int peek(struct queue* q){
    if(isEmpty(q)){
        printf("Queue Underflow!\n");
        exit(1);
    }
    return q->arr[q->f];
}

void traverse(struct queue* q){
    for(int i = q->f; i <= q->r; i++){
        printf("%d\n", q->arr[i]);
    }
}

int main(){
    struct queue* q = intializeQueue();
    enqueue(q, 5);
    enqueue(q, 15);
    enqueue(q, 25);
    enqueue(q, 35);
    enqueue(q, 45);
    traverse(q);
    printf("\n");
    printf("Dequed val: %d\n", dequeue(q));
    printf("Dequed val: %d\n", dequeue(q));
    printf("Peeked val: %d\n", peek(q));
    traverse(q);

    return 0;
}