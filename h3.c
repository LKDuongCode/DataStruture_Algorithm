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
int dequeue(Queue* q);
void printIsEmpty(Queue* q);

int main() {
    Queue q;
    initQueue(&q);
    printf("kiem tra hang doi ban dau: ");
    printIsEmpty(&q);
    enqueue(&q, 10);
    printf("kiem tra hang doi sau khi them: ");
    printIsEmpty(&q);
    enqueue(&q, 20);
    printf("kiem tra hang doi sau khi them: ");
    printIsEmpty(&q);
    int dequeuedValue = dequeue(&q);
    if (dequeuedValue != -1) {
        printf("phan tu lay ra: %d\n", dequeuedValue);
    }
    printf("kiem tra hang doi sau khi dequeue: ");
    printIsEmpty(&q);

    dequeuedValue = dequeue(&q);
    if (dequeuedValue != -1) {
        printf("phan tu lay ra: %d\n", dequeuedValue);
    }
    printf("kiem tra hang doi sau khi dequeue: ");
    printIsEmpty(&q);

    dequeuedValue = dequeue(&q);
    if (dequeuedValue != -1) {
        printf("phan tu lay ra: %d\n", dequeuedValue);
    }
    printf("kiem tra hang doi sau khi dequeue: ");
    printIsEmpty(&q);

    return 0;
}

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue* q) {
    return (q->front == -1);  // hang doi rong khi front = -1
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX_SIZE - 1) {
        printf("hang doi da day, khong the them phan tu %d\n", value);
        return;
    }

    if (q->front == -1) {
        q->front = 0;  // neu hang doi rong cap nhat con tro front
    }

    q->rear++;       // di chuyen con tro rear
    q->arr[q->rear] = value;
    printf("them phan tu %d vao hang doi\n", value);
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("hang doi rong, khong the lay phan tu\n");
        return -1;  // tra ve -1 neu hang doi rong
    }

    int dequeuedValue = q->arr[q->front];  // lay phan tu tu dau hang doi
    if (q->front == q->rear) {
        q->front = q->rear = -1;  // neu hang doi chi co 1 phan tu, reset
    } else {
        q->front++;  // di chuyen con tro front
    }
    return dequeuedValue;
}

void printIsEmpty(Queue* q) {
    if (isEmpty(q)) {
        printf("hang doi rong\n");
    } else {
        printf("hang doi khong rong\n");
    }
}
