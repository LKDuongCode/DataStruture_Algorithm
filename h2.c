#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node *next;
	struct Node *prev;
};
//ham in dslk
void printList (struct Node *head);
struct Node *createNode();
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
	printf("list ban dau: ");
	printList(head);
	
	
	
	return 0;
}

void printList (struct Node *head){
	struct Node *temp = head; // tao mot con tro de duyet
	printf("NULL <->");
	while(temp != NULL){
		printf("%d <->", temp->data);
		temp = temp->next; 
	}
	printf("NULL ");
	printf("\n");
}

struct Node *createNode(){
	int data;
	printf("nhap data cho nut moi");
	scanf("%d",&data);
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

void addNewNode (struct Node**, struct Node **tail, int pos){
	if(pos < 0){
		printf("vi tri khong hop le!");
		return;
	}
	
	struct Node *newNode = createNode();
	if(pos == 0){
		newNode->next = *head;
		*head->prev = newNode;
		*head = newNode;
		return;
	}
	
	struct Node *temp = *head;
	int curPos = 0;
	//tim vi tri truoc vi tri chen; 1-2-3 => chen vao 3 thi tra ve 2
	while (temp != NULL && curPos < pos -1){
		temp = temp->next;
		curPos++;
	}
	
	if(temp == NULL){// neu tim thay la phan tu cuoi
		newNode->prev = *tail;
		*tail->next = newNode;
		*tail = newNode;
		
	}else{
		newNode->next = temp->next;
		newNode->prev = temp;
		if(temp->next != NULL){ // neu gan cuoi
			struct Node* nextNode = temp->next;
			nextNode->prev = newNode;    

		}else{
			*tail = newNode;
		}
		 temp->next = newNode;
	}
}




