#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5  

typedef struct {
    int arr[MAX_SIZE];  
    int front;         
    int rear;         
    int size;      
} Deque;

void initDeque(Deque* dq);
int isEmpty(Deque* dq);
int isFull(Deque* dq);
void addFront(Deque* dq, int data);
void addRear(Deque* dq, int data);
void removeFront(Deque* dq);
void removeRear(Deque* dq);
void printDeque(Deque* dq);

int main() {
    Deque dq;
    initDeque(&dq);
    addFront(&dq, 10);
    printDeque(&dq);
    addRear(&dq, 20);
    printDeque(&dq);

    addFront(&dq, 5);
    printDeque(&dq);

    removeFront(&dq);
    printDeque(&dq);
    removeRear(&dq);
    printDeque(&dq);

    return 0;
}

void initDeque(Deque* dq) {
    dq->front = -1;
    dq->rear = -1;
    dq->size = 0;
}

int isEmpty(Deque* dq) {
    return dq->size == 0;
}

int isFull(Deque* dq) {
    return dq->size == MAX_SIZE;
}

void addFront(Deque* dq, int data) {
    if (isFull(dq)) {
        printf("hang doi da day, khong the them phan tu vao dau\n");
        return;
    }

    if (dq->front == -1) {
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + MAX_SIZE) % MAX_SIZE;
    }

    dq->arr[dq->front] = data;
    dq->size++;

    printf("them phan tu vao dau: %d\n", data);
}

void addRear(Deque* dq, int data) {
    if (isFull(dq)) {
        printf("hang doi da day, khong the them phan tu vao cuoi\n");
        return;
    }

    if (dq->rear == -1) {
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % MAX_SIZE;
    }

    dq->arr[dq->rear] = data;
    dq->size++;

    printf("them phan tu vao cuoi: %d\n", data);
}

void removeFront(Deque* dq) {
    if (isEmpty(dq)) {
        printf("hang doi rong, khong the lay phan tu ra khoi dau\n");
        return;
    }

    printf("lay ra phan tu tu dau: %d\n", dq->arr[dq->front]);
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % MAX_SIZE;
    }
    dq->size--;
}

void removeRear(Deque* dq) {
    if (isEmpty(dq)) {
        printf("hang doi rong, khong the lay phan tu ra khoi cuoi\n");
        return;
    }

    printf("lay ra phan tu tu cuoi: %d\n", dq->arr[dq->rear]);
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else {
        dq->rear = (dq->rear - 1 + MAX_SIZE) % MAX_SIZE;
    }
    dq->size--;
}

void printDeque(Deque* dq) {
    if (isEmpty(dq)) {
        printf("hang doi rong\n");
        return;
    }

    printf("hang doi hien tai: [");
    int i = dq->front;
    while (i != dq->rear) {
        printf("%d, ", dq->arr[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d]\n", dq->arr[dq->rear]);
}
