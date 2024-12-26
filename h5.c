#include<stdio.h>

void printArray(int arr[], int size);
void insertionSort (int arr[], int sz);

int main(){
	int arr[] = {4,2,6,1};
	int sz = sizeof(arr)/ sizeof(int);
	
	printArray(arr,sz);
	insertionSort(arr,sz);
	printArray(arr,sz);
	return 0;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void insertionSort (int arr[], int sz){
	for(int i = 1; i<sz; i++){
		//b1 tao key lam chot giua hai mang
		int key = arr[i];
		int j = i - 1;
		//b2 chuyen cac phan tu > key ve sau 
		while(j>=0 && arr[j] > key){
			arr[j+1] = arr[j];
			j--;
		}
		
		//b3 chen key vao vi tri dung
		arr[j+1] = key;
	}
}
