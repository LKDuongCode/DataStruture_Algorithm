#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 5

typedef struct {
    int priority; 
    char data[50]; // string
} Task;

typedef struct {
    Task arr[MAX_SIZE];
    int size;           
} PriorityQueue;

void initQueue(PriorityQueue* q);
int isEmpty(PriorityQueue* q);
void enqueue(PriorityQueue* q, int priority, const char* data);
void dequeue(PriorityQueue* q);
void printQueue(PriorityQueue* q);

int main() {
    PriorityQueue pq;
    initQueue(&pq);
    enqueue(&pq, 2, "Task A");
    printQueue(&pq);

    enqueue(&pq, 1, "Task B");
    printQueue(&pq);

    enqueue(&pq, 3, "Task C");
    printQueue(&pq);

    dequeue(&pq);
    printQueue(&pq);

    dequeue(&pq);
    printQueue(&pq);

    return 0;
}

void initQueue(PriorityQueue* q) {
    q->size = 0;
}

int isEmpty(PriorityQueue* q) {
    return q->size == 0;
}

void enqueue(PriorityQueue* q, int priority, const char* data) {
    if (q->size >= MAX_SIZE) {
        printf("hang doi da day, khong the them phan tu %s\n", data);
        return;
    }

    // tim vi tri thich hop de chen phan tu vao sao cho hang doi luon duoc sap xep theo muc do uu tien giam dan
    int i = q->size - 1;
    while (i >= 0 && q->arr[i].priority > priority) {
        q->arr[i + 1] = q->arr[i];
        i--;
    }
    q->arr[i + 1].priority = priority;
    strcpy(q->arr[i + 1].data, data);
    q->size++;

    printf("them phan tu (%d, \"%s\") vao hang doi\n", priority, data);
}

void dequeue(PriorityQueue* q) {
    if (isEmpty(q)) {
        printf("hang doi rong, khong the lay phan tu\n");
        return;
    }

    printf("lay ra phan tu: \"%s\" (uu tien %d)\n", q->arr[0].data, q->arr[0].priority);

    // dich chuyen cac phan tu con lai len mot vi tri
    for (int i = 0; i < q->size - 1; i++) {
        q->arr[i] = q->arr[i + 1];
    }

    q->size--;
}

void printQueue(PriorityQueue* q) {
    if (isEmpty(q)) {
        printf("hang doi rong\n");
        return;
    }

    printf("trang thai hang doi: ");
    for (int i = 0; i < q->size; i++) {
        printf("(%d, \"%s\") ", q->arr[i].priority, q->arr[i].data);
    }
    printf("\n");
}
