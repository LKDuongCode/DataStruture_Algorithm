#include<stdio.h>

void printArray (int arr[], int size);
void revert(int arr[], int size) ;

int main(){
    int n;
    printf("nhap do dai cua mang:\n");
    scanf("%d", &n);
    
    if (0 < n && n <= 100) {
        // Nhap vao mang so nguyen
        int arr[n];
        int size = sizeof(arr) / sizeof(arr[0]);
        
        for(int i = 0; i < n; i++) {
            printf("pt%d: ", i); 
            scanf("%d", &arr[i]);
        }
        //dao nguoc mang
        revert(arr,size);
        printArray(arr, size);
    } else {
        printf("n sai");
    }

    return 0;
}
void revert(int arr[], int size) {
    for(int i = 0; i < size / 2; i++) {
        int term = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = term;
    }
}
void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d \t", arr[i]);
    }
    printf("\n");
}

