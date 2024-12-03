#include<stdio.h>
void printArray (int arr[],int size);
void sortAsc (int arr[],int size);
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
        //sap xep tang dan
        sortAsc(arr,size);
        printArray(arr, size);
    } else {
        printf("n sai");
    }

    return 0;;
}
void sortAsc (int arr[],int size){
	//sap xep chen
	for(int i = 1;i<size;i++){
		int key = arr[i];
		int j  = i-1;
		while(j>=0 && arr[j] > key){
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = key;
		
	}
}
void printArray (int arr[],int size){
	 for(int i = 0; i<size;i++){
		printf("%d \t",arr[i]);
	 }
}


