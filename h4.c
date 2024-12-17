#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100 // Kich thuoc toi da cua hang doi

// Cau truc hang doi su dung mang
typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Khoi tao hang doi
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Kiem tra hang doi co rong khong
int isEmpty(Queue* q) {
    return (q->front == -1);
}

// Kiem tra hang doi co day khong
int isFull(Queue* q) {
    return (q->rear == MAX_SIZE - 1);
}

// Them phan tu vao hang doi (enqueue)
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Hang doi day, khong the them phan tu!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0; // Dat front o vi tri dau tien neu hang doi dang rong
    }
    q->rear++;
    q->data[q->rear] = value;
    printf("Da them %d vao hang doi\n", value);
}

// Xoa phan tu khoi hang doi (dequeue)
void dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong, khong the xoa phan tu!\n");
        return;
    }
    printf("Da xoa %d khoi hang doi\n", q->data[q->front]);
    q->front++;
    if (q->front > q->rear) { // Reset hang doi neu khong con phan tu nao
        q->front = q->rear = -1;
    }
}

// Lay phan tu dau hang doi (peek)
int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong!\n");
        return -1;
    }
    return q->data[q->front];
}

// Chuong trinh chinh
int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Phan tu dau hang doi: %d\n", peek(&q));

    dequeue(&q);
    printf("Phan tu dau hang doi sau khi xoa: %d\n", peek(&q));

    dequeue(&q);
    dequeue(&q);
    dequeue(&q); // Hang doi rong

    return 0;
}

