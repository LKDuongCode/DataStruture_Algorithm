#include <stdio.h>
#define MAX_SIZE 100 


void insertElement(int arr[], int *n, int position, int value);
void deleteElement(int arr[], int *n, int position);
int searchElement(int arr[], int n, int value);
void updateElement(int arr[], int n, int position, int newValue);
void displayArray(int arr[], int n);

int main() {
    int arr[MAX_SIZE];
    int n = 0; 


    insertElement(arr, &n, 0, 10);
    insertElement(arr, &n, 1, 20);
    insertElement(arr, &n, 2, 30);
    displayArray(arr, n);


    deleteElement(arr, &n, 1);
    displayArray(arr, n);

    int position = searchElement(arr, n, 30);
    if (position != -1) {
        printf("Phan tu 30 duoc tim thay tai vi tri %d.\n", position);
    } else {
        printf("Phan tu 30 khong ton tai .\n");
    }

    updateElement(arr, n, 0, 50);
    displayArray(arr, n);

    return 0;
}

void insertElement(int arr[], int *n, int position, int value) {
    if (*n >= MAX_SIZE) {
        printf("Mang day, khong the them phan tu.\n");
        return;
    }
    if (position < 0 || position > *n) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    for (int i = *n; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = value;
    (*n)++;
}

void deleteElement(int arr[], int *n, int position) {
    if (*n == 0) {
        printf("Mang rong, khong the xoa phan tu.\n");
        return;
    }
    if (position < 0 || position >= *n) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    for (int i = position; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

int searchElement(int arr[], int n, int value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1; 
}

void updateElement(int arr[], int n, int position, int newValue) {
    if (position < 0 || position >= n) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    arr[position] = newValue;
}

void displayArray(int arr[], int n) {
    if (n == 0) {
        printf("Mang rong.\n");
        return;
    }
    printf("Cac phan tu trong mang: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
