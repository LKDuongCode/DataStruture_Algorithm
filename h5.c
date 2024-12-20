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
	int count = 0;
	int flag; // bien kiem tra hoan doi
	
	printf("mang ban dau: ");
	printArr(arr,n);
	
	for(int i = 0; i< n-1; i++){
		flag = 0; //lam moi bien sau moi vong
		for(int j = 0; j< n-i-1; j++){
			if(arr[j] > arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				
				flag = 1; // co hoan doi
			}
		}
		count++;
		printf("\n sap xep lan %d: ", count);
		printArr(arr,n);
		//neu khong co hoan doi thi thoat lap
		if(flag == 0){
			break;
		}
	}
	printf("\n hoan thanh sap xep voi %d vong lap", count);
	
	printf("\n mang sau khi sap xep: ");
	printArr(arr,n);
	return 0;
}



