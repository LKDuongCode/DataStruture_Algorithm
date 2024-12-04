#include <stdio.h>
void printArray (int arr[],int size);

void fibo(int n, int f[]) ;

int main() {
    int n;
    printf("nhap n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("khong hop le.");
        return 0;
    }
    
    int f[n]; 
    fibo(n, f); 
	printArray(f,n);
    

    return 0;
}

void printArray (int arr[],int size){
	 for(int i = 0; i<size;i++){
		printf("%d \t",arr[i]);
	 }
	 printf("\n");
}


void fibo(int n, int f[]) {
    f[0] = 0; 
    if (n > 1) {
        f[1] = 1; 
    }

    for (int i = 2; i < n; i++) {
        f[i] = f[i - 1] + f[i - 2]; 
    }
}
