#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

// ham dem so luong phan tu trong danh sach
int countNodes(struct Node *head) {
    int count = 0;
    struct Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// ham tao danh sach va in so luong phan tu
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

    // dem so luong phan tu trong danh sach
    int count = countNodes(head);
    printf("so luong phan tu trong danh sach la: %d\n", count);

    return 0;
}

