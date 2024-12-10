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

// kiem tra stack co day khong
int isFull(Stack *stack) {
    return stack->top == MAX - 1;
}

// ham them phan tu vao stack (push)
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("stack overflow!\n");
        return;
    }
    stack->data[++stack->top] = value; // cap nhat top va them gia tri
}

// ham xoa phan tu tren cung (pop)
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("stack underflow!\n");
        return -1; // tra ve -1 de bao loi
    }
    return stack->data[stack->top--]; // tra ve gia tri tren cung va giam top
}

// ham hien thi stack
void display(Stack *stack) {
    if (isEmpty(stack)) {
        printf("stack rong!\n");
        return;
    }
    printf("stack: ");
    // duyet tu tren xuong duoi
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
        if (isFull(&stack)) {
            printf("stack day, khong the them phan tu moi!\n");
            return 0;
        }
        int value;
        printf("nhap gia tri stack[%d]: ", stack.top + 1);
        scanf("%d", &value);
        push(&stack, value);
    }

    // hien thi stack
    printf("stack sau khi them cac phan tu:\n");
    display(&stack);

    // xoa phan tu tren cung
    printf("\nthuc hien thao tac pop...\n");
    int poppedValue = pop(&stack);
    if (poppedValue != -1) {
        printf("phan tu bi xoa: %d\n", poppedValue);
    }

    // hien thi stack sau khi pop
    printf("stack sau khi pop:\n");
    display(&stack);

    return 0;
}

