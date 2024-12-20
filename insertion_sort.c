#include<stdio.h>
// sap xem chen
int main(){
	int nums[] = {2,1,5};
	int n = sizeof(nums)/sizeof(int);
	//b1 duyet tu 1
	for(int i = 1; i<n; i++){
		//b2 dat key va j
		int key = nums[i];
		int j = i-1;
		//b3 duyet j>=0 va nums[j] > key
		while(j>= 0 && nums[j] > key ){
			nums[j+1] = nums[j];
			j--;
		}
		nums[j+1] = key; //b4 gan lai key
	}
	
	for(int i = 0; i<n; i++){
		printf("%d ",nums[i]);
	}
	
	

	return 0;
}



