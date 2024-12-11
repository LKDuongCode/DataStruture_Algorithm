#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5
typedef struct Queue {
    int arr[MAX_SIZE];  
    int front;          
    int rear;       
} Queue;

void initQueue(Queue* q);
int isEmpty(Queue* q);
void enqueue(Queue* q, int value);
int peek(Queue* q);

int main() {
    Queue q;
    initQueue(&q);
    enqueue(&q, 10);
    printf("phan tu dau hang doi: %d\n", peek(&q));
    enqueue(&q, 20);
    printf("phan tu dau hang doi: %d\n", peek(&q));
    enqueue(&q, 30);
    printf("phan tu dau hang doi: %d\n", peek(&q));
    enqueue(&q, 40);
    printf("phan tu dau hang doi: %d\n", peek(&q));
    enqueue(&q, 50);
    printf("phan tu dau hang doi: %d\n", peek(&q));
    enqueue(&q, 60);
    printf("phan tu dau hang doi: %d\n", peek(&q));
    return 0;
}


void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue* q) {
    return (q->front == -1);  
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX_SIZE - 1) {
        printf("hang doi da day, khong the them phan tu %d\n", value);
        return;
    }

    if (q->front == -1) {
        q->front = 0;
    }

    q->rear++;       
    q->arr[q->rear] = value;
    printf("them phan tu %d vao hang doi\n", value);
}

int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("hang doi rong, khong the tra ve phan tu dau\n");
        return -1;  
    }
    return q->arr[q->front];  
}
