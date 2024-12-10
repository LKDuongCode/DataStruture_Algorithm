#include <stdio.h>
#include <string.h>
#define MAX 100

// khai bao struct cho stack
typedef struct {
    char data[MAX];
    int top;
} Stack;

// ham khoi tao stack
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
void push(Stack *stack, char value) {
    if (isFull(stack)) {
        printf("stack day, khong the them phan tu moi!\n");
        return;
    }
    stack->data[++stack->top] = value; // cap nhat top va them gia tri
}

// ham lay phan tu ra khoi stack (pop)
char pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("stack rong, khong co phan tu de lay ra!\n");
        return '\0'; // tra ve ky tu null
    }
    return stack->data[stack->top--]; // tra ve gia tri tren cung va giam top
}

// ham dao nguoc chuoi su dung stack
void reverseString(char *str) {
    Stack stack;
    initStack(&stack);

    // them tung ky tu cua chuoi vao stack
    for (int i = 0; str[i] != '\0'; i++) {
        push(&stack, str[i]);
    }

    // lay ky tu ra khoi stack de tao chuoi dao nguoc
    int i = 0;
    while (!isEmpty(&stack)) {
        str[i++] = pop(&stack);
    }
    str[i] = '\0'; // ket thuc chuoi dao nguoc
}

int main() {
    char str[MAX];

    printf("nhap chuoi (toi da %d ky tu): ", MAX - 1);
    fgets(str, MAX, stdin);

    // loai bo ky tu xuong dong neu co
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    printf("chuoi ban dau: %s\n", str);

    // dao nguoc chuoi
    reverseString(str);

    printf("chuoi sau khi dao nguoc: %s\n", str);

    return 0;
}
#include<stdio.h>

int main(){
	return 0;
}



