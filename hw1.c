//khoi tao va in linked list. 
#include<stdio.h>
#include<stdlib.h>
//dinh nghia kieu cau truc node
struct Node {
	int data;
	struct Node *next;
};
//ham tao mot node o cuoi
struct Node *createNode ();
//ham tao mot linkedList
struct Node *createLinkedList (int size);
void printList(struct Node *head);

int main(){
	int size;
	//nhap so phan tu se co trong dslk
	printf("nhap so node se co:"); scanf("%d",&size);
	if(0<=size && size<=1000){
		struct Node *newList = createLinkedList(size);
		printList(newList);
		free(newList);
		return 0;
	}
	
	printf("size khong hop le");
	return 0;
}

struct Node *createNode (){
	//lay du lieu data cho mot node
	int data;
	printf("nhap data:");
	scanf("%d",&data);
	
	//khoi tao node va gan du lieu
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	if (newNode == NULL) {  
        printf("khong du bo nho\n");
        exit(1);
    }
	newNode->data = data;
	newNode->next = NULL;
	
	return newNode;
}

struct Node *createLinkedList (int size){

	// khoi tao mot linkedlist
	struct Node *head = NULL;
	struct Node *tail = NULL; 
	//tao tung node va dua vao trong dslk
	for(int i = 0; i<size;i++){
		struct Node *newNode = createNode();
		//neu dslk rong - gan head = node moi tao
		if(head == NULL){
			head = newNode;
			tail = newNode;
		}
		
		//neu co du lieu
		tail->next = newNode;
		tail = newNode;
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

