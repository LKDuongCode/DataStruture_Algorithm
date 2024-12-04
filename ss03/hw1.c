#include<stdio.h>
int factorial (int n){
	if(n==0){
		return 1;
	}
	return n* factorial(n-1);
}
int main(){
	int n;
	printf("nhap n giai thua:");
	scanf("%d",&n);
	int result = factorial(n);
	printf("%d",result);
	return 0;
}

