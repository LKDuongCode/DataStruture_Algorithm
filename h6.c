#include<stdio.h>
void printArr(int arr[], int n){
	for(int i = 0; i<n; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int main(){
	int arr[] = {64, 34, 25, 12, 22, 11, 90};
	int n = sizeof(arr)/sizeof(int);
	printArr(arr,n);
	
	int count = 0;
	int flag;
	for(int  i = 0; i<n-1; i++){
		flag = 0;
		for(int j = i +1; j <n; j++){
			if(arr[i] > arr[j]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				
				flag = 1;
			}
		}
		count++;
		printf("\n sap xep lan %d: ", count);
		printArr(arr,n);
		if(flag == 0){
			break;
		}
	}
	printf("\n hoan thanh sap xep voi %d vong lap \n ", count);
	
	printArr(arr,n);
	
	
	
	
	return 0;
}



