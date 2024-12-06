#include <stdio.h>
#include <stdlib.h>

// Dinh nghia kieu cau truc node
struct Node {
    int data;
    struct Node *next;
};

// Ham tao mot node
struct Node *createNode();
// Ham tao mot linked list
struct Node *createLinkedList(int size);
// Ham hien thi danh sach lien ket
void printList(struct Node *head);
// Ham xoa phan tu dau tien khoi danh sach lien ket
void deleteHead(struct Node **head);

int main() {
    int size;
    // Nhap so phan tu se co trong danh sach lien ket
    printf("Nhap so node se co: ");
    scanf("%d", &size);

    if (0 <= size && size <= 1000) {
        struct Node *newList = createLinkedList(size);
        
        // Hien thi danh sach ban dau
        printf("Danh sach ban dau:\n");
        printList(newList);
        
        // Xoa phan tu dau tien
        deleteHead(&newList);
        
        // Hien thi danh sach sau khi xoa
        printf("Danh sach sau khi xoa phan tu dau:\n");
        printList(newList);
        
        // Giai phong bo nho
        free(newList);
        return 0;
    }

    printf("Size khong hop le\n");
    return 0;
}

struct Node *createNode() {
    // Lay du lieu data cho mot node
    int data;
    printf("Nhap data: ");
    scanf("%d", &data);

    // Khoi tao node va gan du lieu
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Khong du bo nho\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

struct Node *createLinkedList(int size) {
    // Khoi tao mot linked list
    struct Node *head = NULL;
    struct Node *tail = NULL;

    // Tao tung node va dua vao danh sach lien ket
    for (int i = 0; i < size; i++) {
        struct Node *newNode = createNode();
        // Neu danh sach lien ket rong - gan head = node moi tao
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            // Neu co du lieu
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteHead(struct Node **head) {
    // Kiem tra danh sach co rong khong
    if (*head == NULL) {
        printf("Danh sach rong, khong the xoa phan tu dau.\n");
        return;
    }

    // Luu lai node dau
    struct Node *temp = *head;
    // Di chuyen head den node ke tiep
    *head = (*head)->next;
    // Giai phong bo nho cua node dau
    free(temp);
}
