#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

// ham in danh sach lien ket
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// ham dao nguoc danh sach lien ket doi
void reverseList(struct Node **head) {
    struct Node *current = *head;
    struct Node *temp = NULL;

    // doi next va prev cua tung node
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; // di chuyen nguoc do prev da hoan doi
    }

    // cap nhat lai head
    if (temp != NULL) {
        *head = temp->prev;
    }
}

int main() {
    // tao danh sach lien ket doi
    struct Node *head = NULL;

    // tao cac node ban dau
    struct Node *node1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *node2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *node3 = (struct Node *)malloc(sizeof(struct Node));

    node1->data = 10; node1->next = node2; node1->prev = NULL;
    node2->data = 20; node2->next = node3; node2->prev = node1;
    node3->data = 30; node3->next = NULL; node3->prev = node2;
    head = node1;

    // in danh sach ban dau
    printf("danh sach ban dau:\n");
    printList(head);

    // dao nguoc danh sach
    reverseList(&head);

    // in danh sach sau khi dao nguoc
    printf("danh sach sau khi dao nguoc:\n");
    printList(head);

    return 0;
}

