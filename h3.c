#include<stdio.h>
void checkSymmetry (int arr[], int size);

int main(){
	int n;
	printf("nhap kich thuoc mang so nguyen ");
	scanf("%d",&n);
	int arr[n];
	for(int i = 0; i<n; i++){
		printf("att[%d] = ",i);
		scanf("%d",&arr[i]);
	}
	
	checkSymmetry(arr,n);

	return 0;
}


void checkSymmetry (int arr[], int size){
	//b1 tao bien dem de kiem tra
	int count = 0;
	for(int i = 0; i< (size/2); i++){
		//b2 tao bien chua phan tu dau va cuoi
		int	first = arr[i];
		int	last = arr[size - i - 1];
		if(first == last){
			printf("cap doi xung: (%d ; %d) \n", first, last);
			count ++;

		}

	}
	
	if(count == 0){
		printf("khong co phan tu doi xung!");
	}
}

