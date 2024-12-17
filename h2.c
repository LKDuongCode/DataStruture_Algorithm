#include <stdio.h>
#include <stdlib.h>

// Dinh nghia cau truc node
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Dinh nghia cau truc danh sach lien ket doi
typedef struct {
    Node* head; // Node dau danh sach
    Node* tail; // Node cuoi danh sach
} DoublyLinkedList;

// Khoi tao danh sach lien ket doi
void initList(DoublyLinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
}

// Tao node moi
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong du bo nho!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}


void addToHead(DoublyLinkedList* list, int value) {
    Node* newNode = createNode(value);
    if (list->head == NULL) { // Danh sach rong
        list->head = list->tail = newNode;
    } else {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
}


void addToTail(DoublyLinkedList* list, int value) {
    Node* newNode = createNode(value);
    if (list->tail == NULL) { // Danh sach rong
        list->head = list->tail = newNode;
    } else {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
}


void deleteFromHead(DoublyLinkedList* list) {
    if (list->head == NULL) {
        printf("Danh sach rong, khong the xoa!\n");
        return;
    }
    Node* temp = list->head;
    if (list->head == list->tail) { // Danh sach chi co 1 node
        list->head = list->tail = NULL;
    } else {
        list->head = list->head->next;
        list->head->prev = NULL;
    }
    free(temp);
}


void deleteFromTail(DoublyLinkedList* list) {
    if (list->tail == NULL) {
        printf("Danh sach rong, khong the xoa!\n");
        return;
    }
    Node* temp = list->tail;
    if (list->head == list->tail) { // Danh sach chi co 1 node
        list->head = list->tail = NULL;
    } else {
        list->tail = list->tail->prev;
        list->tail->next = NULL;
    }
    free(temp);
}


void traverseFromTail(DoublyLinkedList* list) {
    Node* current = list->tail;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}


void freeList(DoublyLinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    list->head = list->tail = NULL;
}

int main() {
    DoublyLinkedList list;
    initList(&list);

    // Them node vao danh sach
    addToHead(&list, 10);
    addToHead(&list, 20);
    addToTail(&list, 30);
    addToTail(&list, 40);

    printf("Duyet danh sach tu dau den cuoi:\n");
    traverseFromHead(&list);

    printf("Duyet danh sach tu cuoi ve dau:\n");
    traverseFromTail(&list);

    // Xoa node
    deleteFromHead(&list);
    deleteFromTail(&list);

    printf("Sau khi xoa node o dau va cuoi:\n");
    traverseFromHead(&list);

    // Giai phong bo nho
    freeList(&list);

    return 0;
}

