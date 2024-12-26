#include<stdio.h>
int binarySearch (int arr[], int sz);
int main(){
	int arr[] = {4,2,6,1};
	int sz = sizeof(arr)/sizeof(int);
	
	int indexFound = binarySearch(arr,sz);
	printf("%d",indexFound);
	
	return 0;
}


int binarySearch (int arr[], int sz){
	int findValue;
	printf("nhap gia tri can tim: ");
	scanf("%d",&findValue);
	
	//b1 xac dinh hai dau
	int left = 0;
	int right = sz-1;
	while (left <= right){
		//b2 xac dinh mid
		int mid = left + (right - left); // tranh tran doi voi so qua lon
		
		
		//b3 them dieu kien
		if(arr[mid] == findValue){
			return mid;
		}else if(arr[mid] > findValue){ // tim kiem nua ben trai
			right =  mid - 1;
		}else { // tim kiem nua ben phai
			left =  mid + 1;
		}
	}
	
	return -1; // khong tim thay
}


