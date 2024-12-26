#include<stdio.h>

void printArray(int arr[], int size);
void selectionSort(int arr[], int sz);

int main(){
	int arr[] = {4,2,6,1};
	int sz = sizeof(arr)/ sizeof(int);
	
	printArray(arr,sz);
	selectionSort(arr,sz);
	printArray(arr,sz);
	return 0; 
} 

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[], int sz){
	for (int i = 0; i<sz-1; i++){
		//b1 tim min
		int minIndex = i;
		for(int j = i+1; j<sz; j++){
			if(arr[j] < arr[minIndex]){
				//b2 cap nhat vi tri min
				minIndex = j;
			}
		}
		
		//b3 hoan doi phan tu nho nhat voi arr[i]
		if(minIndex != i){
			int temp = arr[i];
			arr[i] = arr[minIndex];
			arr[minIndex] = temp;
			
		}
	}
}
