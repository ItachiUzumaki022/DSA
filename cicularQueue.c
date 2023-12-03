// Circular implementation of Queue

#include <stdio.h>
#include <stdlib.h>
#define SIZE 6

struct queue{
    int r, f, data;
    int arr[SIZE];
};

struct queue* intialize(){
    struct queue* q = (struct queue*) malloc(sizeof(struct queue));
    q->f = q->r = 0;
    return q;
}

int isEmpty(struct queue* q){
    if(q->f == q->r){
        return 1;
    }
    return 0;
}

int isFull(struct queue* q){
    if((q->r+1)%SIZE == q->f){
        return 1;
    }
    return 0;
}

void enqueue(struct queue* q, int data){
    if(isFull(q)){
        printf("Queue Overflow!\n");
        exit(1);
    }
    q->r = (q->r + 1) % SIZE;
    q->arr[q->r] = data;
}

int dequeue(struct queue* q){
    if(isEmpty(q)){
        printf("Queue Underflow!\n");
        exit(1);
    }
    int val = q->arr[q->f];
    q->f = (q->f + 1) % SIZE;;
    return val;
}

void traverse(struct queue* q){
    for(int i = q->f + 1; i <= q->r; i++){
        printf("%d\n", q->arr[i]);
    }
}


int main(){
    struct queue* q = intialize();
    enqueue(q, 5);
    enqueue(q, 15);
    enqueue(q, 25);
    enqueue(q, 35);
    enqueue(q, 45);
    traverse(q);

    return 0;
}
