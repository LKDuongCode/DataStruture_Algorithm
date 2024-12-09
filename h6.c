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

// ham thay the gia tri trong danh sach
void replaceValue(struct Node *head, int oldValue, int newValue) {
    struct Node *temp = head;
    int found = 0;

    while (temp != NULL) {
        if (temp->data == oldValue) {
            temp->data = newValue; // thay gia tri
            found = 1;
            break; // ngung tim kiem sau khi thay
        }
        temp = temp->next;
    }

    if (found) {
        printf("gia tri %d da duoc thay bang %d\n", oldValue, newValue);
    } else {
        printf("khong tim thay gia tri %d trong danh sach\n", oldValue);
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

    // nhap gia tri cu va gia tri moi
    int oldValue, newValue;
    printf("nhap gia tri can thay the: ");
    scanf("%d", &oldValue);
    printf("nhap gia tri moi: ");
    scanf("%d", &newValue);

    // thay the gia tri
    replaceValue(head, oldValue, newValue);

    // in danh sach sau khi thay the
    printf("danh sach sau khi thay the:\n");
    printList(head);

    return 0;
}

