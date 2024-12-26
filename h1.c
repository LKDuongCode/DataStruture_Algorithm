#include<stdio.h>

int linearSearch (int arr[], int sz);

int main(){
	int arr[] = {4,2,6,1};
	int sz = sizeof(arr)/sizeof(int);
	
	int indexFound = linearSearch(arr,sz);
	
	printf("%d", indexFound);
	return 0;
}

int linearSearch (int arr[], int sz){
	int findValue;
	printf("nhap gia tri can tim: ");
	scanf("%d",&findValue);
	
	for(int i = 0; i<sz; i++){
		if(arr[i] == findValue){
			return i;
		}
	}
	
	return -1;
}

