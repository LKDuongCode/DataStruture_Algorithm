#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct Queue {
    int array[MAX];
    int front;
    int rear;
} Queue;

void initalQueue(Queue* queue);
int isEmpty(Queue* queue);
int isFull(Queue* queue);
void enqueue(Queue* queue, int value);
void peek(Queue* queue);
void displayQueue(Queue* queue);

int main() {
    Queue queue;
    initalQueue(&queue);
    int value;
    do {
        printf("\n==================MENU================\n");
        printf("0. Thoat\n");
        printf("1. Them phan tu vao cuoi\n");
        printf("2. Hien thi hang doi\n");
        printf("3. Kiem tra phan tu dau\n");
        printf("Vui long chon: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 0: 
                exit(0);
            case 1:
                printf("Nhap gia tri them: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;
            case 2:
                displayQueue(&queue);
                break;
            case 3:
                peek(&queue);
                break;
            default:
                printf("Vui long chon lai\n");
        }   
    } while (1);
    return 0;
}

void initalQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(Queue* queue) {
    return (queue->front == -1);
}

int isFull(Queue* queue) {
    return (queue->rear >= MAX - 1);
}

void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Hang doi da day\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear++;
    queue->array[queue->rear] = value;
}

void peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong\n");
        return;
    }
    printf("Phan tu dau: %d\n", queue->array[queue->front]);
}

void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong\n");
        return;
    }
    printf("Cac phan tu trong hang doi: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d\t", queue->array[i]);
    }
    printf("\n");
}
