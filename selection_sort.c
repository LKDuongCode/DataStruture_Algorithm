#include<stdio.h>

int main(){
	int arr[] = {2,10,5};
	int n = sizeof(arr)/sizeof(int);
	for(int i = 0; i<n-1; i++){
		for(int j = i + 1; j<n; j++){
			if(arr[i] > arr[j]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
	for(int i = 0; i<n; i++){
		printf("%d ",arr[i]);
	}
	return 0;
}



