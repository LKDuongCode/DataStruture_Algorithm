#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct QueueNode {
    struct Node* treeNode;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};


struct Node* createNode(int data);
struct Queue* createQueue();
int isEmpty(struct Queue* q);
void enqueue(struct Queue* q, struct Node* treeNode);
struct Node* dequeue(struct Queue* q);
int calculateHeight(struct Node* root);

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);

    int height = calculateHeight(root);
    printf("chieu cao cua cay %d\n", height);

    return 0;
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// tao hang doi
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

// them mot phan tu vao 
void enqueue(struct Queue* q, struct Node* treeNode) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->treeNode = treeNode;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

//lay phan tu ra 
struct Node* dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        return NULL;
    }
    struct QueueNode* temp = q->front;
    struct Node* treeNode = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return treeNode;
}

int calculateHeight(struct Node* root) {
    if (root == NULL) {
        return 0; // cay rong 
    }

    struct Queue* q = createQueue(); // tao hang doi
    enqueue(q, root);
    int height = 0;

    while (!isEmpty(q)) {
        int nodeCount = 0; // dem so node o moi muc
        struct QueueNode* temp = q->front;

        // dem so node trong muc hien tai
        while (temp != NULL) {
            nodeCount++;
            temp = temp->next;
        }

        // duyet tat ca cac node trong muc hien tai
        while (nodeCount--) {
            struct Node* current = dequeue(q);

            // them cac node con vao hang doi
            if (current->left != NULL) {
                enqueue(q, current->left);
            }
            if (current->right != NULL) {
                enqueue(q, current->right);
            }
        }
        height++; 
    }

    return height;
}
