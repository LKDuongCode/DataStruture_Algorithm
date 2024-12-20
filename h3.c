#include<stdio.h>
void selectionSort(int arr[], int n);
void printArr(int arr[], int n);
void binarySearch (int arr[], int n);
int main(){
	int n;
	printf("nhap n ");
	scanf("%d",&n);
	int arr[n];
	for(int i = 0; i< n; i++){
		printf("arr[%d] = ",i);
		scanf("%d",&arr[i]);
	}
	printArr(arr,n);
	selectionSort(arr,n);
	printArr(arr,n);
	
	binarySearch(arr,n);
	return 0;
}

void printArr(int arr[], int n){
	for(int i = 0; i<n; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void selectionSort(int arr[], int n){
	for(int i = 0; i< n-1; i++){
		for(int j = i+1; j<n; j++){
			if(arr[i] > arr[j]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
}

void binarySearch (int arr[], int n){
	printf("nhap phan tu can tim: ");
	int searchValue;
	scanf("%d",&searchValue);
	
	int indexFound = -1;
	int start = 0;
	int end = n;
	int mid;
	while (start <= end){
		mid = (start+end)/2;
		if(arr[mid] == searchValue){
			indexFound =  mid;
			break;
		}
		else if(arr[mid] < searchValue){
			start = mid + 1;
		}
		else{
			end = mid -1;
		}
	}
	
	if(indexFound != -1){
		printf("tim thay phan tu %d o vi tri %d", arr[indexFound], indexFound);
	}else{
		printf("khong tim thay phan tu %d", n);
	}
	
}
