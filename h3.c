#include <stdio.h>
#include <stdlib.h>

// Cau truc mot node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Cau truc ngan xep
typedef struct Stack {
    Node* top;
} Stack;

// Khoi tao ngan xep
void initStack(Stack* s) {
    s->top = NULL;
}

// Kiem tra ngan xep rong
int isEmpty(Stack* s) {
    return s->top == NULL;
}

// Them phan tu vao ngan xep
void push(Stack* s, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Khong du bo nho.\n");
        return;
    }
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
    printf("Da them %d vao ngan xep.\n", value);
}

// Xoa phan tu khoi ngan xep
void pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Ngan xep rong, khong the xoa phan tu.\n");
        return;
    }
    Node* temp = s->top;
    printf("Da xoa %d khoi ngan xep.\n", temp->data);
    s->top = temp->next;
    free(temp);
}

// Xem phan tu tren cung cua ngan xep
void peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Ngan xep rong, khong co phan tu tren cung.\n");
        return;
    }
    printf("Phan tu tren cung cua ngan xep: %d\n", s->top->data);
}

// Hien thi cac phan tu trong ngan xep
void display(Stack* s) {
    if (isEmpty(s)) {
        printf("Ngan xep rong.\n");
        return;
    }
    printf("Cac phan tu trong ngan xep: ");
    Node* current = s->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Stack s;
    int choice, value;

    initStack(&s);

    do {
        printf("\n--- MENU ---\n");
        printf("1. Them phan tu vao ngan xep (Push)\n");
        printf("2. Xoa phan tu khoi ngan xep (Pop)\n");
        printf("3. Xem phan tu tren cung (Peek)\n");
        printf("4. Kiem tra ngan xep rong\n");
        printf("5. Hien thi cac phan tu\n");
        printf("6. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                peek(&s);
                break;
            case 4:
                if (isEmpty(&s)) {
                    printf("Ngan xep dang rong.\n");
                } else {
                    printf("Ngan xep khong rong.\n");
                }
                break;
            case 5:
                display(&s);
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 6);

    return 0;
}

