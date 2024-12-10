#include <stdio.h>
#include <string.h>
#define MAX 100

// Khai bao struct cho stack
typedef struct {
    char data[MAX];
    int top;
} Stack;

// Ham khoi tao stack
void initStack(Stack *stack) {
    stack->top = -1; // Trang thai ban dau la rong
}

// Kiem tra stack co rong hay khong
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Kiem tra stack co day hay khong
int isFull(Stack *stack) {
    return stack->top == MAX - 1;
}

// Ham them phan tu vao stack (push)
void push(Stack *stack, char value) {
    if (isFull(stack)) {
        printf("Stack day!\n");
        return;
    }
    stack->data[++stack->top] = value; // Cap nhat top va them gia tri
}

// Ham lay phan tu ra khoi stack (pop)
char pop(Stack *stack) {
    if (isEmpty(stack)) {
        return '\0'; // Tra ve gia tri null neu stack rong
    }
    return stack->data[stack->top--]; // Lay phan tu va giam top
}

// Ham kiem tra tinh hop le cua dau ngoac trong bieu thuc
int isValidExpression(char *expr) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; i < strlen(expr); i++) {
        char ch = expr[i];

        // Neu gap dau ngoac mo, them vao stack
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&stack, ch);
        }
        // Neu gap dau ngoac dong, kiem tra xem co dau ngoac mo tuong ung khong
        if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(&stack)) {
                return 0; // Khong co dau ngoac mo tuong ung
            }
            char top = pop(&stack);
            if ((ch == ')' && top != '(') || (ch == '}' && top != '{') || (ch == ']' && top != '[')) {
                return 0; // Dau ngoac dong khong khop
            }
        }
    }

    // Neu stack con phan tu, tuc la co dau ngoac mo chua duoc dong
    return isEmpty(&stack);
}

int main() {
    char expr[MAX];

    printf("Nhap bieu thuc: ");
    fgets(expr, MAX, stdin);

    // Loai bo ky tu xuong dong neu co
    size_t len = strlen(expr);
    if (len > 0 && expr[len - 1] == '\n') {
        expr[len - 1] = '\0';
    }

    // Kiem tra tinh hop le cua bieu thuc
    if (isValidExpression(expr)) {
        printf("Hop le\n");
    } else {
        printf("Khong hop le\n");
    }

    return 0;
}

