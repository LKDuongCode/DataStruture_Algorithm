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

// ham xoa phan tu cuoi cung trong danh sach
void deleteLastNode(struct Node **head) {
    // kiem tra neu danh sach rong
    if (*head == NULL) {
        printf("danh sach rong, khong the xoa!\n");
        return;
    }

    // neu danh sach chi co mot phan tu
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    // duyet den node cuoi cung
    struct Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // ngat lien ket node cuoi cung
    temp->prev->next = NULL;
    free(temp);
}

int main() {
    // tao danh sach lien ket doi
    struct Node *head = NULL;

    // tao cac node ban dau
    struct Node *node1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *node2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *node3 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *node4 = (struct Node *)malloc(sizeof(struct Node));

    node1->data = 10; node1->next = node2; node1->prev = NULL;
    node2->data = 20; node2->next = node3; node2->prev = node1;
    node3->data = 30; node3->next = node4; node3->prev = node2;
    node4->data = 40; node4->next = NULL; node4->prev = node3;
    head = node1;

    // in danh sach ban dau
    printf("danh sach ban dau:\n");
    printList(head);

    // xoa phan tu cuoi cung
    printf("xoa phan tu cuoi cung...\n");
    deleteLastNode(&head);

    // in danh sach sau khi xoa
    printf("danh sach sau khi xoa phan tu cuoi cung:\n");
    printList(head);

    return 0;
}
