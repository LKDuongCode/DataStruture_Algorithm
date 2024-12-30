#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data);
struct Node* search(struct Node* root, int key);

int main() {
    struct Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(20);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->right->left = createNode(15);
    root->right->right = createNode(25);

    int key;
    printf(" gia tri can tim : ");
    scanf("%d", &key);

    struct Node* result = search(root, key);
    if (result != NULL) {
        printf("tim thay.\n", result->data);
    } else {
        printf("khong tim thay.\n", key);
    }

    return 0;
}


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root; // tra ve node neu tim thay hoac cay rong
    }

    // tim trong cay con trai
    struct Node* leftSearch = search(root->left, key);
    if (leftSearch != NULL) {
        return leftSearch; 
    }

    // tim trong cay con phai
    return search(root->right, key);
}

