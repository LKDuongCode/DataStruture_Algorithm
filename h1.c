#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node *next;
	struct Node *prev;
};
//ham in dslk
void printList (struct Node *head);
int main(){
	// tao dslk rong
	struct Node *head = NULL;
	struct Node *tail = NULL;
	struct Node *node1 = (struct Node*)malloc(sizeof(struct Node));
	struct Node *node2 = (struct Node*)malloc(sizeof(struct Node));
	struct Node *node3 = (struct Node*)malloc(sizeof(struct Node));
	struct Node *node4 = (struct Node*)malloc(sizeof(struct Node));
	
	node1->data = 10; node1->next = node2; node1->prev = NULL;
	node2->data = 20; node2->next = node3; node2->prev = node1;
	node3->data = 30; node3->next = node4; node3->prev = node2;
	node4->data = 40; node4->next = NULL; node4->prev = node3;
	head = node1;
	tail = node4;
	
	printList(tail);
	
	return 0;
}

void printList (struct Node *tail){
	struct Node *temp = tail; // tao mot con tro de duyet
	while(temp != NULL){
		printf("%d <->", temp->data);
		temp = temp->prev; // di chuyen ve phia prev
	}
	printf("NULL");
	printf("\n");
}



