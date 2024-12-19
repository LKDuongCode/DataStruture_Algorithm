#include <stdio.h>

void findDup(int arr[], int n);


int main() {
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n];
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    findDup(arr, n);

    return 0;
}

void findDup(int arr[], int n) {
    int count[n]; // Mang de dem so lan xuat hien cua tung phan tu
    int dup = 0; // Bien de kiem tra co phan tu lap lai hay khong

    // Khoi tao mang count voi gia tri 0
    for (int i = 0; i < n; i++) {
        count[i] = 0;
    }

    // Dem so lan xuat hien cua tung phan tu
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (arr[i] == arr[j]) {
                count[i]++;
            }
        }
    }

    // Kiem tra va in ra cac phan tu lap lai
    for (int i = 0; i < n; i++) {
        if (count[i] > 1) {
            // In phan tu chi mot lan
            int isPrinted = 0;
            for (int k = 0; k < i; k++) {
                if (arr[k] == arr[i]) {
                    isPrinted = 1;
                    break;
                }
            }
            if (!isPrinted) {
                printf("Phan tu %d xuat hien %d lan\n", arr[i], count[i]);
                dup = 1;
            }
        }
    }

    if (!dup) {
        printf("Khong co phan tu lap lai\n");
    }
}

