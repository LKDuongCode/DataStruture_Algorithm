#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
    int size;
} Deque;

void initDeque(Deque *dq);
bool isEmpty(Deque *dq);
bool isFull(Deque *dq);
void printDeque(Deque *dq);
void addFront(Deque *dq, int data);
void addRear(Deque *dq, int data);
void removeFront(Deque *dq);
void removeRear(Deque *dq);

int main() {
    Deque dq;
    initDeque(&dq);
    
    addRear(&dq, 10);
    addRear(&dq, 20);
    addFront(&dq, 5);
    addFront(&dq, 1);
    removeFront(&dq);
    removeRear(&dq);
    addRear(&dq, 30);
    removeFront(&dq);
    removeRear(&dq);
    removeRear(&dq);

    return 0;
}


void initDeque(Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
    dq->size = 0;
}

bool isEmpty(Deque *dq) {
    return dq->size == 0;
}

bool isFull(Deque *dq) {
    return dq->size == MAX_SIZE;
}

void printDeque(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Hang doi rong\n");
        return;
    }
    printf("Hang doi hien tai: ");
    int i = dq->front;
    for (int count = 0; count < dq->size; count++) {
        printf("%d ", dq->data[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

void addFront(Deque *dq, int data) {
    if (isFull(dq)) {
        printf("Hang doi day, khong the them phan tu moi.\n");
        return;
    }
    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + MAX_SIZE) % MAX_SIZE;
    }
    dq->data[dq->front] = data;
    dq->size++;
    printf("Them phan tu %d vao dau hang doi.\n", data);
    printDeque(dq);
}

void addRear(Deque *dq, int data) {
    if (isFull(dq)) {
        printf("Hang doi day, khong the them phan tu moi.\n");
        return;
    }
    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % MAX_SIZE;
    }
    dq->data[dq->rear] = data;
    dq->size++;
    printf("Them phan tu %d vao cuoi hang doi.\n", data);
    printDeque(dq);
}

void removeFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Hang doi rong, khong the lay phan tu.\n");
        return;
    }
    int removedData = dq->data[dq->front];
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % MAX_SIZE;
    }
    dq->size--;
    printf("Lay phan tu %d tu dau hang doi.\n", removedData);
    printDeque(dq);
}

void removeRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Hang doi rong, khong the lay phan tu.\n");
        return;
    }
    int removedData = dq->data[dq->rear];
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else {
        dq->rear = (dq->rear - 1 + MAX_SIZE) % MAX_SIZE;
    }
    dq->size--;
    printf("Lay phan tu %d tu cuoi hang doi.\n", removedData);
    printDeque(dq);
}
