#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct StackLinkedList {
    Node* top;
} StackLinkedList;

void initStackLinkedList(StackLinkedList* stack);
int isEmptyLinkedList(StackLinkedList* stack);
void pushLinkedList(StackLinkedList* stack, int value);
int popLinkedList(StackLinkedList* stack);
int peekLinkedList(StackLinkedList* stack);


int main() {

    StackLinkedList stackLinkedList;
    initStackLinkedList(&stackLinkedList);

    pushLinkedList(&stackLinkedList, 100);
    pushLinkedList(&stackLinkedList, 200);
    pushLinkedList(&stackLinkedList, 300);
    printf("phan tu tren dinh ngan xep danh sach lien ket: %d\n", peekLinkedList(&stackLinkedList));
    printf("phan tu pop tu ngan xep danh sach lien ket: %d\n", popLinkedList(&stackLinkedList));
    printf("phan tu tren dinh ngan xep danh sach lien ket sau khi pop: %d\n", peekLinkedList(&stackLinkedList));

    return 0;
}


void initStackLinkedList(StackLinkedList* stack) {
    stack->top = NULL;
}

int isEmptyLinkedList(StackLinkedList* stack) {
    return stack->top == NULL;
}

void pushLinkedList(StackLinkedList* stack, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("khong du bo nho.\n");
        return;
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("da them %d vao ngan xep.\n", value);
}

int popLinkedList(StackLinkedList* stack) {
    if (isEmptyLinkedList(stack)) {
        printf("ngan xep rong.\n");
        return -1;
    }
    Node* temp = stack->top;
    int poppedValue = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return poppedValue;
}

int peekLinkedList(StackLinkedList* stack) {
    if (isEmptyLinkedList(stack)) {
        printf("ngan xep rong.\n");
        return -1;
    }
    return stack->top->data;
}
