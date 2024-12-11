#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5  

// dinh nghia cau truc hang doi
typedef struct Queue {
    int arr[MAX_SIZE];  
    int front;      
    int rear;          
} Queue;

void initQueue(Queue* q);
int isFull(Queue* q);
int isEmpty(Queue* q);
void enqueue(Queue* q, int value);
void printQueue(Queue* q);

int main() {
    Queue q;
    initQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);
    printQueue(&q);
    return 0;
}


void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue* q) {
    return (q->rear == MAX_SIZE - 1);
}

int isEmpty(Queue* q) {
    return (q->front == -1);
}

// them phan tu
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
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

void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("hang doi rong\n");
        return;
    }
    
    printf("cac phan tu trong hang doi: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}
