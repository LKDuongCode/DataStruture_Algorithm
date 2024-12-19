#include <stdio.h>

int binarySearch(int arr[], int left, int right, int target);

int main() {
    int n, target;
    printf("nhap so phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n];
    printf("nhap cac phan tu cua mang (da sap xep):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("nhap gia tri can tim: ");
    scanf("%d", &target);

    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1) {
        printf("phan tu %d nam o vi tri: %d\n", target, result);
    } else {
        printf("phan tu khong ton tai\n");
    }

    return 0;
}


int binarySearch(int arr[], int left, int right, int target) {
    if (left > right) {
        return -1; // tra ve -1 neu khong tim thay
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
        return mid; // tra ve vi tri phan tu
    } else if (arr[mid] > target) {
        return binarySearch(arr, left, mid - 1, target); // tim ben trai
    } else {
        return binarySearch(arr, mid + 1, right, target); // tim ben phai
    }
}
