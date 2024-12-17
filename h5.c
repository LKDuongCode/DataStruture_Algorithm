#include <stdio.h>
#include <stdlib.h>

// Cau truc node cua cay nhi phan
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Tao node moi
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong du bo nho!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Them phan tu vao cay nhi phan
Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    } else {
        printf("Gia tri %d da ton tai trong cay!\n", value);
    }
    return root;
}

// Duyet cay theo thu tu truoc (PreOrder)
void preOrder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Duyet cay theo thu tu giua (InOrder)
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Duyet cay theo thu tu sau (PostOrder)
void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

// Tim kiem phan tu trong cay
Node* search(Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return search(root->left, value);
    }
    return search(root->right, value);
}

// Menu lua chon
void menu() {
    printf("\n----- MENU -----\n");
    printf("1. Them phan tu vao cay\n");
    printf("2. Duyet cay theo thu tu truoc (PreOrder)\n");
    printf("3. Duyet cay theo thu tu giua (InOrder)\n");
    printf("4. Duyet cay theo thu tu sau (PostOrder)\n");
    printf("5. Tim kiem phan tu trong cay\n");
    printf("6. Thoat chuong trinh\n");
    printf("-----------------\n");
}

int main() {
    Node* root = NULL;
    int choice, value;

    do {
        menu();
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Da them %d vao cay\n", value);
                break;
            case 2:
                printf("Duyet cay theo thu tu truoc (PreOrder): ");
                preOrder(root);
                printf("\n");
                break;
            case 3:
                printf("Duyet cay theo thu tu giua (InOrder): ");
                inOrder(root);
                printf("\n");
                break;
            case 4:
                printf("Duyet cay theo thu tu sau (PostOrder): ");
                postOrder(root);
                printf("\n");
                break;
            case 5:
                printf("Nhap gia tri can tim kiem: ");
                scanf("%d", &value);
                Node* result = search(root, value);
                if (result != NULL) {
                    printf("Tim thay phan tu %d trong cay.\n", value);
                } else {
                    printf("Khong tim thay phan tu %d trong cay.\n", value);
                }
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le! Vui long thu lai.\n");
        }
    } while (choice != 6);

    return 0;
}

