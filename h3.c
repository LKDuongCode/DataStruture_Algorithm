#include<stdio.h>
void bubleSort (int arr[], int sz);
void printArray(int arr[], int size) ;

int main(){
	int arr[] = {4,2,6,1};
	int sz = sizeof(arr)/ sizeof(int);
	
	printArray(arr,sz);
	bubleSort(arr,sz);
	printArray(arr,sz);
	
	return 0;
}


void bubleSort (int arr[], int sz){
	for(int i = 0; i< sz-1; i++){
		for(int j = 0; j< sz-i-1; j++){
			if(arr[j] > arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
