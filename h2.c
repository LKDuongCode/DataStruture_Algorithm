#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode();
struct Node* createLinkedList();
void printList(struct Node *head);
void addNodeToHead(struct Node**head);
//-------------------------------------------------------------------------
int main() {
    struct Node *linkedList = createLinkedList();
    printf("ban dau: ");
    printList(linkedList);
    printf("\n");
    

    addNodeToHead(&linkedList);
    printf("sau khi them: ");
    printList(linkedList);
    return 0;
}

// Hàm tao moi node
struct Node* createNode() {
    int data;
    printf("Nhap data: ");
    scanf("%d", &data);

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// tao danh sach lien ket
struct Node* createLinkedList() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    struct Node *head = NULL;

    for (int i = 0; i < n; i++) {
        struct Node *newNode = createNode();
        if (head == NULL) {
            head = newNode;
        } else {
            struct Node *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    return head;
}

//them node vao dau dslk
void addNodeToHead(struct Node**head){
	struct Node *newNode = createNode();
	newNode->next = *head;
	*head = newNode;
}

// in dslk
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

