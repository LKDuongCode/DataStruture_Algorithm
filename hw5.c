#include<stdio.h>
void printArray (int arr[],int size);
void createArray (int arr[],int *n);
void deleteAnElement(int arr[],int *size,int *k);

int main(){
	int size;
	int arr[size];
	//nhap mang so nguyen
	createArray(arr,&size);

	//xoa phan tu
	int k;
	printf("truoc khi xoa: \n");
	printArray(arr,size);
	deleteAnElement(arr,&size,&k);
	printf("sau khi xoa %d: \n",k);
	printArray(arr,size);
	
    return 0;;
}

void createArray (int arr[],int *n){
    printf("nhap do dai cua mang:");
    scanf("%d", n);
     if (0 < *n && *n <= 100) {
    	for(int i = 0; i < *n; i++) {
            printf("pt%d: ", i); 
            scanf("%d", &arr[i]);
        }     	
	 }else{
	 	printf("n khong hop le.");
	 }
}

void deleteAnElement(int arr[],int *size,int *k){
	printf("nhap phan tu muon xoa:");
    scanf("%d",k);
	int deletedIndex = -1;
	// tim kiem phan tu
	for(int i = 0; i<*size;i++){
		if(arr[i] == *k){
			deletedIndex = i;
			break;
		}
	}
	if(!deletedIndex){
		printf("khong tim thay phan tu %d", *k);
		return;
	}
	
	//neu thay
	for(int i = deletedIndex; i< *size;i++){
		arr[i] = arr[i+1];
	}
	(*size)--;
}
void printArray (int arr[],int size){
	 for(int i = 0; i<size;i++){
		printf("%d \t",arr[i]);
	 }
	 printf("\n");
}


