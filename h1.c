#include <stdio.h>
#include <stdlib.h>

// Cau truc node trong danh sach lien ket don
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Khoi tao danh sach rong
Node* initList() {
    return NULL;
}

// Them phan tu vao dau danh sach
Node* addToHead(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Khong du bo nho de cap phat.\n");
        return head;
    }
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    printf("Da them %d vao dau danh sach.\n", value);
    return head;
}

// Them phan tu vao cuoi danh sach
Node* addToTail(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Khong du bo nho de cap phat.\n");
        return head;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Da them %d vao cuoi danh sach.\n", value);
    return head;
}

// Xoa phan tu o dau danh sach
Node* deleteFromHead(Node* head) {
    if (head == NULL) {
        printf("Danh sach rong, khong co phan tu de xoa.\n");
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    printf("Da xoa phan tu %d o dau danh sach.\n", temp->data);
    free(temp);
    return head;
}

// Xoa phan tu o cuoi danh sach
Node* deleteFromTail(Node* head) {
    if (head == NULL) {
        printf("Danh sach rong, khong co phan tu de xoa.\n");
        return NULL;
    }
    if (head->next == NULL) { // Danh sach chi co 1 phan tu
        printf("Da xoa phan tu %d o cuoi danh sach.\n", head->data);
        free(head);
        return NULL;
    }
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    printf("Da xoa phan tu %d o cuoi danh sach.\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
    return head;
}

// Tim kiem phan tu trong danh sach
void searchElement(Node* head, int value) {
    Node* temp = head;
    int found = 0;
    while (temp != NULL) {
        if (temp->data == value) {
            printf("Tim thay phan tu %d trong danh sach.\n", value);
            found = 1;
            break;
        }
        temp = temp->next;
    }
    if (!found) {
        printf("Khong tim thay phan tu %d trong danh sach.\n", value);
    }
}

// Hien thi cac phan tu trong danh sach
void displayList(Node* head) {
    if (head == NULL) {
        printf("Danh sach rong.\n");
        return;
    }
    printf("Cac phan tu trong danh sach: ");
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Giai phong bo nho danh sach
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("Da giai phong bo nho cua danh sach.\n");
}

int main() {
    Node* head = initList();
    int choice, value;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Them phan tu vao dau danh sach\n");
        printf("2. Them phan tu vao cuoi danh sach\n");
        printf("3. Xoa phan tu o dau danh sach\n");
        printf("4. Xoa phan tu o cuoi danh sach\n");
        printf("5. Tim kiem phan tu trong danh sach\n");
        printf("6. Hien thi danh sach\n");
        printf("7. Giai phong danh sach va thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                head = addToHead(head, value);
                break;
            case 2:
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                head = addToTail(head, value);
                break;
            case 3:
                head = deleteFromHead(head);
                break;
            case 4:
                head = deleteFromTail(head);
                break;
            case 5:
                printf("Nhap gia tri can tim: ");
                scanf("%d", &value);
                searchElement(head, value);
                break;
            case 6:
                displayList(head);
                break;
            case 7:
                freeList(head);
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai!\n");
        }
    } while (choice != 7);

    return 0;
}

