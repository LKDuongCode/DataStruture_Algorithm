#include<stdio.h>
int findMin (int arr[], int size);
int main(){
	int n;
	printf("nhap kich thuoc mang so nguyen ");
	scanf("%d",&n);
	int arr[n];
	for(int i = 0; i<n; i++){
		printf("att[%d] = ",i);
		scanf("%d",&arr[i]);
	}
	
	int found = findMin(arr,n);
	if(found == 0){
		printf("khong co gia tri nho nhat");
	}else{
		printf("%d",found);
	}

	return 0;
}

int findMin (int arr[], int size){
	if(size == 0){
		return 0;
	}
	int min = arr[0];
	for(int i = 0; i< size; i++){
		if(min > arr[i]){
			min = arr[i];
		}
	}
	return min;
}


