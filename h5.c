#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data);
int findMax(struct Node* root);

int main() {
    struct Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(20);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->right->left = createNode(15);
    root->right->right = createNode(25);
    
    int maxValue = findMax(root);
    if(maxValue != -1){
    	printf("gia tri lon nhat la: %d\n", maxValue);
	}else{
		printf("khong thay");
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

int findMax(struct Node* root) {
    if (root == NULL) {
        return -1;
    }

    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);

    // ss gia tri cua nut hien tai voi gia tri lon nhat cua hai cay con
    int max = root->data;
    if (leftMax > max) {
        max = leftMax;
    }
    if (rightMax > max) {
        max = rightMax;
    }
    return max;
}

