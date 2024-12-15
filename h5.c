#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int priority;
    int data;   
} Queue;

typedef struct {
    Queue array[MAX];
    int front;
    int rear;
} PriorityQueue;

void initializeQueue(PriorityQueue* queue);
int isEmpty(PriorityQueue* queue);
int isFull(PriorityQueue* queue);
void enqueue(PriorityQueue* queue, int priority, int data);
void dequeue(PriorityQueue* queue);
void displayQueue(PriorityQueue* queue);

int main() {
    PriorityQueue queue;
    initializeQueue(&queue);
    int value, priority;
    
    do {
        printf("\n==================MENU================\n");
        printf("0. Thoat\n");
        printf("1. Them phan tu vao hang doi\n");
        printf("2. Lay phan tu uu tien cao nhat\n");
        printf("3. Hien thi hang doi\n");
        printf("Vui long chon: ");
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 0:
                exit(0);
            case 1:
                printf("Nhap gia tri: ");
                scanf("%d", &value);
                printf("Nhap uu tien: ");
                scanf("%d", &priority);
                enqueue(&queue, priority, value);
                break;
            case 2:
                dequeue(&queue);
                break;
            case 3:
                displayQueue(&queue);
                break;
            default:
                printf("Vui long chon lai\n");
        }
    } while (1);
    
    return 0;
}

void initializeQueue(PriorityQueue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(PriorityQueue* queue) {
    return queue->front == -1;
}

int isFull(PriorityQueue* queue) {
    return queue->rear >= MAX - 1;
}

void enqueue(PriorityQueue* queue, int priority, int data) {
    if (isFull(queue)) {
        printf("Hang doi da day.\n");
        return;
    }
    
    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
        queue->array[queue->rear].priority = priority;
        queue->array[queue->rear].data = data;
    } else {
        int i = queue->rear;
        while (i >= queue->front && queue->array[i].priority < priority) {
            queue->array[i + 1] = queue->array[i];
            i--;
        }
        queue->rear++;
        queue->array[i + 1].priority = priority;
        queue->array[i + 1].data = data;
    }
}

void dequeue(PriorityQueue* queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong.\n");
        return;
    }
    
    printf("Da lay phan tu voi du lieu: %d va uu tien: %d\n", queue->array[queue->front].data, queue->array[queue->front].priority);
    for (int i = queue->front; i < queue->rear; i++) {
        queue->array[i] = queue->array[i + 1];
    }
    
    queue->rear--;
    if (queue->rear == -1) {
        queue->front = -1;
    }
}

void displayQueue(PriorityQueue* queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong.\n");
        return;
    }
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("[Uu tien: %d, Value: %d] ", queue->array[i].priority, queue->array[i].data);
    }
    printf("\n");
}
