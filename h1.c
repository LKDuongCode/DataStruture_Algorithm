#include<stdio.h>

int main(){
	int n;
	printf("nhap n ");
	scanf("%d",&n);
	int arr[n];
	for(int i = 0; i< n; i++){
		printf("arr[%d] = ",i);
		scanf("%d",&arr[i]);
	}
	
	//sap xep noi bot so sanh tung cap phan tu lap lai cho den khi tat car dc sap xep
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - i -1; j++){
			if(arr[j] > arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	
	for(int i = 0; i<n; i++){
		printf("%d ",arr[i]);
	}
	return 0;
}



