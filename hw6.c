#include<stdio.h>
#include<stdlib.h>

void printArray(int arr[], int size);
void createDynamicArray(int **arr, int *n);
void mergeArrays(int **arr1, int *arr2, int *n, int m);

int main() {
    int n, m;
    int *arr1, *arr2;
    printf("Nhap do dai cua mang 1: ");
    createDynamicArray(&arr1, &n);
    printf("Nhap do dai cua mang2: ");
    createDynamicArray(&arr2, &m);

    // Gop hai mang lai
    mergeArrays(&arr1, arr2, &n, m);

    printf("Mang sau khi gop: ");
    printArray(arr1, n);

    free(arr1);
    free(arr2);
    return 0;
}

void createDynamicArray(int **arr, int *n) {
    scanf("%d", n);
    if (*n <= 0) {
        printf("Do dai mang phai lon hon 0.\n");
        exit(1);
    }
    *arr = (int *) malloc((*n) * sizeof(int));
    if (*arr == NULL) {
        printf("Cap phat bo nho that bai!\n");
        exit(1);
    }
    printf("Nhap gia tri mang: \n");
    for (int i = 0; i < *n; i++) {
        printf("pt %d: ", i + 1);
        scanf("%d", &((*arr)[i]));
    }
}

void mergeArrays(int **arr1, int *arr2, int *n, int m) {
    *arr1 = (int *) realloc(*arr1, (*n + m) * sizeof(int));
    if (*arr1 == NULL) {
        printf("Mo rong that bai\n");
        exit(1);
    }
    for (int i = 0; i < m; i++) {
        (*arr1)[*n + i] = arr2[i];
    }
    *n += m;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

