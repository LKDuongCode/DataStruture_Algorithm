#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data);
struct Node* insertNode(struct Node* root, int data);
int countNodesGreaterThanX(struct Node* root, int x);

int main() {
    struct Node* root = NULL;
    int n, x, value;

    printf(" so luong phan tu can chen: ");
    scanf("%d", &n);

    printf(" cac gia tri de tao cay:\n");
    for (int i = 0; i < n; i++) {
        printf("gia tri thu %d: ", i + 1);
        scanf("%d", &value);
        root = insertNode(root, value);
    }

    printf("nhap gia tri X: ");
    scanf("%d", &x);

    int count = countNodesGreaterThanX(root, x);
    printf("so nut lon hon %d: %d\n", x, count);

    return 0;
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data); 
    }
    root->left = insertNode(root->left, data); 
    return root;
}

int countNodesGreaterThanX(struct Node* root, int x) {
    if (root == NULL) {
        return 0;
    }

    int count = 0;
    if (root->data > x) {
        count = 1; 
    }

    return count + countNodesGreaterThanX(root->right, x);
}
