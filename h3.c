#include <stdio.h>
#define MAX 100

// khai bao struct cho stack
typedef struct {
    int data[MAX];
    int top;
} Stack;

// ham khoi tao
void initStack(Stack *newStack) {
    newStack->top = -1; // trang thai ban dau la rong
}

// kiem tra stack co rong khong
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// ham them phan tu vao stack (push)
void push(Stack *stack, int value) {
    if (stack->top == MAX - 1) {
        printf("stack day, khong the them phan tu moi!\n");
        return;
    }
    stack->data[++stack->top] = value; // cap nhat top va them gia tri
}

// ham hien thi stack
void display(Stack *stack) {
    if (isEmpty(stack)) {
        printf("stack rong!\n");
        return;
    }
    printf("stack: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

int main() {
    // khoi tao stack
    Stack stack;
    initStack(&stack);

    int n;
    printf("nhap so luong phan tu muon them vao stack (toi da 100): ");
    scanf("%d", &n);

    // kiem tra gioi han
    if (n > MAX) {
        printf("vuot qua gioi han stack[%d]\n", MAX);
        return 0;
    }

    // them phan tu vao stack
    for (int i = 0; i < n; i++) {
        int value;
        printf("nhap gia tri stack[%d]: ", stack.top + 1);
        scanf("%d", &value);
        push(&stack, value);
    }

    // hien thi stack sau khi them
    printf("\nstack sau khi them cac phan tu:\n");
    display(&stack);

    // kiem tra stack co rong khong
    if (isEmpty(&stack)) {
        printf("ngan xep rong.\n");
    } else {
        printf("ngan xep khong rong.\n");
    }

    return 0;
}

