#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct QueueLinkedList {
    Node* front;
    Node* rear;
} QueueLinkedList;

void initQueueLinkedList(QueueLinkedList* queue);
int isEmptyLinkedList(QueueLinkedList* queue);
void enqueueLinkedList(QueueLinkedList* queue, int value);
int dequeueLinkedList(QueueLinkedList* queue);
int peekLinkedList(QueueLinkedList* queue);



int main() {
    QueueLinkedList queueLinkedList;
    initQueueLinkedList(&queueLinkedList);

    enqueueLinkedList(&queueLinkedList, 100);
    enqueueLinkedList(&queueLinkedList, 200);
    enqueueLinkedList(&queueLinkedList, 300);
    printf("phan tu o dau hang doi danh sach lien ket: %d\n", peekLinkedList(&queueLinkedList));
    printf("phan tu dequeue tu hang doi danh sach lien ket: %d\n", dequeueLinkedList(&queueLinkedList));
    printf("phan tu o dau hang doi danh sach lien ket sau khi dequeue: %d\n", peekLinkedList(&queueLinkedList));

    return 0;
}


void initQueueLinkedList(QueueLinkedList* queue) {
    queue->front = queue->rear = NULL;
}

int isEmptyLinkedList(QueueLinkedList* queue) {
    return queue->front == NULL;
}

void enqueueLinkedList(QueueLinkedList* queue, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("khong du bo nho.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("da them %d vao hang doi.\n", value);
}

int dequeueLinkedList(QueueLinkedList* queue) {
    if (isEmptyLinkedList(queue)) {
        printf("hang doi rong.\n");
        return -1;
    }
    Node* temp = queue->front;
    int dequeuedValue = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return dequeuedValue;
}

int peekLinkedList(QueueLinkedList* queue) {
    if (isEmptyLinkedList(queue)) {
        printf("hang doi rong.\n");
        return -1;
    }
    return queue->front->data;
}
