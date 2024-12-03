#include<stdio.h>
void countAppearances (int arr[],int size,int x,int *count);
int main (){
	int n;
	printf("nhap do dai cua mang:");
	scanf("%d",&n);
	if(0<n<=100){
		//nhap vao mang so nguyen
		int arr[n];
		int size = sizeof(arr) / sizeof(arr[0]);
		for(int i = 0; i<n;i++){
			printf("pt%d: ", i ); 
			scanf("%d",&arr[i]);
		}
		int x = 0;
		int count  = 0;
		printf("nhap so can dem: ");
		scanf("%d",&x);
		//dem so lan xuat hien
		countAppearances(arr,size,x,&count);
			printf("%d",count);
			
	}else{
		printf("n sai");
	}
	return 0;
}


void countAppearances (int arr[],int size,int x,int *count){
	for(int i = 0; i<size;i++){
		if(x == arr[i]){
			(*count)++;
		}
	}

}

