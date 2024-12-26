#include<stdio.h>

void printArray(int arr[], int sz);
void createArray(int arr[], int sz);
void insertionSort (int arr[], int sz);
int linearSearch (int arr[], int sz);
int binarySearch (int arr[], int sz);

int main(){
	int sz;
	printf("nhap size mang: ");
	scanf("%d",&sz);
	int arr[sz];
	
	createArray(arr,sz);
	printf("mang ban dau: \n");
	printArray(arr,sz);
	
	insertionSort(arr,sz);
	printf("mang sau sap xep: \n");
	printArray(arr,sz);
	
	int	indexFoundBinary = binarySearch(arr,sz);
	if(!indexFoundBinary){
		printf("khong tim thay");
	}else{
		printf("tim thay %d o vi tri %d", arr[indexFoundBinary], indexFoundBinary);
	}
	
	
	
	int indexFoundLinear = linearSearch(arr,sz);
	if(!indexFoundLinear){
		printf("khong tim thay");
	}else{
		printf("\n tim thay %d o vi tri %d", arr[indexFoundLinear], indexFoundLinear);
	}
	
	return 0;
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void createArray(int arr[], int sz){
	for(int i = 0; i < sz; i++){
		printf("arr[%d] = ", i);
		scanf("%d", &arr[i]);
	}
}


void insertionSort(int arr[], int sz){
	for (int i = 1; i < sz; i++){
		int key = arr[i];
		int j = i - 1;
		while(j >= 0 && arr[j] > key){
			arr[j+1] = arr[j];
			j--;
		}
		
		arr[j+1] = key;
	}
}


int linearSearch (int arr[], int sz){
	int findValue;
	printf("tim kiem tuyen tinh : ");
	scanf("%d",&findValue);
	
	for(int i = 0; i< sz; i++){
		if(arr[i] == findValue){
			return i;
		}
	}
	
	return -1;
}

int binarySearch (int arr[], int sz){
	int findValue;
	printf("\ntim kiem nhi phan : ");
	scanf("%d",&findValue);
	
	int left = 0;
	int right = sz-1;
	
	while (left <= right){
		int mid = left + (right - left);
		
		if(arr[mid] == findValue){
			return mid;
		}else if(arr[mid] > findValue){
			right = mid-1;
		}else{
			left = mid + 1;
		}
	}
	return -1;
}
