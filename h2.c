#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* initList();
void insertAtBeginning(Node** head, int value);
void insertAtEnd(Node** head, int value);
void deleteAtPosition(Node** head, int position);
Node* search(Node* head, int value);
void updateAtPosition(Node* head, int position, int newValue);
void displayList(Node* head);

int main() {
    Node* head = initList();
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    displayList(head);

    deleteAtPosition(&head, 1);
    displayList(head);

    Node* searchResult = search(head, 30);
    if (searchResult != NULL) {
        printf("%d.\n", searchResult->data);
    } else {
        printf("khong thay.\n");
    }

    updateAtPosition(head, 1, 50);
    printf("danh sach sau khi cap nhat 1: \n");
    displayList(head);

    return 0;
}


Node* initList() {
    return NULL;
}

void insertAtBeginning(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Không d? b? nh?.\n");
        return;
    }
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteAtPosition(Node** head, int position) {
    if (*head == NULL) {
        printf("danh sach rong.\n");
        return;
    }

    Node* temp = *head;

    if (position == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        return;
    }

    Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

Node* search(Node* head, int value) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == value) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void updateAtPosition(Node* head, int position, int newValue) {
    Node* temp = head;
    for (int i = 0; temp != NULL && i < position; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    temp->data = newValue;
}

void displayList(Node* head) {
    if (head == NULL) {
        printf("danh sach rong\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
