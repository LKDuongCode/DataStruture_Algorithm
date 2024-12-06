#include<stdio.h>
#include<stdlib.h>

// Dinh nghia kieu cau truc node
struct Node {
    int data;
    struct Node *next;
};

// Ham tao mot node o cuoi
struct Node *createNode();
// Ham tao mot linkedList
struct Node *createLinkedList(int size);
void printList(struct Node *head);
int searchInList(struct Node *head, int target);

int main() {
    int size;
    // Nhap so phan tu se co trong dslk
    printf("Nhap so node se co: "); 
    scanf("%d", &size);

    if (0 <= size && size <= 1000) {
        struct Node *newList = createLinkedList(size);
        printList(newList);

        // Tim kiem phan tu
        int target;
        printf("Nhap phan tu muon tim: ");
        scanf("%d", &target);

        int index = searchInList(newList, target);
        if (index != -1) {
            printf("Phan tu %d duoc tim thay o vi tri: %d\n", target, index);
        } else {
            printf("Phan tu %d khong co trong danh sach lien ket.\n", target);
        }

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
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Khong du bo nho\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

struct Node *createLinkedList(int size) {
    // Khoi tao mot linkedlist
    struct Node *head = NULL;
    struct Node *tail = NULL; 

    // Tao tung node va dua vao trong dslk
    for (int i = 0; i < size; i++) {
        struct Node *newNode = createNode();
        // Neu dslk rong - gan head = node moi tao
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

int searchInList(struct Node *head, int target) {
    struct Node *temp = head;
    int index = 0;

    // Duyet danh sach lien ket
    while (temp != NULL) {
        if (temp->data == target) {
            return index; // Tra ve vi tri neu tim thay
        }
        temp = temp->next;
        index++;
    }

    return -1; // Tra ve -1 neu khong tim thay
}

