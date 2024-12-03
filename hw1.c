#include<stdio.h>
void printArr (int arr[],int size){
	for(int i = 0; i<size;i++){
		printf("%d \t",arr[i]);
	}
}
int findMax (int arr[],int size){
	int max = 0;
	for(int i = 0; i<size;i++){
		if(max < arr[i]){
			max = arr[i];
		}
	}
	return max;
}
int main (){

	int n;
	printf("nhap do dai cua mang:\n");
	scanf("%d",&n);
	if(0<n<=100){
		//nhap vao mang so nguyen
		int arr[n];
		int size = sizeof(arr) / sizeof(arr[0]);
		for(int i = 0; i<n;i++){
			printf("pt%d: ", i ); 
			scanf("%d",&arr[i]);
		}
		
		// tim gia tri lon nhat
		int max = findMax(arr,size);
		printf("max = %d", max);
		
	}else{
		printf("n sai");
	}


	
	return 0;
}
