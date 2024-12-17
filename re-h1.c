#include<stdio.h>
#include<stdlib.h>
//dinh nghia cau truc node
typedef struct Node {
	int data;
	struct Node *next;
} Node;

Node* initNode();
void displayList (Node *head);
Node* addToHead(Node *head, int value);
Node* addToTail(Node *head,Node *tail, int value){
	// b1:kiem tra rong
    if (tail == NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (!newNode) {
            printf("Khong the tao node moi!\n");
            return NULL; 
        }
        newNode->data = value;
        
        newNode->next = NULL;  
        head  =newNode;
        tail = newNode;
        return tail;
    }
    
    //b2 neu khong
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Khong the tao node moi!\n");
        return tail;  
    }
    
    newNode->data = value;
    newNode->next = NULL; 
    tail->next = newNode;
    tail = newNode;
    
    return tail;  
}



Node* deleteFromHead (Node *head);
void searchElement (Node *head, int value);
void freeList (Node *head);
int main(){
	//khoi tao
	Node *head = initNode();
	Node *tail = initNode();
	int choice, value;
	do{
		printf("======================MENU========================\n");
		printf("1. Hien thi danh sach.\n");
		printf("2. Them phan tu dslk\n");
		printf("3. Xoa phan tu o dau dslk\n");
		printf("4. Tim kiem phan tu theo data\n");
		printf("5. Giai phong dslk \n");
		printf("0. Thoat \n");
		printf("Nhap lua chon ");
		scanf("%d",&choice);
		
		switch (choice){
			case 0:
				break;
			case 1:
				displayList(head);
				break;
			case 2:
				printf("nhap gia tri can them data = ");
				scanf("%d",&value);
				int pos;
				printf("\n ban muon them vao vi tri nao? ");
				printf("\n 1. them vao dau");
				printf("\n 2. them vao cuoi");
				printf("\n 0. thoat \n");
				scanf("%d",&pos);
				switch (pos){
					case 1:
						head = addToHead(head,value);
						break;
					case 2:
						tail = addToTail(head,tail,value);
						break;
					case 0:
						break;
					default:
						printf("\n lua chon khong hop le!");
				}
				break;
			case 3:
				head = deleteFromHead(head);
				break;
			case 4:
				printf("\n nhap data can tim = ");
				scanf("%d",&value);
				searchElement(head,value);
				break;
			case 5:
				freeList(head);
				head = NULL;
				break;
			default:
				printf("\n lua chon khong hop le!");
				
		}
	}while (choice != 0);
	return 0;
}

Node* initNode(){
	return NULL;
}
Node* addToHead(Node *head, int value){
	//b1 khoi tao node moi
	Node* newNode = (Node*)malloc(sizeof(Node));
	if(!newNode){
		printf("ko du bo nho! \n");
		return head;
	}
	
	//b2 gan gia tri va con tro 
	newNode->data = value;
	newNode->next = head;
	head = newNode;
	printf("them thanh cong! \n");
	printf("dslk sau khi them : ");
	displayList(head);
	return head;
}
void displayList (Node *head){
	//b1. kiem tra xem co rong khong
	if(head == NULL){
		printf("dslk rong! \n");
		return;
	}
	
	// neu khong 
	Node *temp = head; // b2. tao con tro tam thoi de duyet
	while (temp != NULL){
		printf("%d -> ", temp->data);
		temp = temp->next; // b3. di chuyen den con tro tiep
	}
	printf("NULL \n");
}

void freeList (Node *head){
	// tao mot bien temp duyet va giai phong tung node trong list
	Node *temp = head ;
	while(temp != NULL){
		Node *nextNode = temp->next;
		free(temp);
		temp = nextNode;
	}
	printf("list da duoc giai phong! \n");
}

void searchElement (Node *head, int value){
	//b1 tao con tro va bien luu gia tri tim kiem
	Node *temp = head;
	int found = 0;
	int pos = 0;
	while (temp != NULL){
		if(value == temp->data){
			found = 1;
			printf("phan tu %d o vi tri list[%d] \n",value, pos);
			break;
		}
		pos ++;
		temp = temp->next;
	}
	
	if(found == 0){
		printf("khong tim thay phan tu %d trong dslk!\n", value);
	}
}
Node* deleteFromHead (Node *head){
	//b1 kiem tra rong
	if(head == NULL){
		printf("/n dslk rong!");
		return head;
	}
	//b2 thay doi gia tri head
	Node *temp = head;
	head = head->next;
	free(temp);
	printf("xoa phan tu dau dslk thanh cong. Sau khi xoa: ");
	displayList(head);
	return head;
}

