#include<stdio.h>
#define MAX 100
//khai bao struct cho stack
typedef struct {
	int data[MAX];
	int top;
}Stack;

//ham khoi tao
void initStack (Stack *newStack){
	 newStack->top = -1; // trang thai ban dau la rong
}


int isEmpty(Stack *stack) {
    return stack->top == -1;
}


int isFull(Stack *stack) {
    return stack->top == MAX - 1;
}

//ham hien thi
void display(Stack *stack){
	if(isEmpty(stack)){
		printf("stack underflow!");
		return;
	}
	printf("stack: ");
	//duyet tu tren(top) xuong duoi
	for(int i = stack->top; i>=0; i--){
		printf("%d ", stack->data[i]);
	}
}

int main(){
	//khoi tao
	Stack stack;
	initStack(&stack);
	int n;
	printf("nhap n:");
	scanf("%d",&n);
	
	if(n > 100){
		printf("vuot gioi han mang stack[100]");
		return 0;
	}
	//them du lieu
	for(int i = 0; i<n ;i++){
		if(isFull(&stack)){
			printf("stack overflow!");
			return 0;
		}
		int value;
		printf("stack[%d] = ",stack.top + 1);
		scanf("%d",&value);
		stack.data[++stack.top] = value; // top luc nay = -1 can chuan bi vi tri moi de them
	}
	display(&stack);
	return 0;
}



