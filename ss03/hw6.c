#include <stdio.h>
#include <stdlib.h>

int caculataion(int *arr, int n) {
    if (n <= 0) {
        return 0;
    }
    return arr[n - 1] + caculataion(arr, n - 1);
}

int main() {
    int n;
    printf("Nhap n ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Cap phat that bai\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ", i );
        scanf("%d", &arr[i]);
    }

  
    int total = caculataion(arr, n);
    printf("result: %d\n", total);


    free(arr);

    return 0;
}
