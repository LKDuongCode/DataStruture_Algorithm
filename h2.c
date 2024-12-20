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
	
	printf("before: ");
	for(int i = 0; i<n; i++){
		printf("%d ",arr[i]);
	}
	
	for(int i = 0; i< n-1; i++){
		for(int j= i+1; j<n; j++){
			if(arr[i] > arr[j]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
	printf("\n after: ");
	for(int i = 0; i<n; i++){
		printf("%d ",arr[i]);
	}
	return 0;
}



